//
// Created by Lloyd Brown on 10/1/19.
//

#ifndef WAFFLE_ASYNC_PROXY_CLIENT_H
#define WAFFLE_ASYNC_PROXY_CLIENT_H

#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransportUtils.h>
#include <string>
#include <vector>
#include <atomic>
#include <thread>
#include <iostream>

#include "client.h"
#include "waffle_thrift.h"
#include "waffle_thrift_response.h"
#include "queue.h"
#include "command_response_reader.h"

#define GET 0
#define PUT 1
#define GET_BATCH 2
#define PUT_BATCH 3

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

class async_proxy_client : client {

public:

    void init(const std::string &host_name, int port);
    int64_t get_client_id();
    command_response_reader get_command_response_reader(int64_t client_id);
    std::string get(const std::string &key) override;
    void put(const std::string &key, const std::string &value) override;
    std::vector<std::string> get_batch(const std::vector<std::string> &keys) override;
    void put_batch(const std::vector<std::string> &keys, const std::vector<std::string> &values) override;
    int num_requests_satisfied();
    void read_responses();
    void finish();


private:
    std::shared_ptr<waffle_thriftClient> client_;

    std::shared_ptr<queue<int>> requests_;
    std::atomic_int* total_;
    std::atomic_bool* done_;
    
    std::condition_variable *m_cond_;
    std::mutex *m_mtx_;


    int64_t sequence_num = 0;
    int64_t client_id_;
    sequence_id seq_id_;
    std::thread *response_thread_;

    int in_flight_limit_ = 16;

    command_response_reader reader_;

    /* Transport */
    std::shared_ptr<apache::thrift::transport::TTransport> transport_{};
    /* Protocol */
    std::shared_ptr<apache::thrift::protocol::TProtocol> protocol_{};
};


#endif //WAFFLE_PROXY_CLIENT_H
