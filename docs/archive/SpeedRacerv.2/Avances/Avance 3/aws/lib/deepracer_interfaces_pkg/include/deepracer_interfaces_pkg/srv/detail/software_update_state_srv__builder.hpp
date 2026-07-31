// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/SoftwareUpdateStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/software_update_state_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SoftwareUpdateStateSrv_Request_request
{
public:
  Init_SoftwareUpdateStateSrv_Request_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Request request(::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Request::_request_type arg)
  {
    msg_.request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SoftwareUpdateStateSrv_Request_request();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_SoftwareUpdateStateSrv_Response_update_state
{
public:
  Init_SoftwareUpdateStateSrv_Response_update_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Response update_state(::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Response::_update_state_type arg)
  {
    msg_.update_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::SoftwareUpdateStateSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_SoftwareUpdateStateSrv_Response_update_state();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__BUILDER_HPP_
