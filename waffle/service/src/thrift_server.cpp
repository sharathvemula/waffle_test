//
// Created by Lloyd Brown on 10/5/19.
//

#include "thrift_server.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

std::shared_ptr<TServer> thrift_server::create(std::shared_ptr<proxy> proxy_ptr, const std::string &proxy_type, std::shared_ptr<thrift_response_client_map> id_to_client, int port, size_t num_threads) {
    auto clone_factory = std::make_shared<thrift_handler_factory>(proxy_ptr, proxy_type, id_to_client);
    auto proc_factory = std::make_shared<waffle_thriftProcessorFactory>(clone_factory);
    auto socket = std::make_shared<TNonblockingServerSocket>(port);
    socket->setSendTimeout(1200000);

    std::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    std::shared_ptr<PosixThreadFactory> threadFactory = std::shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    auto server = std::make_shared<TNonblockingServer>(proc_factory, std::make_shared<TBinaryProtocolFactory>(), socket, threadManager);

    server->setNumIOThreads(num_threads);
    return server;
}
