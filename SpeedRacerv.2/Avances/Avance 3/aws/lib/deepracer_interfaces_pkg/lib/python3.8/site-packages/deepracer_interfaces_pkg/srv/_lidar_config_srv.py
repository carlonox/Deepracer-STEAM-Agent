# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/LidarConfigSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LidarConfigSrv_Request(type):
    """Metaclass of message 'LidarConfigSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.LidarConfigSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__lidar_config_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__lidar_config_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__lidar_config_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__lidar_config_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__lidar_config_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LidarConfigSrv_Request(metaclass=Metaclass_LidarConfigSrv_Request):
    """Message class 'LidarConfigSrv_Request'."""

    __slots__ = [
        '_use_lidar',
        '_min_angle',
        '_max_angle',
        '_num_values',
        '_min_distance',
        '_max_distance',
        '_clipping_distance',
        '_num_sectors',
        '_preprocess_type',
    ]

    _fields_and_field_types = {
        'use_lidar': 'boolean',
        'min_angle': 'float',
        'max_angle': 'float',
        'num_values': 'int32',
        'min_distance': 'float',
        'max_distance': 'float',
        'clipping_distance': 'float',
        'num_sectors': 'int32',
        'preprocess_type': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.use_lidar = kwargs.get('use_lidar', bool())
        self.min_angle = kwargs.get('min_angle', float())
        self.max_angle = kwargs.get('max_angle', float())
        self.num_values = kwargs.get('num_values', int())
        self.min_distance = kwargs.get('min_distance', float())
        self.max_distance = kwargs.get('max_distance', float())
        self.clipping_distance = kwargs.get('clipping_distance', float())
        self.num_sectors = kwargs.get('num_sectors', int())
        self.preprocess_type = kwargs.get('preprocess_type', int())

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
        if self.use_lidar != other.use_lidar:
            return False
        if self.min_angle != other.min_angle:
            return False
        if self.max_angle != other.max_angle:
            return False
        if self.num_values != other.num_values:
            return False
        if self.min_distance != other.min_distance:
            return False
        if self.max_distance != other.max_distance:
            return False
        if self.clipping_distance != other.clipping_distance:
            return False
        if self.num_sectors != other.num_sectors:
            return False
        if self.preprocess_type != other.preprocess_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def use_lidar(self):
        """Message field 'use_lidar'."""
        return self._use_lidar

    @use_lidar.setter
    def use_lidar(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'use_lidar' field must be of type 'bool'"
        self._use_lidar = value

    @property
    def min_angle(self):
        """Message field 'min_angle'."""
        return self._min_angle

    @min_angle.setter
    def min_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_angle' field must be of type 'float'"
        self._min_angle = value

    @property
    def max_angle(self):
        """Message field 'max_angle'."""
        return self._max_angle

    @max_angle.setter
    def max_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_angle' field must be of type 'float'"
        self._max_angle = value

    @property
    def num_values(self):
        """Message field 'num_values'."""
        return self._num_values

    @num_values.setter
    def num_values(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_values' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_values' field must be an integer in [-2147483648, 2147483647]"
        self._num_values = value

    @property
    def min_distance(self):
        """Message field 'min_distance'."""
        return self._min_distance

    @min_distance.setter
    def min_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_distance' field must be of type 'float'"
        self._min_distance = value

    @property
    def max_distance(self):
        """Message field 'max_distance'."""
        return self._max_distance

    @max_distance.setter
    def max_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_distance' field must be of type 'float'"
        self._max_distance = value

    @property
    def clipping_distance(self):
        """Message field 'clipping_distance'."""
        return self._clipping_distance

    @clipping_distance.setter
    def clipping_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'clipping_distance' field must be of type 'float'"
        self._clipping_distance = value

    @property
    def num_sectors(self):
        """Message field 'num_sectors'."""
        return self._num_sectors

    @num_sectors.setter
    def num_sectors(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_sectors' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_sectors' field must be an integer in [-2147483648, 2147483647]"
        self._num_sectors = value

    @property
    def preprocess_type(self):
        """Message field 'preprocess_type'."""
        return self._preprocess_type

    @preprocess_type.setter
    def preprocess_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'preprocess_type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'preprocess_type' field must be an integer in [-128, 127]"
        self._preprocess_type = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_LidarConfigSrv_Response(type):
    """Metaclass of message 'LidarConfigSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.LidarConfigSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__lidar_config_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__lidar_config_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__lidar_config_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__lidar_config_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__lidar_config_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LidarConfigSrv_Response(metaclass=Metaclass_LidarConfigSrv_Response):
    """Message class 'LidarConfigSrv_Response'."""

    __slots__ = [
        '_error',
    ]

    _fields_and_field_types = {
        'error': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
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
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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


class Metaclass_LidarConfigSrv(type):
    """Metaclass of service 'LidarConfigSrv'."""

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
                'deepracer_interfaces_pkg.srv.LidarConfigSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__lidar_config_srv

            from deepracer_interfaces_pkg.srv import _lidar_config_srv
            if _lidar_config_srv.Metaclass_LidarConfigSrv_Request._TYPE_SUPPORT is None:
                _lidar_config_srv.Metaclass_LidarConfigSrv_Request.__import_type_support__()
            if _lidar_config_srv.Metaclass_LidarConfigSrv_Response._TYPE_SUPPORT is None:
                _lidar_config_srv.Metaclass_LidarConfigSrv_Response.__import_type_support__()


class LidarConfigSrv(metaclass=Metaclass_LidarConfigSrv):
    from deepracer_interfaces_pkg.srv._lidar_config_srv import LidarConfigSrv_Request as Request
    from deepracer_interfaces_pkg.srv._lidar_config_srv import LidarConfigSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
