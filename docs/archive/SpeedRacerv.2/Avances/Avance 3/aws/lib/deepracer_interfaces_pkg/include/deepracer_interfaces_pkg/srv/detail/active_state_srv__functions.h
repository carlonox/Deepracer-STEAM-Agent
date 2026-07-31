// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from deepracer_interfaces_pkg:srv/ActiveStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__FUNCTIONS_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "deepracer_interfaces_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "deepracer_interfaces_pkg/srv/detail/active_state_srv__struct.h"

/// Initialize srv/ActiveStateSrv message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request
 * )) before or use
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg);

/// Finalize srv/ActiveStateSrv message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg);

/// Create srv/ActiveStateSrv message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__create();

/// Destroy srv/ActiveStateSrv message.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg);


/// Initialize array of srv/ActiveStateSrv messages.
/**
 * It allocates the memory for the number of elements and calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array, size_t size);

/// Finalize array of srv/ActiveStateSrv messages.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array);

/// Create array of srv/ActiveStateSrv messages.
/**
 * It allocates the memory for the array and calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__create(size_t size);

/// Destroy array of srv/ActiveStateSrv messages.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array);

/// Initialize srv/ActiveStateSrv message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response
 * )) before or use
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg);

/// Finalize srv/ActiveStateSrv message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg);

/// Create srv/ActiveStateSrv message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__create();

/// Destroy srv/ActiveStateSrv message.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg);


/// Initialize array of srv/ActiveStateSrv messages.
/**
 * It allocates the memory for the number of elements and calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array, size_t size);

/// Finalize array of srv/ActiveStateSrv messages.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array);

/// Create array of srv/ActiveStateSrv messages.
/**
 * It allocates the memory for the array and calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__create(size_t size);

/// Destroy array of srv/ActiveStateSrv messages.
/**
 * It calls
 * deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_deepracer_interfaces_pkg
void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__FUNCTIONS_H_
