// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "waffle_thrift.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class waffle_thriftHandler : virtual public waffle_thriftIf {
 public:
  waffle_thriftHandler() {
    // Your initialization goes here
  }

  int64_t get_client_id() {
    // Your implementation goes here
    printf("get_client_id\n");
  }

  void register_client_id(const int32_t block_id, const int64_t client_id) {
    // Your implementation goes here
    printf("register_client_id\n");
  }

  void async_get(const sequence_id& seq_id, const std::string& key) {
    // Your implementation goes here
    printf("async_get\n");
  }

  void async_put(const sequence_id& seq_id, const std::string& key, const std::string& value) {
    // Your implementation goes here
    printf("async_put\n");
  }

  void async_get_batch(const sequence_id& seq_id, const std::vector<std::string> & keys) {
    // Your implementation goes here
    printf("async_get_batch\n");
  }

  void async_put_batch(const sequence_id& seq_id, const std::vector<std::string> & keys, const std::vector<std::string> & values) {
    // Your implementation goes here
    printf("async_put_batch\n");
  }

  void get(std::string& _return, const std::string& key) {
    // Your implementation goes here
    printf("get\n");
  }

  void put(const std::string& key, const std::string& value) {
    // Your implementation goes here
    printf("put\n");
  }

  void get_batch(std::vector<std::string> & _return, const std::vector<std::string> & keys) {
    // Your implementation goes here
    printf("get_batch\n");
  }

  void put_batch(const std::vector<std::string> & keys, const std::vector<std::string> & values) {
    // Your implementation goes here
    printf("put_batch\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<waffle_thriftHandler> handler(new waffle_thriftHandler());
  ::std::shared_ptr<TProcessor> processor(new waffle_thriftProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
