// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetDeviceInfoSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_DEVICE_INFO_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_DEVICE_INFO_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/get_device_info_srv__struct.hpp"
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
auto build<::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_GetDeviceInfoSrv_Response_error
{
public:
  explicit Init_GetDeviceInfoSrv_Response_error(::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response error(::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response msg_;
};

class Init_GetDeviceInfoSrv_Response_software_version
{
public:
  explicit Init_GetDeviceInfoSrv_Response_software_version(::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response & msg)
  : msg_(msg)
  {}
  Init_GetDeviceInfoSrv_Response_error software_version(::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response::_software_version_type arg)
  {
    msg_.software_version = std::move(arg);
    return Init_GetDeviceInfoSrv_Response_error(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response msg_;
};

class Init_GetDeviceInfoSrv_Response_hardware_version
{
public:
  Init_GetDeviceInfoSrv_Response_hardware_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDeviceInfoSrv_Response_software_version hardware_version(::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response::_hardware_version_type arg)
  {
    msg_.hardware_version = std::move(arg);
    return Init_GetDeviceInfoSrv_Response_software_version(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetDeviceInfoSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_GetDeviceInfoSrv_Response_hardware_version();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_DEVICE_INFO_SRV__BUILDER_HPP_
