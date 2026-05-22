// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetStatusLedBlinkSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_status_led_blink_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedBlinkSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedBlinkSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv>()
{
  return "deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv>()
{
  return "deepracer_interfaces_pkg/srv/SetStatusLedBlinkSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__TRAITS_HPP_
