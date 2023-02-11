//
// Created by Lloyd Brown on 9/24/19.
//

#include "waffle_proxy.h"

std::string extractKey(std::string encryptedKey) {
    for(int i=encryptedKey.size()-1; i>=0; --i) {
        if(encryptedKey[i] == '#') {
            return encryptedKey.substr(0, i);
        }
    }
    return "";
}

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

void waffle_proxy::init(const std::vector<std::string> &keys, const std::vector<std::string> &values, void ** args){
    std::unordered_set<std::string> allKeys;
    std::unordered_set<std::string> tempFakeKeys;
    realBst = FrequencySmoother();
    fakeBst = FrequencySmoother();
    std::vector<std::string> keysCache;
    std::vector<std::string> keysCacheUnencrypted;

    if (server_type_ == "redis") {
        std::cout << "Storage interface is starting with Redis DB " << std::endl;
        storage_interface_ = std::make_shared<redis>(server_host_name_, server_port_);
        cpp_redis::network::set_default_nb_workers(std::min(10, p_threads_));
        std::cout << "Storage interface is initialized with Redis DB " << std::endl;
    }

    // if (server_type_ == "rocksdb") {
    //     storage_interface = std::make_shared<rocksdb>(server_host_name_, server_port_);
    // }
    //else if (server_type_ == "memcached")
    //    storage_interface_ new memcached(server_host_name_, server_port_+i);
    for (int i = 1; i < server_count_; i++) {
        storage_interface_->add_server(server_host_name_, server_port_+i);
    }

    id_to_client_ = *(static_cast<std::shared_ptr<thrift_response_client_map>*>(args[0]));
    //int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    int num_cores = 1;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_cores; i++) {
        auto q = std::make_shared<queue<std::pair<operation, std::shared_ptr<std::promise<std::string>>>>>();
        operation_queues_.push_back(q);
    }
    for (int i = 0; i < num_cores; i++) {
        threads_.push_back(std::thread(&waffle_proxy::consumer_thread, this, i, new encryption_engine(encryption_engine_)));
    }
    threads_.push_back(std::thread(&waffle_proxy::responder_thread, this));
    
    //Adding the data to Database
    std::cout << "Keys size in init() is " << keys.size() << std::endl;
    std::unordered_map<std::string, std::string> keyValueMap;
    for(int i=0;i<keys.size();++i) {
        keyValueMap[keys[i]] = values[i];
        // allKeys.insert(keys[i]);
        realBst.insert(keys[i]);
        // storage_interface_->put(encryption_engine_.encrypt(keys[i] + "#" + std::to_string(realBst.getFrequency(keys[i]))), encryption_engine_.encrypt(values[i]));
    }


    // Initialising Cache
    size_t cacheCapacity = R+s;
    std::unordered_set<std::string> temp;
    std::vector<std::string> valuesCache;
    while(keysCacheUnencrypted.size() < cacheCapacity) {
        auto index = rand()%(keys.size());
        if(temp.find(keys[index]) == temp.end()) {
            temp.insert(keys[index]);
            keysCacheUnencrypted.push_back(keys[index]);
            //keysCache.push_back(encryption_engine_.encrypt(keys[index] + "#" + std::to_string(realBst.getFrequency(keys[index]))));
            // keysCache.push_back(keys[index]);
            valuesCache.push_back(values[index]);
            keyValueMap.erase(keys[index]);
        }
    }
    //auto valuesCache = storage_interface_->get_batch(keysCache);
    // for(int i=0;i<valuesCache.size(); ++i) {
    //     valuesCache[i] = encryption_engine_.decrypt(valuesCache[i]);
    // }
    cache = Cache(keysCacheUnencrypted, valuesCache, cacheCapacity+R);
    


    std::vector<std::string> fakeValues;
    std::vector<std::string> fakeKeys;
    for(int i=0; i < m; ) {
        auto fakeKey = gen_random(rand()%15);
        if(allKeys.find(fakeKey) == allKeys.end() && tempFakeKeys.find(fakeKey)==tempFakeKeys.end()) {
            ++i;
            fakeBst.insert(fakeKey);
            tempFakeKeys.insert(fakeKey);
            auto tempFakeKey = encryption_engine_.encrypt(fakeKey + '#' + std::to_string(fakeBst.getFrequency(fakeKey)));
            auto fakeKeyValue = encryption_engine_.encrypt(gen_random(rand()%15));
            fakeKeys.push_back(tempFakeKey);
            fakeValues.push_back(fakeKeyValue);
        }
    }

    for(auto& it: keyValueMap) {
        storage_interface_->put(encryption_engine_.encrypt(it.first + "#" + std::to_string(realBst.getFrequency(it.first))), encryption_engine_.encrypt(it.second));
    }
    storage_interface_->put_batch(fakeKeys, fakeValues);
    threads_.push_back(std::thread(&waffle_proxy::clearThread, this));
    std::cout << "Successfully initialized waffle with keys size " << keys.size() << " and cache with " << cache.size() << " Fake keys size is " << m << " D is " << D << " R is" << R << " s is "  << s << " FakeBST size is " << fakeBst.size() << std::endl;
}

