# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/NavThrottleSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavThrottleSrv_Request(type):
    """Metaclass of message 'NavThrottleSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.NavThrottleSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__nav_throttle_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__nav_throttle_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__nav_throttle_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__nav_throttle_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__nav_throttle_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavThrottleSrv_Request(metaclass=Metaclass_NavThrottleSrv_Request):
    """Message class 'NavThrottleSrv_Request'."""

    __slots__ = [
        '_throttle',
    ]

    _fields_and_field_types = {
        'throttle': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.throttle = kwargs.get('throttle', float())

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
        if self.throttle != other.throttle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def throttle(self):
        """Message field 'throttle'."""
        return self._throttle

    @throttle.setter
    def throttle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'throttle' field must be of type 'float'"
        self._throttle = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_NavThrottleSrv_Response(type):
    """Metaclass of message 'NavThrottleSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.NavThrottleSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__nav_throttle_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__nav_throttle_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__nav_throttle_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__nav_throttle_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__nav_throttle_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavThrottleSrv_Response(metaclass=Metaclass_NavThrottleSrv_Response):
    """Message class 'NavThrottleSrv_Response'."""

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


class Metaclass_NavThrottleSrv(type):
    """Metaclass of service 'NavThrottleSrv'."""

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
                'deepracer_interfaces_pkg.srv.NavThrottleSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__nav_throttle_srv

            from deepracer_interfaces_pkg.srv import _nav_throttle_srv
            if _nav_throttle_srv.Metaclass_NavThrottleSrv_Request._TYPE_SUPPORT is None:
                _nav_throttle_srv.Metaclass_NavThrottleSrv_Request.__import_type_support__()
            if _nav_throttle_srv.Metaclass_NavThrottleSrv_Response._TYPE_SUPPORT is None:
                _nav_throttle_srv.Metaclass_NavThrottleSrv_Response.__import_type_support__()


class NavThrottleSrv(metaclass=Metaclass_NavThrottleSrv):
    from deepracer_interfaces_pkg.srv._nav_throttle_srv import NavThrottleSrv_Request as Request
    from deepracer_interfaces_pkg.srv._nav_throttle_srv import NavThrottleSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
