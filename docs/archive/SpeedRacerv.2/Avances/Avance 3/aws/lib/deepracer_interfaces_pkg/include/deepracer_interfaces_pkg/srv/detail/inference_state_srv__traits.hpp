// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/InferenceStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__INFERENCE_STATE_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__INFERENCE_STATE_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/inference_state_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::InferenceStateSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/InferenceStateSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::InferenceStateSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/InferenceStateSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::InferenceStateSrv>()
{
  return "deepracer_interfaces_pkg::srv::InferenceStateSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::InferenceStateSrv>()
{
  return "deepracer_interfaces_pkg/srv/InferenceStateSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::InferenceStateSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::InferenceStateSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::InferenceStateSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::InferenceStateSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::InferenceStateSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__INFERENCE_STATE_SRV__TRAITS_HPP_
