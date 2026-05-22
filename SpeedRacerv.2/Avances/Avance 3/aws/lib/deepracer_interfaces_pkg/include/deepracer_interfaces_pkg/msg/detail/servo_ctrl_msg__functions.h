// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__FUNCTIONS_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "deepracer_interfaces_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "deepracer_interfaces_pkg/msg/detail/servo_ctrl_msg__struct.h"

/// Initialize msg/ServoCtrlMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg
 * )) before or use
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__msg__ServoCtrlMsg__init(deepracer_interfaces_pkg__msg__ServoCtrlMsg * msg);

/// Finalize msg/ServoCtrlMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__msg__ServoCtrlMsg__fini(deepracer_interfaces_pkg__msg__ServoCtrlMsg * msg);

/// Create msg/ServoCtrlMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__msg__ServoCtrlMsg *
deepracer_interfaces_pkg__msg__ServoCtrlMsg__create();

/// Destroy msg/ServoCtrlMsg message.
/**
 * It calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__msg__ServoCtrlMsg__destroy(deepracer_interfaces_pkg__msg__ServoCtrlMsg * msg);


/// Initialize array of msg/ServoCtrlMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__init(deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence * array, size_t size);

/// Finalize array of msg/ServoCtrlMsg messages.
/**
 * It calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__fini(deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence * array);

/// Create array of msg/ServoCtrlMsg messages.
/**
 * It allocates the memory for the array and calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence *
deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__create(size_t size);

/// Destroy array of msg/ServoCtrlMsg messages.
/**
 * It calls
 * deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence__destroy(deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__FUNCTIONS_H_
