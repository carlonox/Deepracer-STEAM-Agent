// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/ModelOptimizeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/ModelOptimizeSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/ModelOptimizeSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::ModelOptimizeSrv>()
{
  return "deepracer_interfaces_pkg::srv::ModelOptimizeSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::ModelOptimizeSrv>()
{
  return "deepracer_interfaces_pkg/srv/ModelOptimizeSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::ModelOptimizeSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__TRAITS_HPP_
