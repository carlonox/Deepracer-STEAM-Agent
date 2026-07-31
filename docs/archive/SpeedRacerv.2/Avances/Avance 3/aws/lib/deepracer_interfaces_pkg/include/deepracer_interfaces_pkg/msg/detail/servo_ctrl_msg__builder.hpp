// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_ServoCtrlMsg_throttle
{
public:
  explicit Init_ServoCtrlMsg_throttle(::deepracer_interfaces_pkg::msg::ServoCtrlMsg & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::ServoCtrlMsg throttle(::deepracer_interfaces_pkg::msg::ServoCtrlMsg::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::ServoCtrlMsg msg_;
};

class Init_ServoCtrlMsg_angle
{
public:
  Init_ServoCtrlMsg_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoCtrlMsg_throttle angle(::deepracer_interfaces_pkg::msg::ServoCtrlMsg::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_ServoCtrlMsg_throttle(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::ServoCtrlMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::ServoCtrlMsg>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_ServoCtrlMsg_angle();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__BUILDER_HPP_