void waffle_proxy::create_security_batch(std::shared_ptr<queue <std::pair<operation, std::shared_ptr<std::promise<std::string>>>>> &op_queue,
                                          std::vector<operation> &storage_batch,
                                          std::unordered_map<std::string, std::vector<std::shared_ptr<std::promise<std::string>>>> &keyToPromiseMap) {

    if (op_queue->size() == 0) {
        std::cout << "WARNING: You should never see this line on console! Queue size is 0" << std::endl;
    } else {
        struct operation operat;
        auto operation_promise_pair = op_queue->pop();
        auto currentKey = operation_promise_pair.first.key;
        if(operation_promise_pair.first.value == "") {
            // It's a GET request
            if(cache.checkIfKeyExists(currentKey) == true) {
                operation_promise_pair.second->set_value(cache.getValueWithoutPositionChange(currentKey));
            } else {
                if(keyToPromiseMap.find(currentKey) == keyToPromiseMap.end()) {
                    storage_batch.push_back(operation_promise_pair.first);
                }
                keyToPromiseMap[currentKey].push_back(operation_promise_pair.second);
            }
        } else {
            // It's a PUT request
            if(cache.checkIfKeyExists(currentKey) == false) {
                if(keyToPromiseMap.find(currentKey) == keyToPromiseMap.end()) {
                    storage_batch.push_back(operation_promise_pair.first);
                }
            }
            cache.insertIntoCache(currentKey, operation_promise_pair.first.value);
            operation_promise_pair.second->set_value(cache.getValueWithoutPositionChange(currentKey));
        }
    }
};

void waffle_proxy::execute_batch(const std::vector<operation> &operations, std::unordered_map<std::string, std::vector<std::shared_ptr<std::promise<std::string>>>> &keyToPromiseMap, std::shared_ptr<storage_interface> storage_interface, encryption_engine *enc_engine) {
    // std::cout << "Storage batch size is " << operations.size() << " and R is " << R << std::endl; // Both need not be the same
    // Storage_keys is same as readBatch
    std::vector<std::string> storage_keys;
    std::vector<std::string> writeBatchKeys;
    std::vector<std::string> writeBatchValues;

    for(int i = 0; i < operations.size(); i++){
        std::string key = operations[i].key;
        storage_keys.push_back(enc_engine->encrypt(key + "#" + std::to_string(realBst.getFrequency(key))));
        realBst.incrementFrequency(key);
    }

    std::vector<std::string> realKeysNotInCache;
    auto it = realBst.getIterator();
    for(int i=0;i<s;) {
        if(cache.checkIfKeyExists(it->first) == false) {
            realKeysNotInCache.push_back(it->first);
            ++i;
        }
        ++it;
    }

    // std::cout << "realKeysNotInCache size is " << realKeysNotInCache.size() << std::endl;

    for(auto& iter: realKeysNotInCache) {
        storage_keys.push_back(enc_engine->encrypt(iter + "#" + std::to_string(realBst.getFrequency(iter))));
        realBst.incrementFrequency(iter);
    }

    for(int i=0;i<(D-operations.size());++i) {
        auto fakeMinKey = fakeBst.getKeyWithMinFrequency();
        storage_keys.push_back(enc_engine->encrypt(fakeMinKey + "#" + std::to_string(fakeBst.getFrequency(fakeMinKey))));
        fakeBst.incrementFrequency(fakeMinKey);
    }

    auto responses = storage_interface->get_batch(storage_keys);
    // std::cout << "Got key value pairs" << std::endl;
    for(int i = 0 ; i < storage_keys.size(); i++){
        if(i < (operations.size() + realKeysNotInCache.size())) {
            // This means ith request is for real key
            auto kv_pair = cache.evictLRElementFromCache();
            writeBatchKeys.push_back(enc_engine->encrypt(kv_pair[0] + "#" + std::to_string(realBst.getFrequency(kv_pair[0]))));
            writeBatchValues.push_back(enc_engine->encrypt(kv_pair[1]));

            auto keyAboutToGoToCache = extractKey(enc_engine->decrypt(storage_keys[i]));
            // std::cout << "Extracted key which is about to go to Cache is " << keyAboutToGoToCache << std::endl;
            std::string valueAboutToGoToCache = enc_engine->decrypt(responses[i]);
            if(keyToPromiseMap.find(keyAboutToGoToCache) != keyToPromiseMap.end()) {
                for(auto& it: keyToPromiseMap[keyAboutToGoToCache]) {
                    it->set_value(valueAboutToGoToCache);
                }
            }
            if(cache.checkIfKeyExists(keyAboutToGoToCache) == true) {
                valueAboutToGoToCache = cache.getValueWithoutPositionChange(keyAboutToGoToCache);
            }
            cache.insertIntoCache(keyAboutToGoToCache, valueAboutToGoToCache);
        } else {
            // Writing fake key values to DB
            auto fakeWriteKey = extractKey(enc_engine->decrypt(storage_keys[i]));
            writeBatchKeys.push_back(enc_engine->encrypt(fakeWriteKey + "#" + std::to_string(fakeBst.getFrequency(fakeWriteKey))));
            writeBatchValues.push_back(enc_engine->encrypt("fakeValue"));

        }
    }
    storage_interface_->put_batch(writeBatchKeys, writeBatchValues);
    keysNotUsed.push(storage_keys);

    if(cache.size() != (R+s)) {
        std::cout << "WARNING: This should never happen: Cache size is less than R+s" << std::endl;
    }
};

