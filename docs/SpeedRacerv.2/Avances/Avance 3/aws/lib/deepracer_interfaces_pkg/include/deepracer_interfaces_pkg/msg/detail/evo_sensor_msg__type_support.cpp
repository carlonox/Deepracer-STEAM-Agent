// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from deepracer_interfaces_pkg:msg/EvoSensorMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "deepracer_interfaces_pkg/msg/detail/evo_sensor_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void EvoSensorMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) deepracer_interfaces_pkg::msg::EvoSensorMsg(_init);
}

void EvoSensorMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<deepracer_interfaces_pkg::msg::EvoSensorMsg *>(message_memory);
  typed_message->~EvoSensorMsg();
}

size_t size_function__EvoSensorMsg__images(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EvoSensorMsg__images(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__EvoSensorMsg__images(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void resize_function__EvoSensorMsg__images(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

size_t size_function__EvoSensorMsg__lidar_data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__EvoSensorMsg__lidar_data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__EvoSensorMsg__lidar_data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__EvoSensorMsg__lidar_data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EvoSensorMsg_message_member_array[2] = {
  {
    "images",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::EvoSensorMsg, images),  // bytes offset in struct
    nullptr,  // default value
    size_function__EvoSensorMsg__images,  // size() function pointer
    get_const_function__EvoSensorMsg__images,  // get_const(index) function pointer
    get_function__EvoSensorMsg__images,  // get(index) function pointer
    resize_function__EvoSensorMsg__images  // resize(index) function pointer
  },
  {
    "lidar_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::EvoSensorMsg, lidar_data),  // bytes offset in struct
    nullptr,  // default value
    size_function__EvoSensorMsg__lidar_data,  // size() function pointer
    get_const_function__EvoSensorMsg__lidar_data,  // get_const(index) function pointer
    get_function__EvoSensorMsg__lidar_data,  // get(index) function pointer
    resize_function__EvoSensorMsg__lidar_data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EvoSensorMsg_message_members = {
  "deepracer_interfaces_pkg::msg",  // message namespace
  "EvoSensorMsg",  // message name
  2,  // number of fields
  sizeof(deepracer_interfaces_pkg::msg::EvoSensorMsg),
  EvoSensorMsg_message_member_array,  // message members
  EvoSensorMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  EvoSensorMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EvoSensorMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EvoSensorMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace deepracer_interfaces_pkg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<deepracer_interfaces_pkg::msg::EvoSensorMsg>()
{
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::EvoSensorMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, deepracer_interfaces_pkg, msg, EvoSensorMsg)() {
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::EvoSensorMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
