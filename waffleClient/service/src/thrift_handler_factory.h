//
// Created by Lloyd Brown on 10/5/19.
//

#ifndef WAFFLE_THRIFT_HANDLER_FACTORY_H
#define WAFFLE_THRIFT_HANDLER_FACTORY_H

#include "thrift_handler_factory.h"
#include "thrift_handler.h"
//#include <thrift/protocol/TBinaryProtocol.h>
//#include <thrift/server/TSimpleServer.h>
//#include <thrift/transport/TSocket.h>
//#include <thrift/transport/TServerSocket.h>
//#include <thrift/transport/TNonblockinsgServerSocket.h>
//#include <thrift/transport/TBufferTransports.h>
//#include <thrift/server/TServer.h>
//#include <thrift/server/TNonblockingServer.h>
//#include "../../proxy/src/proxy.h"
#include "waffle_thrift.h"

class thrift_handler_factory : public waffle_thriftIfFactory {
public:
    explicit thrift_handler_factory(std::shared_ptr<proxy> proxy, const std::string &proxy_type, 
                                    std::shared_ptr<thrift_response_client_map> id_to_client);
    waffle_thriftIf *getHandler(const ::apache::thrift::TConnectionInfo &connInfo) override;
    void releaseHandler(waffle_thriftIf *anIf) override;

private:
    std::shared_ptr<proxy> proxy_;
    std::string proxy_type_ = "waffle";
    std::shared_ptr<thrift_response_client_map> id_to_client_;
    std::atomic<int64_t> client_id_gen_;
};

#endif //PANCAKE_THRIFT_HANDLER_FACTORY_H