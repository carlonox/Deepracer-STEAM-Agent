// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetStatusLedBlinkSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_status_led_blink_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetStatusLedBlinkSrv_Request_delay
{
public:
  explicit Init_SetStatusLedBlinkSrv_Request_delay(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request delay(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request::_delay_type arg)
  {
    msg_.delay = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request msg_;
};

class Init_SetStatusLedBlinkSrv_Request_color2
{
public:
  explicit Init_SetStatusLedBlinkSrv_Request_color2(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetStatusLedBlinkSrv_Request_delay color2(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request::_color2_type arg)
  {
    msg_.color2 = std::move(arg);
    return Init_SetStatusLedBlinkSrv_Request_delay(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request msg_;
};

class Init_SetStatusLedBlinkSrv_Request_color1
{
public:
  explicit Init_SetStatusLedBlinkSrv_Request_color1(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetStatusLedBlinkSrv_Request_color2 color1(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request::_color1_type arg)
  {
    msg_.color1 = std::move(arg);
    return Init_SetStatusLedBlinkSrv_Request_color2(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request msg_;
};

class Init_SetStatusLedBlinkSrv_Request_led_index
{
public:
  Init_SetStatusLedBlinkSrv_Request_led_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStatusLedBlinkSrv_Request_color1 led_index(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request::_led_index_type arg)
  {
    msg_.led_index = std::move(arg);
    return Init_SetStatusLedBlinkSrv_Request_color1(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetStatusLedBlinkSrv_Request_led_index();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetStatusLedBlinkSrv_Response_error
{
public:
  Init_SetStatusLedBlinkSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response error(::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetStatusLedBlinkSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetStatusLedBlinkSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_BLINK_SRV__BUILDER_HPP_
