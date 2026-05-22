// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/NetworkConnectionStatus.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/network_connection_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_NetworkConnectionStatus_network_connected
{
public:
  Init_NetworkConnectionStatus_network_connected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::msg::NetworkConnectionStatus network_connected(::deepracer_interfaces_pkg::msg::NetworkConnectionStatus::_network_connected_type arg)
  {
    msg_.network_connected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::NetworkConnectionStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::NetworkConnectionStatus>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_NetworkConnectionStatus_network_connected();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__BUILDER_HPP_
