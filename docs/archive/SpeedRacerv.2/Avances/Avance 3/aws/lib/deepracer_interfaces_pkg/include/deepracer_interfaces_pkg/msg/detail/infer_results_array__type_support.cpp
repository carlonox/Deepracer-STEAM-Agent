// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from deepracer_interfaces_pkg:msg/InferResultsArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "deepracer_interfaces_pkg/msg/detail/infer_results_array__struct.hpp"
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

void InferResultsArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) deepracer_interfaces_pkg::msg::InferResultsArray(_init);
}

void InferResultsArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<deepracer_interfaces_pkg::msg::InferResultsArray *>(message_memory);
  typed_message->~InferResultsArray();
}

size_t size_function__InferResultsArray__results(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<deepracer_interfaces_pkg::msg::InferResults> *>(untyped_member);
  return member->size();
}

const void * get_const_function__InferResultsArray__results(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<deepracer_interfaces_pkg::msg::InferResults> *>(untyped_member);
  return &member[index];
}

void * get_function__InferResultsArray__results(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<deepracer_interfaces_pkg::msg::InferResults> *>(untyped_member);
  return &member[index];
}

void resize_function__InferResultsArray__results(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<deepracer_interfaces_pkg::msg::InferResults> *>(untyped_member);
  member->resize(size);
}

size_t size_function__InferResultsArray__images(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__InferResultsArray__images(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__InferResultsArray__images(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void resize_function__InferResultsArray__images(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember InferResultsArray_message_member_array[2] = {
  {
    "results",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<deepracer_interfaces_pkg::msg::InferResults>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::InferResultsArray, results),  // bytes offset in struct
    nullptr,  // default value
    size_function__InferResultsArray__results,  // size() function pointer
    get_const_function__InferResultsArray__results,  // get_const(index) function pointer
    get_function__InferResultsArray__results,  // get(index) function pointer
    resize_function__InferResultsArray__results  // resize(index) function pointer
  },
  {
    "images",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::InferResultsArray, images),  // bytes offset in struct
    nullptr,  // default value
    size_function__InferResultsArray__images,  // size() function pointer
    get_const_function__InferResultsArray__images,  // get_const(index) function pointer
    get_function__InferResultsArray__images,  // get(index) function pointer
    resize_function__InferResultsArray__images  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers InferResultsArray_message_members = {
  "deepracer_interfaces_pkg::msg",  // message namespace
  "InferResultsArray",  // message name
  2,  // number of fields
  sizeof(deepracer_interfaces_pkg::msg::InferResultsArray),
  InferResultsArray_message_member_array,  // message members
  InferResultsArray_init_function,  // function to initialize message memory (memory has to be allocated)
  InferResultsArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t InferResultsArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &InferResultsArray_message_members,
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
get_message_type_support_handle<deepracer_interfaces_pkg::msg::InferResultsArray>()
{
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::InferResultsArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, deepracer_interfaces_pkg, msg, InferResultsArray)() {
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::InferResultsArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
