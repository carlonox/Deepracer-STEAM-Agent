// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/camera_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_CameraMsg_images
{
public:
  Init_CameraMsg_images()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::msg::CameraMsg images(::deepracer_interfaces_pkg::msg::CameraMsg::_images_type arg)
  {
    msg_.images = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::CameraMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::CameraMsg>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_CameraMsg_images();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__BUILDER_HPP_
