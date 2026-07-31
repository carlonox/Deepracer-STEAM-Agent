// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetStatusLedSolidSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_status_led_solid_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedSolidSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedSolidSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedSolidSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__TRAITS_HPP_
