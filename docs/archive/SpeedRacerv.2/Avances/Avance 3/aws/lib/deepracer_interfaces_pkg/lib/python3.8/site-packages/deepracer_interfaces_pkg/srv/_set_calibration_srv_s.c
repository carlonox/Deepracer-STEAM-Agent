// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from deepracer_interfaces_pkg:srv/SetCalibrationSrv.idl
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
#include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__struct.h"
#include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool deepracer_interfaces_pkg__srv__set_calibration_srv__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[76];
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
    assert(strncmp("deepracer_interfaces_pkg.srv._set_calibration_srv.SetCalibrationSrv_Request", full_classname_dest, 75) == 0);
  }
  deepracer_interfaces_pkg__srv__SetCalibrationSrv_Request * ros_message = _ros_message;
  {  // cal_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "cal_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cal_type = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // max
    PyObject * field = PyObject_GetAttrString(_pymsg, "max");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // mid
    PyObject * field = PyObject_GetAttrString(_pymsg, "mid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mid = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // min
    PyObject * field = PyObject_GetAttrString(_pymsg, "min");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // polarity
    PyObject * field = PyObject_GetAttrString(_pymsg, "polarity");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->polarity = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * deepracer_interfaces_pkg__srv__set_calibration_srv__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetCalibrationSrv_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("deepracer_interfaces_pkg.srv._set_calibration_srv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetCalibrationSrv_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  deepracer_interfaces_pkg__srv__SetCalibrationSrv_Request * ros_message = (deepracer_interfaces_pkg__srv__SetCalibrationSrv_Request *)raw_ros_message;
  {  // cal_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cal_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cal_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mid
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // polarity
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->polarity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "polarity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__struct.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/set_calibration_srv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool deepracer_interfaces_pkg__srv__set_calibration_srv__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[77];
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
    assert(strncmp("deepracer_interfaces_pkg.srv._set_calibration_srv.SetCalibrationSrv_Response", full_classname_dest, 76) == 0);
  }
  deepracer_interfaces_pkg__srv__SetCalibrationSrv_Response * ros_message = _ros_message;
  {  // error
    PyObject * field = PyObject_GetAttrString(_pymsg, "error");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->error = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * deepracer_interfaces_pkg__srv__set_calibration_srv__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetCalibrationSrv_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("deepracer_interfaces_pkg.srv._set_calibration_srv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetCalibrationSrv_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  deepracer_interfaces_pkg__srv__SetCalibrationSrv_Response * ros_message = (deepracer_interfaces_pkg__srv__SetCalibrationSrv_Response *)raw_ros_message;
  {  // error
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
