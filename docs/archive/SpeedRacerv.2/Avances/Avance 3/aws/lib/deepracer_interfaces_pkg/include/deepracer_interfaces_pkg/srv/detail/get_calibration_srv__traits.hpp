// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/get_calibration_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/GetCalibrationSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/GetCalibrationSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::GetCalibrationSrv>()
{
  return "deepracer_interfaces_pkg::srv::GetCalibrationSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::GetCalibrationSrv>()
{
  return "deepracer_interfaces_pkg/srv/GetCalibrationSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::GetCalibrationSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__TRAITS_HPP_
