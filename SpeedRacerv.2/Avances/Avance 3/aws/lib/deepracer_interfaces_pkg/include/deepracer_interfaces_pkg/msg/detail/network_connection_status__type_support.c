// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from deepracer_interfaces_pkg:msg/NetworkConnectionStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "deepracer_interfaces_pkg/msg/detail/network_connection_status__rosidl_typesupport_introspection_c.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "deepracer_interfaces_pkg/msg/detail/network_connection_status__functions.h"
#include "deepracer_interfaces_pkg/msg/detail/network_connection_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__msg__NetworkConnectionStatus__init(message_memory);
}

void NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__msg__NetworkConnectionStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_member_array[1] = {
  {
    "network_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__msg__NetworkConnectionStatus, network_connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_members = {
  "deepracer_interfaces_pkg__msg",  // message namespace
  "NetworkConnectionStatus",  // message name
  1,  // number of fields
  sizeof(deepracer_interfaces_pkg__msg__NetworkConnectionStatus),
  NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_member_array,  // message members
  NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_type_support_handle = {
  0,
  &NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, msg, NetworkConnectionStatus)() {
  if (!NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_type_support_handle.typesupport_identifier) {
    NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NetworkConnectionStatus__rosidl_typesupport_introspection_c__NetworkConnectionStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
