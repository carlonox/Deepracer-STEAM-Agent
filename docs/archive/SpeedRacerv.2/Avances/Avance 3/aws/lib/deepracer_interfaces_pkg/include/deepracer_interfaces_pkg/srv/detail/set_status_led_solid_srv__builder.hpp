// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetStatusLedSolidSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_status_led_solid_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetStatusLedSolidSrv_Request_hold
{
public:
  explicit Init_SetStatusLedSolidSrv_Request_hold(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request hold(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request::_hold_type arg)
  {
    msg_.hold = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request msg_;
};

class Init_SetStatusLedSolidSrv_Request_color
{
public:
  explicit Init_SetStatusLedSolidSrv_Request_color(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetStatusLedSolidSrv_Request_hold color(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_SetStatusLedSolidSrv_Request_hold(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request msg_;
};

class Init_SetStatusLedSolidSrv_Request_led_index
{
public:
  Init_SetStatusLedSolidSrv_Request_led_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStatusLedSolidSrv_Request_color led_index(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request::_led_index_type arg)
  {
    msg_.led_index = std::move(arg);
    return Init_SetStatusLedSolidSrv_Request_color(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetStatusLedSolidSrv_Request_led_index();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetStatusLedSolidSrv_Response_error
{
public:
  Init_SetStatusLedSolidSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response error(::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetStatusLedSolidSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetStatusLedSolidSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__BUILDER_HPP_
