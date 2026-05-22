// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__struct.h"
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "sensor_msgs/msg/detail/image__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool deepracer_interfaces_pkg__msg__camera_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("deepracer_interfaces_pkg.msg._camera_msg.CameraMsg", full_classname_dest, 50) == 0);
  }
  deepracer_interfaces_pkg__msg__CameraMsg * ros_message = _ros_message;
  {  // images
    PyObject * field = PyObject_GetAttrString(_pymsg, "images");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'images'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!sensor_msgs__msg__Image__Sequence__init(&(ros_message->images), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create sensor_msgs__msg__Image__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    sensor_msgs__msg__Image * dest = ros_message->images.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!sensor_msgs__msg__image__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * deepracer_interfaces_pkg__msg__camera_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CameraMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("deepracer_interfaces_pkg.msg._camera_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CameraMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  deepracer_interfaces_pkg__msg__CameraMsg * ros_message = (deepracer_interfaces_pkg__msg__CameraMsg *)raw_ros_message;
  {  // images
    PyObject * field = NULL;
    size_t size = ros_message->images.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    sensor_msgs__msg__Image * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->images.data[i]);
      PyObject * pyitem = sensor_msgs__msg__image__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "images", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