std::string waffle_proxy::get(const std::string &key) {
    return get(rand_uint32(0, RAND_MAX), key);
};

void waffle_proxy::async_get(const sequence_id &seq_id, const std::string &key) {
    async_get(seq_id, rand_uint32(0, RAND_MAX), key);
};

void waffle_proxy::put(const std::string &key, const std::string &value) {
    return put(rand_uint32(0, RAND_MAX), key, value);
};

void waffle_proxy::async_put(const sequence_id &seq_id, const std::string &key, const std::string &value) {
    async_put(seq_id, rand_uint32(0, RAND_MAX), key, value);
};

std::vector<std::string> waffle_proxy::get_batch(const std::vector<std::string> &keys) {
    return get_batch(rand_uint32(0, RAND_MAX), keys);
};

void waffle_proxy::async_get_batch(const sequence_id &seq_id, const std::vector<std::string> &keys) {
    async_get_batch(seq_id, rand_uint32(0, RAND_MAX), keys);
};

void waffle_proxy::put_batch(const std::vector<std::string> &keys, const std::vector<std::string> &values) {
    return put_batch(rand_uint32(0, RAND_MAX), keys, values);
};

void waffle_proxy::async_put_batch(const sequence_id &seq_id, const std::vector<std::string> &keys, const std::vector<std::string> &values) {
    async_put_batch(seq_id, rand_uint32(0, RAND_MAX), keys, values);
};

std::string waffle_proxy::get(int queue_id, const std::string &key) {
    return get_future(queue_id, key).get();
};

void waffle_proxy::async_get(const sequence_id &seq_id, int queue_id, const std::string &key) {
    // Send to responder thread
    std::vector<std::future<std::string>> waiters;
    waiters.push_back(get_future(queue_id, key));

    respond_queue_.push(std::make_pair(GET, std::make_pair(seq_id, std::move(waiters))));
};

void waffle_proxy::put(int queue_id, const std::string &key, const std::string &value) {
    put_future(queue_id, key, value).get();
};

void waffle_proxy::async_put(const sequence_id &seq_id, int queue_id, const std::string &key, const std::string &value) {
    // Send to responder thread
    std::vector<std::future<std::string>> waiters;
    waiters.push_back(put_future(queue_id, key, value));

    respond_queue_.push(std::make_pair(GET, std::make_pair(seq_id, std::move(waiters))));
};

std::vector<std::string> waffle_proxy::get_batch(int queue_id, const std::vector<std::string> &keys) {
    std::vector<std::string> _return;
    std::vector<std::future<std::string>> waiters;
    for (const auto &key: keys) {
        waiters.push_back((get_future(queue_id, key)));
    }
    for (int i = 0; i < waiters.size(); i++){
        _return.push_back(waiters[i].get());
    }
    return _return;
};

