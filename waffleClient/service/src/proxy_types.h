/**
 * Autogenerated by Thrift Compiler (0.17.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef proxy_TYPES_H
#define proxy_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>




class sequence_id;


class sequence_id : public virtual ::apache::thrift::TBase {
 public:

  sequence_id(const sequence_id&) noexcept;
  sequence_id& operator=(const sequence_id&) noexcept;
  sequence_id() noexcept
              : client_id(0),
                client_seq_no(0),
                server_seq_no(0) {
  }

  virtual ~sequence_id() noexcept;
  int64_t client_id;
  int64_t client_seq_no;
  int64_t server_seq_no;

  void __set_client_id(const int64_t val);

  void __set_client_seq_no(const int64_t val);

  void __set_server_seq_no(const int64_t val);

  bool operator == (const sequence_id & rhs) const
  {
    if (!(client_id == rhs.client_id))
      return false;
    if (!(client_seq_no == rhs.client_seq_no))
      return false;
    if (!(server_seq_no == rhs.server_seq_no))
      return false;
    return true;
  }
  bool operator != (const sequence_id &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const sequence_id & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot) override;
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const override;

  virtual void printTo(std::ostream& out) const;
};

void swap(sequence_id &a, sequence_id &b);

std::ostream& operator<<(std::ostream& out, const sequence_id& obj);



#endif