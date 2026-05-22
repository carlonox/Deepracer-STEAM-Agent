// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetCalibrationSrv_Request_polarity
{
public:
  explicit Init_SetCalibrationSrv_Request_polarity(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request polarity(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request::_polarity_type arg)
  {
    msg_.polarity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request msg_;
};

class Init_SetCalibrationSrv_Request_min
{
public:
  explicit Init_SetCalibrationSrv_Request_min(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetCalibrationSrv_Request_polarity min(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_SetCalibrationSrv_Request_polarity(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request msg_;
};

class Init_SetCalibrationSrv_Request_mid
{
public:
  explicit Init_SetCalibrationSrv_Request_mid(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetCalibrationSrv_Request_min mid(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request::_mid_type arg)
  {
    msg_.mid = std::move(arg);
    return Init_SetCalibrationSrv_Request_min(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request msg_;
};

class Init_SetCalibrationSrv_Request_max
{
public:
  explicit Init_SetCalibrationSrv_Request_max(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request & msg)
  : msg_(msg)
  {}
  Init_SetCalibrationSrv_Request_mid max(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request::_max_type arg)
  {
    msg_.max = std::move(arg);
    return Init_SetCalibrationSrv_Request_mid(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request msg_;
};

class Init_SetCalibrationSrv_Request_cal_type
{
public:
  Init_SetCalibrationSrv_Request_cal_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCalibrationSrv_Request_max cal_type(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request::_cal_type_type arg)
  {
    msg_.cal_type = std::move(arg);
    return Init_SetCalibrationSrv_Request_max(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetCalibrationSrv_Request_cal_type();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SetCalibrationSrv_Response_error
{
public:
  Init_SetCalibrationSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response error(::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SetCalibrationSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SetCalibrationSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_CALIBRATION_SRV__BUILDER_HPP_
