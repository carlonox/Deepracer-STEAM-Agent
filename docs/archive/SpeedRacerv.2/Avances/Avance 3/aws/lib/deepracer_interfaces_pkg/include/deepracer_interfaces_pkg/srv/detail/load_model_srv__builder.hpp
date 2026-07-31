// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/LoadModelSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/load_model_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_LoadModelSrv_Request_action_space_type
{
public:
  explicit Init_LoadModelSrv_Request_action_space_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Request action_space_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request::_action_space_type_type arg)
  {
    msg_.action_space_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Request msg_;
};

class Init_LoadModelSrv_Request_pre_process_type
{
public:
  explicit Init_LoadModelSrv_Request_pre_process_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LoadModelSrv_Request_action_space_type pre_process_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request::_pre_process_type_type arg)
  {
    msg_.pre_process_type = std::move(arg);
    return Init_LoadModelSrv_Request_action_space_type(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Request msg_;
};

class Init_LoadModelSrv_Request_task_type
{
public:
  explicit Init_LoadModelSrv_Request_task_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LoadModelSrv_Request_pre_process_type task_type(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_LoadModelSrv_Request_pre_process_type(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Request msg_;
};

class Init_LoadModelSrv_Request_artifact_path
{
public:
  Init_LoadModelSrv_Request_artifact_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadModelSrv_Request_task_type artifact_path(::deepracer_interfaces_pkg::srv::LoadModelSrv_Request::_artifact_path_type arg)
  {
    msg_.artifact_path = std::move(arg);
    return Init_LoadModelSrv_Request_task_type(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::LoadModelSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_LoadModelSrv_Request_artifact_path();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_LoadModelSrv_Response_error
{
public:
  Init_LoadModelSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Response error(::deepracer_interfaces_pkg::srv::LoadModelSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LoadModelSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::LoadModelSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_LoadModelSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__BUILDER_HPP_
