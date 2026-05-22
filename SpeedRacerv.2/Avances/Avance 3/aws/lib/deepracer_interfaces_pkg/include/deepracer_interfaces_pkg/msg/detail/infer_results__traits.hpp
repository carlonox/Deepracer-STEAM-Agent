// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:msg/InferResults.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__TRAITS_HPP_

#include "deepracer_interfaces_pkg/msg/detail/infer_results__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::msg::InferResults>()
{
  return "deepracer_interfaces_pkg::msg::InferResults";
}

template<>
inline const char * name<deepracer_interfaces_pkg::msg::InferResults>()
{
  return "deepracer_interfaces_pkg/msg/InferResults";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::msg::InferResults>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::msg::InferResults>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::msg::InferResults>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__TRAITS_HPP_
