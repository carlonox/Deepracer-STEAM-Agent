// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/ConsoleModelActionSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/console_model_action_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ConsoleModelActionSrv_Request_action
{
public:
  explicit Init_ConsoleModelActionSrv_Request_action(::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request action(::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request msg_;
};

class Init_ConsoleModelActionSrv_Request_model_path
{
public:
  Init_ConsoleModelActionSrv_Request_model_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConsoleModelActionSrv_Request_action model_path(::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request::_model_path_type arg)
  {
    msg_.model_path = std::move(arg);
    return Init_ConsoleModelActionSrv_Request_action(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ConsoleModelActionSrv_Request_model_path();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ConsoleModelActionSrv_Response_status
{
public:
  Init_ConsoleModelActionSrv_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response status(::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ConsoleModelActionSrv_Response_status();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__BUILDER_HPP_
