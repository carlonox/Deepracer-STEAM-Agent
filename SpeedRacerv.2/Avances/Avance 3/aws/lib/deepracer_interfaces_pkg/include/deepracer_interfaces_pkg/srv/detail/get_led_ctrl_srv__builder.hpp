// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetLedCtrlSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/get_led_ctrl_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_GetLedCtrlSrv_Response_blue
{
public:
  explicit Init_GetLedCtrlSrv_Response_blue(::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response blue(::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response msg_;
};

class Init_GetLedCtrlSrv_Response_green
{
public:
  explicit Init_GetLedCtrlSrv_Response_green(::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetLedCtrlSrv_Response_blue green(::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_GetLedCtrlSrv_Response_blue(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response msg_;
};

class Init_GetLedCtrlSrv_Response_red
{
public:
  Init_GetLedCtrlSrv_Response_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetLedCtrlSrv_Response_green red(::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_GetLedCtrlSrv_Response_green(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_GetLedCtrlSrv_Response_red();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__BUILDER_HPP_
