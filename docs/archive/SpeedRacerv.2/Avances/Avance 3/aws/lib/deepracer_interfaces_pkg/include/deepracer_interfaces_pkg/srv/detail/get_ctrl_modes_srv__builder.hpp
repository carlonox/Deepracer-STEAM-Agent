// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetCtrlModesSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/get_ctrl_modes_srv__struct.hpp"
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
auto build<::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_GetCtrlModesSrv_Response_error
{
public:
  explicit Init_GetCtrlModesSrv_Response_error(::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response error(::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response msg_;
};

class Init_GetCtrlModesSrv_Response_modes
{
public:
  Init_GetCtrlModesSrv_Response_modes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCtrlModesSrv_Response_error modes(::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response::_modes_type arg)
  {
    msg_.modes = std::move(arg);
    return Init_GetCtrlModesSrv_Response_error(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::GetCtrlModesSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_GetCtrlModesSrv_Response_modes();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__BUILDER_HPP_
