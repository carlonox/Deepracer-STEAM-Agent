// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/SetCalibrationSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/SetCalibrationSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetCalibrationSrv>()
{
  return "deepracer_interfaces_pkg::srv::SetCalibrationSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetCalibrationSrv>()
{
  return "deepracer_interfaces_pkg/srv/SetCalibrationSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::SetCalibrationSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__TRAITS_HPP_
