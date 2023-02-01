//
// Created by Lloyd Brown on 9/24/19.
//

#include "waffle_proxy.h"

void waffle_proxy::init(const std::vector<std::string> &keys, void ** args){
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
    bst = FrequencySmoother();
    cache = Cache();
    id_to_client_ = *(static_cast<std::shared_ptr<thrift_response_client_map>*>(args[0]));
    //int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    int num_cores = 1;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_cores; i++) {
        auto q = std::make_shared<queue<std::pair<operation, std::shared_ptr<std::promise<std::string>>>>>();
        operation_queues_.push_back(q);
    }
    for (int i = 0; i < num_cores; i++) {
        threads_.push_back(std::thread(&waffle_proxy::consumer_thread, this, i));
    }
    threads_.push_back(std::thread(&waffle_proxy::responder_thread, this));
    std::cout << "Initializing waffle with keys size " << keys.size() << std::endl;
    for(auto& it : keys) {
        bst.insert(it);
    }

}

void waffle_proxy::create_security_batch(std::shared_ptr<queue <std::pair<operation, std::shared_ptr<std::promise<std::string>>>>> &op_queue,
                                          std::vector<operation> &storage_batch, std::vector<bool> &is_trues,
                                          std::vector<std::shared_ptr<std::promise<std::string>>> &promises) {
// Can optimize this code. TODO(sharathvemula)
    for (int i = 0; i < security_batch_size_; i++) {
        // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
        auto coin_toss = rand()%2;
        // coin_toss = 1 means serving real request
        if(coin_toss == 1) {
            // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
            if (op_queue->size() == 0) {
                struct operation operat;
                operat.key = bst.getKeyWithMinFrequency();
                bst.incrementFrequency(operat.key);
                if(bst.getFrequency(operat.key) > freqMax) {
                    freqMax = bst.getFrequency(operat.key);
                    cache.evictCache();
                }
                operat.value = "";
                storage_batch.push_back(operat);
                is_trues.push_back(false);
            } else {
                // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
                struct operation operat;
                auto operation_promise_pair = op_queue->pop();
                auto currentKey = operation_promise_pair.first.key;
                if(operation_promise_pair.first.value != "") {
                    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
                    if(cache.checkIfKeyExists(currentKey) == true) {
                        cache.markKeyDirty(currentKey);
                        operat.key = bst.getKeyWithMinFrequency();
                        bst.incrementFrequency(operat.key);
                        if(bst.getFrequency(operat.key) > freqMax) {
                            freqMax = bst.getFrequency(operat.key);
                            cache.evictCache();
                        }
                        operat.value = "";
                        storage_batch.push_back(operat);
                        is_trues.push_back(false);
                        operation_promise_pair.second->set_value(cache.getValue(currentKey));
                    } else {
                        // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
                        if(bst.getFrequency(currentKey) > freqMax) {
                            freqMax = bst.getFrequency(currentKey);
                            cache.evictCache();
                        }
                        storage_batch.push_back(operation_promise_pair.first);
                        is_trues.push_back(true);
                        promises.push_back(operation_promise_pair.second);
                    }
                } else {
                    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
                    if(cache.checkIfKeyExists(currentKey) == true) {
                        operat.key = bst.getKeyWithMinFrequency();
                        bst.incrementFrequency(operat.key);
                        if(bst.getFrequency(operat.key) > freqMax) {
                            freqMax = bst.getFrequency(operat.key);
                            cache.evictCache();
                        }
                        operat.value = "";
                        storage_batch.push_back(operat);
                        is_trues.push_back(false);
                        operation_promise_pair.second->set_value(cache.getValue(currentKey));
                    } else {
                        if(bst.getFrequency(currentKey) > freqMax) {
                            freqMax = bst.getFrequency(currentKey);
                            cache.evictCache();
                        }
                        storage_batch.push_back(operation_promise_pair.first);
                        is_trues.push_back(true);
                        promises.push_back(operation_promise_pair.second);
                    }
                }
            }
        } else {
            struct operation operat;
            operat.key = bst.getKeyWithMinFrequency();
            bst.incrementFrequency(operat.key);
            if(bst.getFrequency(operat.key) > freqMax) {
                freqMax = bst.getFrequency(operat.key);
                cache.evictCache();
            }
            operat.value = "";
            storage_batch.push_back(operat);
            is_trues.push_back(false);
        }
    }
};

void waffle_proxy::execute_batch(const std::vector<operation> &operations, std::vector<bool> &is_trues,
                                  std::vector<std::shared_ptr<std::promise<std::string>>> &promises, std::shared_ptr<storage_interface> storage_interface) {
    //std::cout << "Executing batch " << std::endl;
    std::vector<std::string> storage_keys;
    for(int i = 0; i < operations.size(); i++){
        std::string key = operations[i].key;
        storage_keys.push_back(key);
    }
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
    auto responses = storage_interface->get_batch(storage_keys);
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
    std::vector<std::string> storage_values;
    for(int i = 0, j = 0; i < operations.size(); i++){
        if(cache.checkIfKeyExists(operations[i].key)) {
            cache.unMarkKeyDirty(operations[i].key);
            storage_values.push_back(cache.getValue(operations[i].key));
        } else {
            storage_values.push_back(responses[i]);
        }
        if (is_trues[i] == true) {
            promises[j]->set_value(storage_values[i]);
            j++;
            if(bst.getFrequency(operations[i].key) == freqMax && cache.checkIfKeyExists(operations[i].key)==false) {
                cache.insertIntoCache(operations[i].key, "", false);
            }
        }
    }
    //std::cout << "Executed batch " << std::endl;
}

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
    std::cout << "Pushing client ID async_get is " << seq_id.client_id << std::endl;
    respond_queue_.push(std::make_pair(GET, std::make_pair(seq_id, std::move(waiters))));
};

