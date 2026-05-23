// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__struct.hpp"
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

void CameraMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) deepracer_interfaces_pkg::msg::CameraMsg(_init);
}

void CameraMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<deepracer_interfaces_pkg::msg::CameraMsg *>(message_memory);
  typed_message->~CameraMsg();
}

size_t size_function__CameraMsg__images(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__CameraMsg__images(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__CameraMsg__images(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void resize_function__CameraMsg__images(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CameraMsg_message_member_array[1] = {
  {
    "images",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::CameraMsg, images),  // bytes offset in struct
    nullptr,  // default value
    size_function__CameraMsg__images,  // size() function pointer
    get_const_function__CameraMsg__images,  // get_const(index) function pointer
    get_function__CameraMsg__images,  // get(index) function pointer
    resize_function__CameraMsg__images  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CameraMsg_message_members = {
  "deepracer_interfaces_pkg::msg",  // message namespace
  "CameraMsg",  // message name
  1,  // number of fields
  sizeof(deepracer_interfaces_pkg::msg::CameraMsg),
  CameraMsg_message_member_array,  // message members
  CameraMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CameraMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CameraMsg_message_members,
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
get_message_type_support_handle<deepracer_interfaces_pkg::msg::CameraMsg>()
{
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::CameraMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, deepracer_interfaces_pkg, msg, CameraMsg)() {
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::CameraMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