void waffle_proxy::async_get_batch(const sequence_id &seq_id, int queue_id, const std::vector<std::string> &keys) {
    std::vector<std::string> _return;
    std::vector<std::future<std::string>> waiters;
    for (const auto &key: keys) {
        waiters.push_back((get_future(queue_id, key)));
    }
    // std::cout << "async_get_batch client ID is " << seq_id.client_id << std::endl;
    respond_queue_.push(std::make_pair(GET_BATCH, std::make_pair(seq_id, std::move(waiters))));
    sequence_queue_.push(seq_id);
};

void waffle_proxy::put_batch(int queue_id, const std::vector<std::string> &keys, const std::vector<std::string> &values) {
    // Send waiters to responder thread
    std::vector<std::future<std::string>> waiters;
    int i = 0;
    for (const auto &key: keys) {
        waiters.push_back((put_future(queue_id, key, values[i])));
        i++;
    }
    for (int i = 0; i < waiters.size(); i++){
        waiters[i].get();
    }
};

void waffle_proxy::async_put_batch(const sequence_id &seq_id, int queue_id, const std::vector<std::string> &keys, const std::vector<std::string> &values) {
    // Send waiters to responder thread
    std::vector<std::future<std::string>> waiters;
    // std::cout << "async_put_batch client ID is " << seq_id.client_id << std::endl;
    int i = 0;
    for (const auto &key: keys) {
        waiters.push_back((put_future(queue_id, key, values[i])));
        i++;
    }

    respond_queue_.push(std::make_pair(PUT_BATCH, std::make_pair(seq_id, std::move(waiters))));
    sequence_queue_.push(seq_id);
};

std::future<std::string> waffle_proxy::get_future(int queue_id, const std::string &key) {
    auto prom = std::make_shared<std::promise<std::string>>();
    std::future<std::string> waiter = prom->get_future();
    struct operation operat;
    operat.key = key;
    operat.value = "";
    operation_queues_[queue_id % operation_queues_.size()]->push(std::make_pair(operat, prom));
    return waiter;
};

std::future<std::string> waffle_proxy::put_future(int queue_id, const std::string &key, const std::string &value) {
    auto prom = std::make_shared<std::promise<std::string>>();
    std::future<std::string> waiter = prom->get_future();
    struct operation operat;
    operat.key = key;
    operat.value = value;
    operation_queues_[queue_id % operation_queues_.size()]->push(std::make_pair(operat, prom));
    return waiter;
};

void waffle_proxy::consumer_thread(int id, encryption_engine *enc_engine){
    int operations_serviced = 0;
    int previous_total_operations = 0;
    int total_operations = 0;
    std::cout << "Entering here to consumer thread" << std::endl;
    while (!finished_) {
        std::vector <operation> storage_batch;
        std::unordered_map<std::string, std::vector<std::shared_ptr<std::promise<std::string>>>> keyToPromiseMap;
        //std::unordered_set<std::string> tempSet;
        int i=0;
        while (i < R && !finished_) {
            if(operation_queues_[id]->size() > 0) {
                create_security_batch(operation_queues_[id], storage_batch, keyToPromiseMap);
                ++i;
            }
        }
        execute_batch(storage_batch, keyToPromiseMap, storage_interface_, enc_engine);
    }

};

void waffle_proxy::responder_thread(){
    while (true){
        auto tuple = respond_queue_.pop();
        auto op_code = tuple.first;
        auto seq = tuple.second.first;
        seq = sequence_queue_.pop();
        std::vector<std::string>results;
        for (int i = 0; i < tuple.second.second.size(); i++) {
            results.push_back(tuple.second.second[i].get());
        }
        id_to_client_->async_respond_client(seq, op_code, results);
    }
    std::cout << "Quitting response thread" << std::endl;
};

void waffle_proxy::clearThread(){
    while(true) {
        auto keyVectorNotUsed = keysNotUsed.pop();
        if(keyVectorNotUsed.size() > 0)
            storage_interface_->delete_batch(keyVectorNotUsed);
    }
}

void waffle_proxy::flush() {
    std::cout << "Flushing proxy " << std::endl;
};

void waffle_proxy::close() {
    finished_ = true;
    for (int i = 0; i < threads_.size(); i++)
        threads_[i].join();
};