void waffle_proxy::put(int queue_id, const std::string &key, const std::string &value) {
    put_future(queue_id, key, value).get();
};

void waffle_proxy::async_put(const sequence_id &seq_id, int queue_id, const std::string &key, const std::string &value) {
    // Send to responder thread
    std::vector<std::future<std::string>> waiters;
    waiters.push_back(put_future(queue_id, key, value));
    std::cout << "Pushing client ID async_put is " << seq_id.client_id << std::endl;
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
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
    for (const auto &key: keys) {
        waiters.push_back((get_future(queue_id, key)));
    }
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
    std::cout << "Pushing client ID async_get_batch is " << seq_id.client_id << std::endl;
    respond_queue_.push(std::make_pair(GET_BATCH, std::make_pair(seq_id, std::move(waiters))));
    sequence_queue_.push(seq_id);
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
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
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
    int i = 0;
    for (const auto &key: keys) {
        waiters.push_back((put_future(queue_id, key, values[i])));
        i++;
    }
    // for (int i = 0; i < waiters.size(); i++){
    //     waiters[i].get();
    // }
    std::cout << "Pushing client ID async_put_batch is " << seq_id.client_id << std::endl;
    respond_queue_.push(std::make_pair(PUT_BATCH, std::make_pair(seq_id, std::move(waiters))));
    sequence_queue_.push(seq_id);
};

std::future<std::string> waffle_proxy::get_future(int queue_id, const std::string &key) {
    // if (key_to_frequency_.find(key) == key_to_frequency_.end()){
    //     throw std::logic_error("Key does not exist");
    // }
    auto prom = std::make_shared<std::promise<std::string>>();
    std::future<std::string> waiter = prom->get_future();
    struct operation operat;
    operat.key = key;
    operat.value = "";
    operation_queues_[queue_id % operation_queues_.size()]->push(std::make_pair(operat, prom));
    // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
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

void waffle_proxy::consumer_thread(int id){
    std::shared_ptr<storage_interface> storage_interface;
    if (server_type_ == "redis") {
        std::cout << "Storage interface is starting with Redis DB " << std::endl;
        storage_interface = std::make_shared<redis>(server_host_name_, server_port_);
        cpp_redis::network::set_default_nb_workers(std::min(10, p_threads_));
        std::cout << "Storage interface is initialized with Redis DB " << std::endl;
    }

    // if (server_type_ == "rocksdb") {
    //     storage_interface = std::make_shared<rocksdb>(server_host_name_, server_port_);
    // }
    //else if (server_type_ == "memcached")
    //    storage_interface_ new memcached(server_host_name_, server_port_+i);
    for (int i = 1; i < server_count_; i++) {
        storage_interface->add_server(server_host_name_, server_port_+i);
    }
    int operations_serviced = 0;
    int previous_total_operations = 0;
    int total_operations = 0;
    std::cout << "Entering here to consumer thread" << std::endl;
    while (!finished_) {
        // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
        while (1 && !finished_) {
            total_operations = operation_queues_[id]->size(); // + operations_serviced;
            int i = 0;
            // // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << "Total operations are " << total_operations  << std::endl;
            // // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << "Prev Total operations are " << previous_total_operations  << std::endl;
            for (; i < total_operations; i++) {
                // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << "Total operations are " << total_operations  << std::endl;
                // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << "Prev Total operations are " << previous_total_operations  << std::endl;
                std::vector <operation> storage_batch;
                std::vector<std::shared_ptr<std::promise<std::string>>> promises;
                std::vector<bool> is_trues;
                // std::cout << "Entering waffle_proxy.cpp line " << __LINE__ << std::endl;
                create_security_batch(operation_queues_[id], storage_batch, is_trues, promises);
                execute_batch(storage_batch, is_trues, promises, storage_interface);
            }
            if (i != 0) {
                //operations_serviced += i;
                previous_total_operations = total_operations;
            }
        }
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
        std::cout << "Responder thread client ID is " << seq.client_id << std::endl;
        id_to_client_->async_respond_client(seq, op_code, results);
    }
    std::cout << "Quitting response thread" << std::endl;
}

void waffle_proxy::flush() {
    // for (auto operation_queue : operation_queues_){
    //     if (operation_queue->size() != 0) {
    //         auto operation_promise_pair = operation_queue->pop();
    //         auto read_result = storage_interface_->get(operation_promise_pair.first.key);
    //         storage_interface_->put(operation_promise_pair.first.key, read_result);
    //         operation_promise_pair.second->set_value(read_result);
    //     }
    // }
    std::cout << "Flushing proxy " << std::endl;
}

void waffle_proxy::close() {
    finished_ = true;
    for (int i = 0; i < threads_.size(); i++)
        threads_[i].join();
}

