// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from deepracer_interfaces_pkg:msg/SoftwareUpdatePctMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "deepracer_interfaces_pkg/msg/detail/software_update_pct_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_deepracer_interfaces_pkg
cdr_serialize(
  const deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_deepracer_interfaces_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_deepracer_interfaces_pkg
get_serialized_size(
  const deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_deepracer_interfaces_pkg
max_serialized_size_SoftwareUpdatePctMsg(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, deepracer_interfaces_pkg, msg, SoftwareUpdatePctMsg)();

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
