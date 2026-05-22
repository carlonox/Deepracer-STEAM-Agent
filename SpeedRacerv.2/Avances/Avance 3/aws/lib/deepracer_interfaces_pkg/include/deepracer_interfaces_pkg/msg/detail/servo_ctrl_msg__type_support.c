// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__rosidl_typesupport_introspection_c.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__functions.h"
#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__msg__ServoCtrlMsg__init(message_memory);
}

void ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__msg__ServoCtrlMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_member_array[2] = {
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__msg__ServoCtrlMsg, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "throttle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__msg__ServoCtrlMsg, throttle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_members = {
  "deepracer_interfaces_pkg__msg",  // message namespace
  "ServoCtrlMsg",  // message name
  2,  // number of fields
  sizeof(deepracer_interfaces_pkg__msg__ServoCtrlMsg),
  ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_member_array,  // message members
  ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_type_support_handle = {
  0,
  &ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, msg, ServoCtrlMsg)() {
  if (!ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_type_support_handle.typesupport_identifier) {
    ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ServoCtrlMsg__rosidl_typesupport_introspection_c__ServoCtrlMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
