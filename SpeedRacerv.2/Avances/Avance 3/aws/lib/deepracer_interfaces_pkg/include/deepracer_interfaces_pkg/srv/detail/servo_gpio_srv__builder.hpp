// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/ServoGPIOSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SERVO_GPIO_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SERVO_GPIO_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/servo_gpio_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ServoGPIOSrv_Request_enable
{
public:
  Init_ServoGPIOSrv_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Request enable(::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ServoGPIOSrv_Request_enable();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ServoGPIOSrv_Response_error
{
public:
  Init_ServoGPIOSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Response error(::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ServoGPIOSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ServoGPIOSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SERVO_GPIO_SRV__BUILDER_HPP_
