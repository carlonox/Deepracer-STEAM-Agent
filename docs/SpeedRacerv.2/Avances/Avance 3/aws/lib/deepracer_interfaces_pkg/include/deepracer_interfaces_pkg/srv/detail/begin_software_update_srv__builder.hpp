// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/BeginSoftwareUpdateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/begin_software_update_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_BeginSoftwareUpdateSrv_Request_sleep_time_before_reboot
{
public:
  Init_BeginSoftwareUpdateSrv_Request_sleep_time_before_reboot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request sleep_time_before_reboot(::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request::_sleep_time_before_reboot_type arg)
  {
    msg_.sleep_time_before_reboot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_BeginSoftwareUpdateSrv_Request_sleep_time_before_reboot();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_BeginSoftwareUpdateSrv_Response_response_status
{
public:
  Init_BeginSoftwareUpdateSrv_Response_response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response response_status(::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response::_response_status_type arg)
  {
    msg_.response_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_BeginSoftwareUpdateSrv_Response_response_status();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__BUILDER_HPP_
