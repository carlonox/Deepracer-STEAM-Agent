// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/EvoSensorMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/evo_sensor_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_EvoSensorMsg_lidar_data
{
public:
  explicit Init_EvoSensorMsg_lidar_data(::deepracer_interfaces_pkg::msg::EvoSensorMsg & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::EvoSensorMsg lidar_data(::deepracer_interfaces_pkg::msg::EvoSensorMsg::_lidar_data_type arg)
  {
    msg_.lidar_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::EvoSensorMsg msg_;
};

class Init_EvoSensorMsg_images
{
public:
  Init_EvoSensorMsg_images()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EvoSensorMsg_lidar_data images(::deepracer_interfaces_pkg::msg::EvoSensorMsg::_images_type arg)
  {
    msg_.images = std::move(arg);
    return Init_EvoSensorMsg_lidar_data(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::EvoSensorMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::EvoSensorMsg>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_EvoSensorMsg_images();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__BUILDER_HPP_
