// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from deepracer_interfaces_pkg:srv/ActiveStateSrv.idl
// generated code does not contain a copyright notice
#include "deepracer_interfaces_pkg/srv/detail/active_state_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // state
  return true;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // state
}

deepracer_interfaces_pkg__srv__ActiveStateSrv_Request *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__create()
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Request *)malloc(sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request));
  bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * msg)
{
  if (msg) {
    deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini(msg);
  }
  free(msg);
}


bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * data = NULL;
  if (size) {
    data = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Request *)calloc(size, sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__create(size_t size)
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence *)malloc(sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence * array)
{
  if (array) {
    deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence__fini(array);
  }
  free(array);
}


bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // error
  return true;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // error
}

deepracer_interfaces_pkg__srv__ActiveStateSrv_Response *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__create()
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Response *)malloc(sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response));
  bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * msg)
{
  if (msg) {
    deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini(msg);
  }
  free(msg);
}


bool
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__init(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * data = NULL;
  if (size) {
    data = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Response *)calloc(size, sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__fini(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence *
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__create(size_t size)
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array = (deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence *)malloc(sizeof(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__destroy(deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence * array)
{
  if (array) {
    deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence__fini(array);
  }
  free(array);
}
