#include "thrift_response_client_map.h"

thrift_response_client_map::thrift_response_client_map() : clients_(0) {
}

void thrift_response_client_map::add_client(int64_t client_id, std::shared_ptr<thrift_response_client> client) {
  clients_.insert(client_id, client);
}

void thrift_response_client_map::remove_client(int64_t client_id) {
  clients_.erase(client_id);
}

void thrift_response_client_map::async_respond_client(const sequence_id &seq, int op_code, const std::vector<std::string> &result) {
  if (seq.client_id == -1) {
    std::cout << "Client ID is -1 " << std::endl;
    return;
  }

  bool found = clients_.update_fn(seq.client_id, [&](std::shared_ptr<thrift_response_client> &client) {
    try {
      client->async_response(seq, op_code, result);
    }
    catch (apache::thrift::transport::TTransportException e) {
      std::cout << "sending error: " << e.what() << std::endl;
    }
  });

  if (!found) {
   std::cout << "Client ID not found" << std::endl;
  }

}

void thrift_response_client_map::clear() {
  clients_.clear();
}

void thrift_response_client_map::send_failure() {
  sequence_id fail;
  fail.__set_client_id(-2);
  fail.__set_client_seq_no(-2);
  fail.__set_client_id(-2);
  for (const auto &x : clients_.lock_table()) {
  try {
      std::vector<std::string> _result;
      x.second->async_response(fail, 5, _result);
  } 
  catch (std::exception &e) {
    continue;
    }
  }
}