// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/EnableStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ENABLE_STATE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ENABLE_STATE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/enable_state_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_EnableStateSrv_Request_is_active
{
public:
  Init_EnableStateSrv_Request_is_active()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::EnableStateSrv_Request is_active(::deepracer_interfaces_pkg::srv::EnableStateSrv_Request::_is_active_type arg)
  {
    msg_.is_active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::EnableStateSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::EnableStateSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_EnableStateSrv_Request_is_active();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_EnableStateSrv_Response_error
{
public:
  Init_EnableStateSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::EnableStateSrv_Response error(::deepracer_interfaces_pkg::srv::EnableStateSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::EnableStateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::EnableStateSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_EnableStateSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ENABLE_STATE_SRV__BUILDER_HPP_
