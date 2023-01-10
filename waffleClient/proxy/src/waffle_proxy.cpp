//
// Created by Lloyd Brown on 9/24/19.
//

#include "waffle_proxy.h"

void waffle_proxy::init(const std::vector<std::string> &keys, const std::vector<std::string> &values, void ** args){
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
    //if (!is_static_)
    //    threads_.push_back(std::thread(&waffle_proxy::distribution_thread, this));
    threads_.push_back(std::thread(&waffle_proxy::responder_thread, this));
}

void waffle_proxy::create_security_batch(std::shared_ptr<queue <std::pair<operation, std::shared_ptr<std::promise<std::string>>>>> &op_queue,
                                          std::vector<operation> &storage_batch, std::vector<bool> &is_trues,
                                          std::vector<std::shared_ptr<std::promise<std::string>>> &promises) {
    for (int i = 0; i < security_batch_size_; i++) {
        // if (is_true_distribution()) {
        //     if (op_queue->size() == 0) {
        //         struct operation operat;
        //         operat.key = real_distribution_.sample();
        //         operat.value = "";
        //         storage_batch.push_back(operat);
        //         is_trues.push_back(false);
        //     } else {
        //         auto operation_promise_pair = op_queue->pop();
        //         storage_batch.push_back(operation_promise_pair.first);
        //         is_trues.push_back(true);
        //         promises.push_back(operation_promise_pair.second);
        //     }
        // } else {
        //     struct operation operat;
        //     operat.key = fake_distribution_.sample();
        //     operat.value = "";
        //     storage_batch.push_back(operat);
        //     is_trues.push_back(false);
        // }
        if (op_queue->size() == 0) {
            struct operation operat;
            operat.key = 1;
            operat.value = "test";
            storage_batch.push_back(operat);
            is_trues.push_back(true);
        } else {
            auto operation_promise_pair = op_queue->pop();
            storage_batch.push_back(operation_promise_pair.first);
            is_trues.push_back(true);
            promises.push_back(operation_promise_pair.second);
        }
    }
};

void waffle_proxy::execute_batch(const std::vector<operation> &operations, std::vector<bool> &is_trues,
                                  std::vector<std::shared_ptr<std::promise<std::string>>> &promises) {

    // Store which are real queries so we can return the values
    // std::vector<std::string> labels;

    // std::vector<std::string> storage_keys;
    // for(int i = 0; i < operations.size(); i++){
    //     std::string key = operations[i].key;
    //     replica_ids.push_back(missing_new_replicas_.sample_a_replica(key, key_to_number_of_replicas_[key], is_trues[i], key_to_frequency_[key], p_max_));
    //     labels.push_back(std::to_string(replica_to_label_[operations[i].key+std::to_string(replica_ids[i])]));
    //     storage_keys.push_back(labels[i]);
    // }
    // auto responses = storage_interface->get_batch(storage_keys);
    // std::vector<std::string> storage_values;
    // for(int i = 0, j = 0; i < operations.size(); i++){
    //     auto cipher = responses[i];
    //     auto plaintext = enc_engine->decrypt(cipher);
    //     if(operations[i].value != ""){
    //         update_cache_.populate_replica_updates(operations[i].key, operations[i].value, key_to_number_of_replicas_[operations[i].key]);
    //     }
    //     auto plaintext_update = update_cache_.check_for_update(operations[i].key, replica_ids[i]);
    //     plaintext = plaintext_update == "" ? plaintext : plaintext_update;
    //     missing_new_replicas_.check_if_missing(operations[i].key, plaintext, update_cache_);
    //     if (is_trues[i]) {
    //         promises[j]->set_value(plaintext);
    //         j++;
    //     }
    //     storage_values.push_back(enc_engine->encrypt(plaintext));
    // }
    // storage_interface->put_batch(storage_keys, storage_values);
    std::cout << "Executing batch " << std::endl;
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
    int i = 0;
    for (const auto &key: keys) {
        waiters.push_back((put_future(queue_id, key, values[i])));
        i++;
    }
    for (int i = 0; i < waiters.size(); i++){
        waiters[i].get();
    }
    respond_queue_.push(std::make_pair(PUT_BATCH, std::make_pair(seq_id, std::move(waiters))));
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
    // std::shared_ptr<storage_interface> storage_interface;
    // if (server_type_ == "redis") {
    //     storage_interface = std::make_shared<redis>(server_host_name_, server_port_);
    // }
    // else if (server_type_ == "rocksdb") {
    //     storage_interface = std::make_shared<rocksdb>(server_host_name_, server_port_);
    // }
    // //else if (server_type_ == "memcached")
    // //    storage_interface_ new memcached(server_host_name_, server_port_+i);
    // for (int i = 1; i < server_count_; i++) {
    //     storage_interface->add_server(server_host_name_, server_port_+i);
    // }
    int operations_serviced = 0;
    int previous_total_operations = 0;
    int total_operations = 0;
    std::cout << "Entering here to consumer thread" << std::endl;
    while (!finished_) {
        std::vector <operation> storage_batch;
        std::vector<std::shared_ptr<std::promise<std::string>>> promises;
        std::vector<bool> is_trues;
        while (storage_batch.size() < storage_batch_size_ && !finished_) {
            total_operations = operation_queues_[id]->size() + operations_serviced;
            int i = 0;
            for (; i < total_operations - previous_total_operations; i++)
                create_security_batch(operation_queues_[id], storage_batch, is_trues, promises);
            if (i != 0) {
                operations_serviced += i;
                previous_total_operations = total_operations;
            }
        }
        execute_batch(storage_batch, is_trues, promises);
    }

};

void waffle_proxy::responder_thread(){
    while (true){
        auto tuple = respond_queue_.pop();
        
        auto op_code = tuple.first;
        auto seq = tuple.second.first;
        seq = sequence_queue_.pop();
        std::vector<std::string>results;
        for (int i = 0; i < tuple.second.second.size(); i++)
            results.push_back(tuple.second.second[i].get());
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

