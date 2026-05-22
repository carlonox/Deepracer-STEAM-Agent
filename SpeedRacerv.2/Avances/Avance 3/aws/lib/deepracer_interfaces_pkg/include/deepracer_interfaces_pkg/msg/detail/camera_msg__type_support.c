// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__rosidl_typesupport_introspection_c.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__functions.h"
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__struct.h"


// Include directives for member types
// Member `images`
#include "sensor_msgs/msg/image.h"
// Member `images`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__msg__CameraMsg__init(message_memory);
}

void CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__msg__CameraMsg__fini(message_memory);
}

size_t CameraMsg__rosidl_typesupport_introspection_c__size_function__Image__images(
  const void * untyped_member)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return member->size;
}

const void * CameraMsg__rosidl_typesupport_introspection_c__get_const_function__Image__images(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void * CameraMsg__rosidl_typesupport_introspection_c__get_function__Image__images(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

bool CameraMsg__rosidl_typesupport_introspection_c__resize_function__Image__images(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  sensor_msgs__msg__Image__Sequence__fini(member);
  return sensor_msgs__msg__Image__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_member_array[1] = {
  {
    "images",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__msg__CameraMsg, images),  // bytes offset in struct
    NULL,  // default value
    CameraMsg__rosidl_typesupport_introspection_c__size_function__Image__images,  // size() function pointer
    CameraMsg__rosidl_typesupport_introspection_c__get_const_function__Image__images,  // get_const(index) function pointer
    CameraMsg__rosidl_typesupport_introspection_c__get_function__Image__images,  // get(index) function pointer
    CameraMsg__rosidl_typesupport_introspection_c__resize_function__Image__images  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_members = {
  "deepracer_interfaces_pkg__msg",  // message namespace
  "CameraMsg",  // message name
  1,  // number of fields
  sizeof(deepracer_interfaces_pkg__msg__CameraMsg),
  CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_member_array,  // message members
  CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_type_support_handle = {
  0,
  &CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, msg, CameraMsg)() {
  CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_type_support_handle.typesupport_identifier) {
    CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CameraMsg__rosidl_typesupport_introspection_c__CameraMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
