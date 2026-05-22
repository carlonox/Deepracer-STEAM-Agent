// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SensorStatusCheckSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/sensor_status_check_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SensorStatusCheckSrv_Response_error
{
public:
  explicit Init_SensorStatusCheckSrv_Response_error(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response error(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response msg_;
};

class Init_SensorStatusCheckSrv_Response_stereo_camera_status
{
public:
  explicit Init_SensorStatusCheckSrv_Response_stereo_camera_status(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response & msg)
  : msg_(msg)
  {}
  Init_SensorStatusCheckSrv_Response_error stereo_camera_status(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response::_stereo_camera_status_type arg)
  {
    msg_.stereo_camera_status = std::move(arg);
    return Init_SensorStatusCheckSrv_Response_error(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response msg_;
};

class Init_SensorStatusCheckSrv_Response_single_camera_status
{
public:
  explicit Init_SensorStatusCheckSrv_Response_single_camera_status(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response & msg)
  : msg_(msg)
  {}
  Init_SensorStatusCheckSrv_Response_stereo_camera_status single_camera_status(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response::_single_camera_status_type arg)
  {
    msg_.single_camera_status = std::move(arg);
    return Init_SensorStatusCheckSrv_Response_stereo_camera_status(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response msg_;
};

class Init_SensorStatusCheckSrv_Response_lidar_status
{
public:
  Init_SensorStatusCheckSrv_Response_lidar_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorStatusCheckSrv_Response_single_camera_status lidar_status(::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response::_lidar_status_type arg)
  {
    msg_.lidar_status = std::move(arg);
    return Init_SensorStatusCheckSrv_Response_single_camera_status(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SensorStatusCheckSrv_Response_lidar_status();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__BUILDER_HPP_
