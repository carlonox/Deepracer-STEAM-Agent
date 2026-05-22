// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/get_calibration_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_GetCalibrationSrv_Request_cal_type
{
public:
  Init_GetCalibrationSrv_Request_cal_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request cal_type(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request::_cal_type_type arg)
  {
    msg_.cal_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_GetCalibrationSrv_Request_cal_type();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_GetCalibrationSrv_Response_error
{
public:
  explicit Init_GetCalibrationSrv_Response_error(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response error(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response msg_;
};

class Init_GetCalibrationSrv_Response_polarity
{
public:
  explicit Init_GetCalibrationSrv_Response_polarity(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetCalibrationSrv_Response_error polarity(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response::_polarity_type arg)
  {
    msg_.polarity = std::move(arg);
    return Init_GetCalibrationSrv_Response_error(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response msg_;
};

class Init_GetCalibrationSrv_Response_min
{
public:
  explicit Init_GetCalibrationSrv_Response_min(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetCalibrationSrv_Response_polarity min(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response::_min_type arg)
  {
    msg_.min = std::move(arg);
    return Init_GetCalibrationSrv_Response_polarity(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response msg_;
};

class Init_GetCalibrationSrv_Response_mid
{
public:
  explicit Init_GetCalibrationSrv_Response_mid(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetCalibrationSrv_Response_min mid(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response::_mid_type arg)
  {
    msg_.mid = std::move(arg);
    return Init_GetCalibrationSrv_Response_min(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response msg_;
};

class Init_GetCalibrationSrv_Response_max
{
public:
  Init_GetCalibrationSrv_Response_max()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCalibrationSrv_Response_mid max(::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response::_max_type arg)
  {
    msg_.max = std::move(arg);
    return Init_GetCalibrationSrv_Response_mid(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_GetCalibrationSrv_Response_max();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__BUILDER_HPP_
