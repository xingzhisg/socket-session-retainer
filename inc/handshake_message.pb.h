// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: handshake_message.proto

#ifndef PROTOBUF_handshake_5fmessage_2eproto__INCLUDED
#define PROTOBUF_handshake_5fmessage_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace miu {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_handshake_5fmessage_2eproto();
void protobuf_AssignDesc_handshake_5fmessage_2eproto();
void protobuf_ShutdownFile_handshake_5fmessage_2eproto();

class handshake;

// ===================================================================

class handshake : public ::google::protobuf::Message {
 public:
  handshake();
  virtual ~handshake();
  
  handshake(const handshake& from);
  
  inline handshake& operator=(const handshake& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const handshake& default_instance();
  
  void Swap(handshake* other);
  
  // implements Message ----------------------------------------------
  
  handshake* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const handshake& from);
  void MergeFrom(const handshake& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string version = 1;
  inline bool has_version() const;
  inline void clear_version();
  static const int kVersionFieldNumber = 1;
  inline const ::std::string& version() const;
  inline void set_version(const ::std::string& value);
  inline void set_version(const char* value);
  inline void set_version(const char* value, size_t size);
  inline ::std::string* mutable_version();
  inline ::std::string* release_version();
  
  // required string host = 2;
  inline bool has_host() const;
  inline void clear_host();
  static const int kHostFieldNumber = 2;
  inline const ::std::string& host() const;
  inline void set_host(const ::std::string& value);
  inline void set_host(const char* value);
  inline void set_host(const char* value, size_t size);
  inline ::std::string* mutable_host();
  inline ::std::string* release_host();
  
  // required uint32 port = 3;
  inline bool has_port() const;
  inline void clear_port();
  static const int kPortFieldNumber = 3;
  inline ::google::protobuf::uint32 port() const;
  inline void set_port(::google::protobuf::uint32 value);
  
  // required string user = 4;
  inline bool has_user() const;
  inline void clear_user();
  static const int kUserFieldNumber = 4;
  inline const ::std::string& user() const;
  inline void set_user(const ::std::string& value);
  inline void set_user(const char* value);
  inline void set_user(const char* value, size_t size);
  inline ::std::string* mutable_user();
  inline ::std::string* release_user();
  
  // optional string cookie = 5;
  inline bool has_cookie() const;
  inline void clear_cookie();
  static const int kCookieFieldNumber = 5;
  inline const ::std::string& cookie() const;
  inline void set_cookie(const ::std::string& value);
  inline void set_cookie(const char* value);
  inline void set_cookie(const char* value, size_t size);
  inline ::std::string* mutable_cookie();
  inline ::std::string* release_cookie();
  
  // required string uuid = 6;
  inline bool has_uuid() const;
  inline void clear_uuid();
  static const int kUuidFieldNumber = 6;
  inline const ::std::string& uuid() const;
  inline void set_uuid(const ::std::string& value);
  inline void set_uuid(const char* value);
  inline void set_uuid(const char* value, size_t size);
  inline ::std::string* mutable_uuid();
  inline ::std::string* release_uuid();
  
  // required uint64 timestamp = 7;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 7;
  inline ::google::protobuf::uint64 timestamp() const;
  inline void set_timestamp(::google::protobuf::uint64 value);
  
  // required string hash = 8;
  inline bool has_hash() const;
  inline void clear_hash();
  static const int kHashFieldNumber = 8;
  inline const ::std::string& hash() const;
  inline void set_hash(const ::std::string& value);
  inline void set_hash(const char* value);
  inline void set_hash(const char* value, size_t size);
  inline ::std::string* mutable_hash();
  inline ::std::string* release_hash();
  
  // optional string app = 9;
  inline bool has_app() const;
  inline void clear_app();
  static const int kAppFieldNumber = 9;
  inline const ::std::string& app() const;
  inline void set_app(const ::std::string& value);
  inline void set_app(const char* value);
  inline void set_app(const char* value, size_t size);
  inline ::std::string* mutable_app();
  inline ::std::string* release_app();
  
  // @@protoc_insertion_point(class_scope:miu.handshake)
 private:
  inline void set_has_version();
  inline void clear_has_version();
  inline void set_has_host();
  inline void clear_has_host();
  inline void set_has_port();
  inline void clear_has_port();
  inline void set_has_user();
  inline void clear_has_user();
  inline void set_has_cookie();
  inline void clear_has_cookie();
  inline void set_has_uuid();
  inline void clear_has_uuid();
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_hash();
  inline void clear_has_hash();
  inline void set_has_app();
  inline void clear_has_app();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* version_;
  ::std::string* host_;
  ::std::string* user_;
  ::std::string* cookie_;
  ::std::string* uuid_;
  ::google::protobuf::uint64 timestamp_;
  ::std::string* hash_;
  ::std::string* app_;
  ::google::protobuf::uint32 port_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(9 + 31) / 32];
  
