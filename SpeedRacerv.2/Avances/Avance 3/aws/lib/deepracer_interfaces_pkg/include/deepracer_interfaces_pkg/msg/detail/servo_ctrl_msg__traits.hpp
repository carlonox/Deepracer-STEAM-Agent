// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__TRAITS_HPP_

#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::msg::ServoCtrlMsg>()
{
  return "deepracer_interfaces_pkg::msg::ServoCtrlMsg";
}

template<>
inline const char * name<deepracer_interfaces_pkg::msg::ServoCtrlMsg>()
{
  return "deepracer_interfaces_pkg/msg/ServoCtrlMsg";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::msg::ServoCtrlMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::msg::ServoCtrlMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::msg::ServoCtrlMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__TRAITS_HPP_
