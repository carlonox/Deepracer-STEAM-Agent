// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:msg/EvoSensorMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__TRAITS_HPP_

#include "deepracer_interfaces_pkg/msg/detail/evo_sensor_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::msg::EvoSensorMsg>()
{
  return "deepracer_interfaces_pkg::msg::EvoSensorMsg";
}

template<>
inline const char * name<deepracer_interfaces_pkg::msg::EvoSensorMsg>()
{
  return "deepracer_interfaces_pkg/msg/EvoSensorMsg";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::msg::EvoSensorMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::msg::EvoSensorMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::msg::EvoSensorMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__TRAITS_HPP_