  friend void  protobuf_AddDesc_handshake_5fmessage_2eproto();
  friend void protobuf_AssignDesc_handshake_5fmessage_2eproto();
  friend void protobuf_ShutdownFile_handshake_5fmessage_2eproto();
  
  void InitAsDefaultInstance();
  static handshake* default_instance_;
};
// ===================================================================


// ===================================================================

// handshake

// required string version = 1;
inline bool handshake::has_version() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void handshake::set_has_version() {
  _has_bits_[0] |= 0x00000001u;
}
inline void handshake::clear_has_version() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void handshake::clear_version() {
  if (version_ != &::google::protobuf::internal::kEmptyString) {
    version_->clear();
  }
  clear_has_version();
}
inline const ::std::string& handshake::version() const {
  return *version_;
}
inline void handshake::set_version(const ::std::string& value) {
  set_has_version();
  if (version_ == &::google::protobuf::internal::kEmptyString) {
    version_ = new ::std::string;
  }
  version_->assign(value);
}
inline void handshake::set_version(const char* value) {
  set_has_version();
  if (version_ == &::google::protobuf::internal::kEmptyString) {
    version_ = new ::std::string;
  }
  version_->assign(value);
}
inline void handshake::set_version(const char* value, size_t size) {
  set_has_version();
  if (version_ == &::google::protobuf::internal::kEmptyString) {
    version_ = new ::std::string;
  }
  version_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_version() {
  set_has_version();
  if (version_ == &::google::protobuf::internal::kEmptyString) {
    version_ = new ::std::string;
  }
  return version_;
}
inline ::std::string* handshake::release_version() {
  clear_has_version();
  if (version_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = version_;
    version_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string host = 2;
inline bool handshake::has_host() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void handshake::set_has_host() {
  _has_bits_[0] |= 0x00000002u;
}
inline void handshake::clear_has_host() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void handshake::clear_host() {
  if (host_ != &::google::protobuf::internal::kEmptyString) {
    host_->clear();
  }
  clear_has_host();
}
inline const ::std::string& handshake::host() const {
  return *host_;
}
inline void handshake::set_host(const ::std::string& value) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(value);
}
inline void handshake::set_host(const char* value) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(value);
}
inline void handshake::set_host(const char* value, size_t size) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_host() {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  return host_;
}
inline ::std::string* handshake::release_host() {
  clear_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = host_;
    host_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required uint32 port = 3;
inline bool handshake::has_port() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void handshake::set_has_port() {
  _has_bits_[0] |= 0x00000004u;
}
inline void handshake::clear_has_port() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void handshake::clear_port() {
  port_ = 0u;
  clear_has_port();
}
inline ::google::protobuf::uint32 handshake::port() const {
  return port_;
}
inline void handshake::set_port(::google::protobuf::uint32 value) {
  set_has_port();
  port_ = value;
}

// required string user = 4;
inline bool handshake::has_user() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void handshake::set_has_user() {
  _has_bits_[0] |= 0x00000008u;
}
inline void handshake::clear_has_user() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void handshake::clear_user() {
  if (user_ != &::google::protobuf::internal::kEmptyString) {
    user_->clear();
  }
  clear_has_user();
}
inline const ::std::string& handshake::user() const {
  return *user_;
}
inline void handshake::set_user(const ::std::string& value) {
  set_has_user();
  if (user_ == &::google::protobuf::internal::kEmptyString) {
    user_ = new ::std::string;
  }
  user_->assign(value);
}
inline void handshake::set_user(const char* value) {
  set_has_user();
  if (user_ == &::google::protobuf::internal::kEmptyString) {
    user_ = new ::std::string;
  }
  user_->assign(value);
}
inline void handshake::set_user(const char* value, size_t size) {
  set_has_user();
  if (user_ == &::google::protobuf::internal::kEmptyString) {
    user_ = new ::std::string;
  }
  user_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_user() {
  set_has_user();
  if (user_ == &::google::protobuf::internal::kEmptyString) {
    user_ = new ::std::string;
  }
  return user_;
}
inline ::std::string* handshake::release_user() {
  clear_has_user();
  if (user_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = user_;
    user_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string cookie = 5;
inline bool handshake::has_cookie() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void handshake::set_has_cookie() {
  _has_bits_[0] |= 0x00000010u;
}
inline void handshake::clear_has_cookie() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void handshake::clear_cookie() {
  if (cookie_ != &::google::protobuf::internal::kEmptyString) {
    cookie_->clear();
  }
  clear_has_cookie();
}
inline const ::std::string& handshake::cookie() const {
  return *cookie_;
}
inline void handshake::set_cookie(const ::std::string& value) {
  set_has_cookie();
  if (cookie_ == &::google::protobuf::internal::kEmptyString) {
    cookie_ = new ::std::string;
  }
  cookie_->assign(value);
}
inline void handshake::set_cookie(const char* value) {
  set_has_cookie();
  if (cookie_ == &::google::protobuf::internal::kEmptyString) {
    cookie_ = new ::std::string;
  }
  cookie_->assign(value);
}
inline void handshake::set_cookie(const char* value, size_t size) {
  set_has_cookie();
  if (cookie_ == &::google::protobuf::internal::kEmptyString) {
    cookie_ = new ::std::string;
  }
  cookie_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_cookie() {
  set_has_cookie();
  if (cookie_ == &::google::protobuf::internal::kEmptyString) {
    cookie_ = new ::std::string;
  }
  return cookie_;
}
inline ::std::string* handshake::release_cookie() {
  clear_has_cookie();
  if (cookie_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = cookie_;
    cookie_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string uuid = 6;
inline bool handshake::has_uuid() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void handshake::set_has_uuid() {
  _has_bits_[0] |= 0x00000020u;
}
inline void handshake::clear_has_uuid() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void handshake::clear_uuid() {
  if (uuid_ != &::google::protobuf::internal::kEmptyString) {
    uuid_->clear();
  }
  clear_has_uuid();
}
inline const ::std::string& handshake::uuid() const {
  return *uuid_;
}
inline void handshake::set_uuid(const ::std::string& value) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(value);
}
inline void handshake::set_uuid(const char* value) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(value);
}
inline void handshake::set_uuid(const char* value, size_t size) {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  uuid_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_uuid() {
  set_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    uuid_ = new ::std::string;
  }
  return uuid_;
}
inline ::std::string* handshake::release_uuid() {
  clear_has_uuid();
  if (uuid_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = uuid_;
    uuid_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required uint64 timestamp = 7;
inline bool handshake::has_timestamp() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void handshake::set_has_timestamp() {
  _has_bits_[0] |= 0x00000040u;
}
inline void handshake::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void handshake::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::uint64 handshake::timestamp() const {
  return timestamp_;
}
inline void handshake::set_timestamp(::google::protobuf::uint64 value) {
  set_has_timestamp();
  timestamp_ = value;
}

// required string hash = 8;
inline bool handshake::has_hash() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void handshake::set_has_hash() {
  _has_bits_[0] |= 0x00000080u;
}
inline void handshake::clear_has_hash() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void handshake::clear_hash() {
  if (hash_ != &::google::protobuf::internal::kEmptyString) {
    hash_->clear();
  }
  clear_has_hash();
}
inline const ::std::string& handshake::hash() const {
  return *hash_;
}
inline void handshake::set_hash(const ::std::string& value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void handshake::set_hash(const char* value) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(value);
}
inline void handshake::set_hash(const char* value, size_t size) {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  hash_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_hash() {
  set_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    hash_ = new ::std::string;
  }
  return hash_;
}
inline ::std::string* handshake::release_hash() {
  clear_has_hash();
  if (hash_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = hash_;
    hash_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string app = 9;
inline bool handshake::has_app() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void handshake::set_has_app() {
  _has_bits_[0] |= 0x00000100u;
}
inline void handshake::clear_has_app() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void handshake::clear_app() {
  if (app_ != &::google::protobuf::internal::kEmptyString) {
    app_->clear();
  }
  clear_has_app();
}
inline const ::std::string& handshake::app() const {
  return *app_;
}
inline void handshake::set_app(const ::std::string& value) {
  set_has_app();
  if (app_ == &::google::protobuf::internal::kEmptyString) {
    app_ = new ::std::string;
  }
  app_->assign(value);
}
inline void handshake::set_app(const char* value) {
  set_has_app();
  if (app_ == &::google::protobuf::internal::kEmptyString) {
    app_ = new ::std::string;
  }
  app_->assign(value);
}
inline void handshake::set_app(const char* value, size_t size) {
  set_has_app();
  if (app_ == &::google::protobuf::internal::kEmptyString) {
    app_ = new ::std::string;
  }
  app_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* handshake::mutable_app() {
  set_has_app();
  if (app_ == &::google::protobuf::internal::kEmptyString) {
    app_ = new ::std::string;
  }
  return app_;
}
inline ::std::string* handshake::release_app() {
  clear_has_app();
  if (app_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = app_;
    app_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace miu

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_handshake_5fmessage_2eproto__INCLUDED