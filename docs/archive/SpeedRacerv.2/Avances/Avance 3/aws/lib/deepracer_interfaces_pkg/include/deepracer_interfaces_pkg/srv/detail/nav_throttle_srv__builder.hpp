// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/NavThrottleSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/nav_throttle_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_NavThrottleSrv_Request_throttle
{
public:
  Init_NavThrottleSrv_Request_throttle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::NavThrottleSrv_Request throttle(::deepracer_interfaces_pkg::srv::NavThrottleSrv_Request::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::NavThrottleSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::NavThrottleSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_NavThrottleSrv_Request_throttle();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_NavThrottleSrv_Response_error
{
public:
  Init_NavThrottleSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::NavThrottleSrv_Response error(::deepracer_interfaces_pkg::srv::NavThrottleSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::NavThrottleSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::NavThrottleSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_NavThrottleSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__BUILDER_HPP_
