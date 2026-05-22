// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from deepracer_interfaces_pkg:srv/LidarConfigSrv.idl
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
#include "deepracer_interfaces_pkg/srv/detail/lidar_config_srv__struct.h"
#include "deepracer_interfaces_pkg/srv/detail/lidar_config_srv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool deepracer_interfaces_pkg__srv__lidar_config_srv__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[70];
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
    assert(strncmp("deepracer_interfaces_pkg.srv._lidar_config_srv.LidarConfigSrv_Request", full_classname_dest, 69) == 0);
  }
  deepracer_interfaces_pkg__srv__LidarConfigSrv_Request * ros_message = _ros_message;
  {  // use_lidar
    PyObject * field = PyObject_GetAttrString(_pymsg, "use_lidar");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->use_lidar = (Py_True == field);
    Py_DECREF(field);
  }
  {  // min_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // num_values
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_values");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_values = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // min_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // clipping_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipping_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->clipping_distance = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // num_sectors
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_sectors");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_sectors = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // preprocess_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "preprocess_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->preprocess_type = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * deepracer_interfaces_pkg__srv__lidar_config_srv__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LidarConfigSrv_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("deepracer_interfaces_pkg.srv._lidar_config_srv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LidarConfigSrv_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  deepracer_interfaces_pkg__srv__LidarConfigSrv_Request * ros_message = (deepracer_interfaces_pkg__srv__LidarConfigSrv_Request *)raw_ros_message;
  {  // use_lidar
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->use_lidar ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "use_lidar", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_values
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->num_values);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_values", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipping_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->clipping_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipping_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // num_sectors
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->num_sectors);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_sectors", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // preprocess_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->preprocess_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "preprocess_type", field);
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
// #include "deepracer_interfaces_pkg/srv/detail/lidar_config_srv__struct.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/lidar_config_srv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool deepracer_interfaces_pkg__srv__lidar_config_srv__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[71];
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
    assert(strncmp("deepracer_interfaces_pkg.srv._lidar_config_srv.LidarConfigSrv_Response", full_classname_dest, 70) == 0);
  }
  deepracer_interfaces_pkg__srv__LidarConfigSrv_Response * ros_message = _ros_message;
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
PyObject * deepracer_interfaces_pkg__srv__lidar_config_srv__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LidarConfigSrv_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("deepracer_interfaces_pkg.srv._lidar_config_srv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LidarConfigSrv_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  deepracer_interfaces_pkg__srv__LidarConfigSrv_Response * ros_message = (deepracer_interfaces_pkg__srv__LidarConfigSrv_Response *)raw_ros_message;
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
