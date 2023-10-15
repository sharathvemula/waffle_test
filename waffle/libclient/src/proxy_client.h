//
// Created by Lloyd Brown on 10/1/19.
//

#ifndef WAFFLE_PROXY_CLIENT_H
#define WAFFLE_PROXY_CLIENT_H

#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransportUtils.h>
#include <string>
#include <vector>

#include "client.h"
#include "waffle_thrift.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

class proxy_client : client{

public:
    void init(const std::string &host_name, int port) override;
    std::string get(const std::string &key) override;
    void put(const std::string &key, const std::string &value) override;
    std::vector<std::string> get_batch(const std::vector<std::string> &keys) override;
    void put_batch(const std::vector<std::string> &keys, const std::vector<std::string> &values) override;


private:
    std::shared_ptr<waffle_thriftClient> client_;

};


#endif //waffle_PROXY_CLIENT_H
