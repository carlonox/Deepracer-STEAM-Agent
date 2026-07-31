// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/VerifyModelReadySrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VERIFY_MODEL_READY_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VERIFY_MODEL_READY_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/verify_model_ready_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_VerifyModelReadySrv_Request_model_name
{
public:
  Init_VerifyModelReadySrv_Request_model_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Request model_name(::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Request::_model_name_type arg)
  {
    msg_.model_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_VerifyModelReadySrv_Request_model_name();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_VerifyModelReadySrv_Response_response_status
{
public:
  Init_VerifyModelReadySrv_Response_response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Response response_status(::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Response::_response_status_type arg)
  {
    msg_.response_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::VerifyModelReadySrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_VerifyModelReadySrv_Response_response_status();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VERIFY_MODEL_READY_SRV__BUILDER_HPP_
