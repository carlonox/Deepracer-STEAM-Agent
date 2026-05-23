// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetLedCtrlSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_LED_CTRL_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_LED_CTRL_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_led_ctrl_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetLedCtrlSrv_Request_blue
{
public:
  explicit Init_SetLedCtrlSrv_Request_blue(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request blue(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request msg_;
};

class Init_SetLedCtrlSrv_Request_green
{
public:
  explicit Init_SetLedCtrlSrv_Request_green(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetLedCtrlSrv_Request_blue green(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_SetLedCtrlSrv_Request_blue(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request msg_;
};

class Init_SetLedCtrlSrv_Request_red
{
public:
  Init_SetLedCtrlSrv_Request_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetLedCtrlSrv_Request_green red(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_SetLedCtrlSrv_Request_green(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetLedCtrlSrv_Request_red();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetLedCtrlSrv_Response_error
{
public:
  Init_SetLedCtrlSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Response error(::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetLedCtrlSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetLedCtrlSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_LED_CTRL_SRV__BUILDER_HPP_
