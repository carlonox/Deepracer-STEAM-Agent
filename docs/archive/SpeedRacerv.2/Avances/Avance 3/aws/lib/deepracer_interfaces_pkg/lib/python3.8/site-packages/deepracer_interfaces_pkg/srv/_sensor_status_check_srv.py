# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/SensorStatusCheckSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SensorStatusCheckSrv_Request(type):
    """Metaclass of message 'SensorStatusCheckSrv_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('deepracer_interfaces_pkg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'deepracer_interfaces_pkg.srv.SensorStatusCheckSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__sensor_status_check_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__sensor_status_check_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__sensor_status_check_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__sensor_status_check_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__sensor_status_check_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SensorStatusCheckSrv_Request(metaclass=Metaclass_SensorStatusCheckSrv_Request):
    """Message class 'SensorStatusCheckSrv_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SensorStatusCheckSrv_Response(type):
    """Metaclass of message 'SensorStatusCheckSrv_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('deepracer_interfaces_pkg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'deepracer_interfaces_pkg.srv.SensorStatusCheckSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__sensor_status_check_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__sensor_status_check_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__sensor_status_check_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__sensor_status_check_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__sensor_status_check_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SensorStatusCheckSrv_Response(metaclass=Metaclass_SensorStatusCheckSrv_Response):
    """Message class 'SensorStatusCheckSrv_Response'."""

    __slots__ = [
        '_lidar_status',
        '_single_camera_status',
        '_stereo_camera_status',
        '_error',
    ]

    _fields_and_field_types = {
        'lidar_status': 'int8',
        'single_camera_status': 'int8',
        'stereo_camera_status': 'int8',
        'error': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.lidar_status = kwargs.get('lidar_status', int())
        self.single_camera_status = kwargs.get('single_camera_status', int())
        self.stereo_camera_status = kwargs.get('stereo_camera_status', int())
        self.error = kwargs.get('error', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.lidar_status != other.lidar_status:
            return False
        if self.single_camera_status != other.single_camera_status:
            return False
        if self.stereo_camera_status != other.stereo_camera_status:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def lidar_status(self):
        """Message field 'lidar_status'."""
        return self._lidar_status

    @lidar_status.setter
    def lidar_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lidar_status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'lidar_status' field must be an integer in [-128, 127]"
        self._lidar_status = value

    @property
    def single_camera_status(self):
        """Message field 'single_camera_status'."""
        return self._single_camera_status

    @single_camera_status.setter
    def single_camera_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'single_camera_status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'single_camera_status' field must be an integer in [-128, 127]"
        self._single_camera_status = value

    @property
    def stereo_camera_status(self):
        """Message field 'stereo_camera_status'."""
        return self._stereo_camera_status

    @stereo_camera_status.setter
    def stereo_camera_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stereo_camera_status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'stereo_camera_status' field must be an integer in [-128, 127]"
        self._stereo_camera_status = value

    @property
    def error(self):
        """Message field 'error'."""
        return self._error

    @error.setter
    def error(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'error' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'error' field must be an integer in [-2147483648, 2147483647]"
        self._error = value


class Metaclass_SensorStatusCheckSrv(type):
    """Metaclass of service 'SensorStatusCheckSrv'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('deepracer_interfaces_pkg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'deepracer_interfaces_pkg.srv.SensorStatusCheckSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__sensor_status_check_srv

            from deepracer_interfaces_pkg.srv import _sensor_status_check_srv
            if _sensor_status_check_srv.Metaclass_SensorStatusCheckSrv_Request._TYPE_SUPPORT is None:
                _sensor_status_check_srv.Metaclass_SensorStatusCheckSrv_Request.__import_type_support__()
            if _sensor_status_check_srv.Metaclass_SensorStatusCheckSrv_Response._TYPE_SUPPORT is None:
                _sensor_status_check_srv.Metaclass_SensorStatusCheckSrv_Response.__import_type_support__()


class SensorStatusCheckSrv(metaclass=Metaclass_SensorStatusCheckSrv):
    from deepracer_interfaces_pkg.srv._sensor_status_check_srv import SensorStatusCheckSrv_Request as Request
    from deepracer_interfaces_pkg.srv._sensor_status_check_srv import SensorStatusCheckSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
