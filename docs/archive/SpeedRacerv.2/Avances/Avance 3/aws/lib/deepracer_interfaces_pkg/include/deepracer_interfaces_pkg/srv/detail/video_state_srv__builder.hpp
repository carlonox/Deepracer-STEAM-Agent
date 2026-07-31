// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/VideoStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VIDEO_STATE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VIDEO_STATE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/video_state_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_VideoStateSrv_Request_activate_video
{
public:
  Init_VideoStateSrv_Request_activate_video()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::VideoStateSrv_Request activate_video(::deepracer_interfaces_pkg::srv::VideoStateSrv_Request::_activate_video_type arg)
  {
    msg_.activate_video = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::VideoStateSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::VideoStateSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_VideoStateSrv_Request_activate_video();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_VideoStateSrv_Response_error
{
public:
  Init_VideoStateSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::VideoStateSrv_Response error(::deepracer_interfaces_pkg::srv::VideoStateSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::VideoStateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::VideoStateSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_VideoStateSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__VIDEO_STATE_SRV__BUILDER_HPP_
