//
// Created by Lloyd Brown on 8/29/19.
//

#ifndef WAFFLE_PROXY_H
#define WAFFLE_PROXY_H

#include <unordered_map>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <algorithm>
#include <thread>
#include <future>
#include <random>

#include "proxy.h"
#include "util.h"
#include "operation.h"
#include "queue.h"
#include "thrift_response_client_map.h"
#include "FrequencySmoother.hpp"
#include "Cache.hpp"

#include "redis.h"
#include "storage_interface.h"
//#include "memcached.h"


class waffle_proxy : public proxy {
public:

    void init(const std::vector<std::string> &keys, void ** args) override;
    void close() override;
    std::string get(const std::string &key) override;
    void put(const std::string &key, const std::string &value) override;
    std::vector<std::string> get_batch(const std::vector<std::string> &keys) override;
    void put_batch(const std::vector<std::string> &keys, const std::vector<std::string> &values) override;

    std::string get(int queue_id, const std::string &key) override;
    void put(int queue_id, const std::string &key, const std::string &value) override;
    std::vector<std::string> get_batch(int queue_id, const std::vector<std::string> &keys) override;
    void put_batch(int queue_id, const std::vector<std::string> &keys, const std::vector<std::string> &values) override;

    void async_get(const sequence_id &seq_id, const std::string &key);
    void async_put(const sequence_id &seq_id, const std::string &key, const std::string &value);
    void async_get_batch(const sequence_id &seq_id, const std::vector<std::string> &keys);
    void async_put_batch(const sequence_id &seq_id, const std::vector<std::string> &keys, const std::vector<std::string> &values);

    void async_get(const sequence_id &seq_id, int queue_id, const std::string &key);
    void async_put(const sequence_id &seq_id, int queue_id, const std::string &key, const std::string &value);
    void async_get_batch(const sequence_id &seq_id, int queue_id, const std::vector<std::string> &keys);
    void async_put_batch(const sequence_id &seq_id, int queue_id, const std::vector<std::string> &keys, const std::vector<std::string> &values);

    std::future<std::string> get_future(int queue_id, const std::string &key);
    std::future<std::string> put_future(int queue_id, const std::string &key, const std::string &value);

    void flush();

    std::string output_location_ = "log";
    std::string trace_location_ = "";
    std::string server_host_name_ = "127.0.0.1";
    int server_port_ = 6379;
    int security_batch_size_ = 3;
    int object_size_ = 1024;
    int key_size_ = 16;
    int server_count_ = 1;
    std::string server_type_ = "redis";
    int p_threads_ = 1;
    int storage_batch_size_ = 5;
    int core_ = 0;
    bool is_static_ = true;

private:
    void create_security_batch(std::shared_ptr<queue <std::pair<operation, std::shared_ptr<std::promise<std::string>>>>> &op_queue,
                               std::vector<operation> &storage_batch, std::vector<bool> &is_trues,
                               std::vector<std::shared_ptr<std::promise<std::string>>> &promises);

    void execute_batch(const std::vector<operation> &operations, std::vector<bool> &is_trues,
                       std::vector<std::shared_ptr<std::promise<std::string>>> &promises, std::shared_ptr<storage_interface> storage_interface, encryption_engine *enc_engine);
    void consumer_thread(int id);
    void responder_thread();

    std::vector<std::shared_ptr<queue<std::pair<operation, std::shared_ptr<std::promise<std::string>>>>>> operation_queues_;
    std::vector<std::thread> threads_;
    bool finished_ = false;
    std::shared_ptr<thrift_response_client_map> id_to_client_;
    std::shared_ptr<storage_interface> storage_interface_; 

    int GET = 0;
    int PUT = 1;
    int GET_BATCH = 2;
    int PUT_BATCH = 3;
    int freqMax = 0;
    FrequencySmoother realBst;
    FrequencySmoother fakeBst;
    Cache cache;
    queue<std::pair<int, std::pair<const sequence_id&, std::vector<std::future<std::string>>>>> respond_queue_;
    queue<sequence_id> sequence_queue_;
    // System parameters
    int R = 10;
    int D = 11;
    int s = 20;
    int m = 1000;
};

#endif //WAFFLE_PROXY_H
