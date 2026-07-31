// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from deepracer_interfaces_pkg:msg/USBFileSystemNotificationMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "deepracer_interfaces_pkg/msg/detail/usb_file_system_notification_msg__struct.hpp"
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

void USBFileSystemNotificationMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg(_init);
}

void USBFileSystemNotificationMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg *>(message_memory);
  typed_message->~USBFileSystemNotificationMsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember USBFileSystemNotificationMsg_message_member_array[4] = {
  {
    "path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg, path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "file_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg, file_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "callback_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg, callback_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "node_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg, node_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers USBFileSystemNotificationMsg_message_members = {
  "deepracer_interfaces_pkg::msg",  // message namespace
  "USBFileSystemNotificationMsg",  // message name
  4,  // number of fields
  sizeof(deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg),
  USBFileSystemNotificationMsg_message_member_array,  // message members
  USBFileSystemNotificationMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  USBFileSystemNotificationMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t USBFileSystemNotificationMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &USBFileSystemNotificationMsg_message_members,
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
get_message_type_support_handle<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg>()
{
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::USBFileSystemNotificationMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, deepracer_interfaces_pkg, msg, USBFileSystemNotificationMsg)() {
  return &::deepracer_interfaces_pkg::msg::rosidl_typesupport_introspection_cpp::USBFileSystemNotificationMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
