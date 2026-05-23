# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/SetStatusLedBlinkSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetStatusLedBlinkSrv_Request(type):
    """Metaclass of message 'SetStatusLedBlinkSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.SetStatusLedBlinkSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_status_led_blink_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_status_led_blink_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_status_led_blink_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_status_led_blink_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_status_led_blink_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetStatusLedBlinkSrv_Request(metaclass=Metaclass_SetStatusLedBlinkSrv_Request):
    """Message class 'SetStatusLedBlinkSrv_Request'."""

    __slots__ = [
        '_led_index',
        '_color1',
        '_color2',
        '_delay',
    ]

    _fields_and_field_types = {
        'led_index': 'int32',
        'color1': 'string',
        'color2': 'string',
        'delay': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.led_index = kwargs.get('led_index', int())
        self.color1 = kwargs.get('color1', str())
        self.color2 = kwargs.get('color2', str())
        self.delay = kwargs.get('delay', float())

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
        if self.led_index != other.led_index:
            return False
        if self.color1 != other.color1:
            return False
        if self.color2 != other.color2:
            return False
        if self.delay != other.delay:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def led_index(self):
        """Message field 'led_index'."""
        return self._led_index

    @led_index.setter
    def led_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led_index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'led_index' field must be an integer in [-2147483648, 2147483647]"
        self._led_index = value

    @property
    def color1(self):
        """Message field 'color1'."""
        return self._color1

    @color1.setter
    def color1(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'color1' field must be of type 'str'"
        self._color1 = value

    @property
    def color2(self):
        """Message field 'color2'."""
        return self._color2

    @color2.setter
    def color2(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'color2' field must be of type 'str'"
        self._color2 = value

    @property
    def delay(self):
        """Message field 'delay'."""
        return self._delay

    @delay.setter
    def delay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delay' field must be of type 'float'"
        self._delay = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SetStatusLedBlinkSrv_Response(type):
    """Metaclass of message 'SetStatusLedBlinkSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.SetStatusLedBlinkSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_status_led_blink_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_status_led_blink_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_status_led_blink_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_status_led_blink_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_status_led_blink_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetStatusLedBlinkSrv_Response(metaclass=Metaclass_SetStatusLedBlinkSrv_Response):
    """Message class 'SetStatusLedBlinkSrv_Response'."""

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


class Metaclass_SetStatusLedBlinkSrv(type):
    """Metaclass of service 'SetStatusLedBlinkSrv'."""

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
                'deepracer_interfaces_pkg.srv.SetStatusLedBlinkSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_status_led_blink_srv

            from deepracer_interfaces_pkg.srv import _set_status_led_blink_srv
            if _set_status_led_blink_srv.Metaclass_SetStatusLedBlinkSrv_Request._TYPE_SUPPORT is None:
                _set_status_led_blink_srv.Metaclass_SetStatusLedBlinkSrv_Request.__import_type_support__()
            if _set_status_led_blink_srv.Metaclass_SetStatusLedBlinkSrv_Response._TYPE_SUPPORT is None:
                _set_status_led_blink_srv.Metaclass_SetStatusLedBlinkSrv_Response.__import_type_support__()


class SetStatusLedBlinkSrv(metaclass=Metaclass_SetStatusLedBlinkSrv):
    from deepracer_interfaces_pkg.srv._set_status_led_blink_srv import SetStatusLedBlinkSrv_Request as Request
    from deepracer_interfaces_pkg.srv._set_status_led_blink_srv import SetStatusLedBlinkSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
