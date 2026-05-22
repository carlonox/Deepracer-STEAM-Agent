// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SoftwareUpdateCheckSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/software_update_check_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SoftwareUpdateCheckSrv_Request_force_update_check
{
public:
  Init_SoftwareUpdateCheckSrv_Request_force_update_check()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request force_update_check(::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request::_force_update_check_type arg)
  {
    msg_.force_update_check = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SoftwareUpdateCheckSrv_Request_force_update_check();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SoftwareUpdateCheckSrv_Response_software_update_state
{
public:
  Init_SoftwareUpdateCheckSrv_Response_software_update_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response software_update_state(::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response::_software_update_state_type arg)
  {
    msg_.software_update_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SoftwareUpdateCheckSrv_Response_software_update_state();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__BUILDER_HPP_
