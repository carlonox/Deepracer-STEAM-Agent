# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/GetCalibrationSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetCalibrationSrv_Request(type):
    """Metaclass of message 'GetCalibrationSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.GetCalibrationSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_calibration_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_calibration_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_calibration_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_calibration_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_calibration_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetCalibrationSrv_Request(metaclass=Metaclass_GetCalibrationSrv_Request):
    """Message class 'GetCalibrationSrv_Request'."""

    __slots__ = [
        '_cal_type',
    ]

    _fields_and_field_types = {
        'cal_type': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cal_type = kwargs.get('cal_type', int())

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
        if self.cal_type != other.cal_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def cal_type(self):
        """Message field 'cal_type'."""
        return self._cal_type

    @cal_type.setter
    def cal_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cal_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'cal_type' field must be an integer in [-2147483648, 2147483647]"
        self._cal_type = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GetCalibrationSrv_Response(type):
    """Metaclass of message 'GetCalibrationSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.GetCalibrationSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_calibration_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_calibration_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_calibration_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_calibration_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_calibration_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetCalibrationSrv_Response(metaclass=Metaclass_GetCalibrationSrv_Response):
    """Message class 'GetCalibrationSrv_Response'."""

    __slots__ = [
        '_max',
        '_mid',
        '_min',
        '_polarity',
        '_error',
    ]

    _fields_and_field_types = {
        'max': 'int32',
        'mid': 'int32',
        'min': 'int32',
        'polarity': 'int32',
        'error': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.max = kwargs.get('max', int())
        self.mid = kwargs.get('mid', int())
        self.min = kwargs.get('min', int())
        self.polarity = kwargs.get('polarity', int())
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
        if self.max != other.max:
            return False
        if self.mid != other.mid:
            return False
        if self.min != other.min:
            return False
        if self.polarity != other.polarity:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property  # noqa: A003
    def max(self):  # noqa: A003
        """Message field 'max'."""
        return self._max

    @max.setter  # noqa: A003
    def max(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max' field must be an integer in [-2147483648, 2147483647]"
        self._max = value

    @property
    def mid(self):
        """Message field 'mid'."""
        return self._mid

    @mid.setter
    def mid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mid' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mid' field must be an integer in [-2147483648, 2147483647]"
        self._mid = value

    @property  # noqa: A003
    def min(self):  # noqa: A003
        """Message field 'min'."""
        return self._min

    @min.setter  # noqa: A003
    def min(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'min' field must be an integer in [-2147483648, 2147483647]"
        self._min = value

    @property
    def polarity(self):
        """Message field 'polarity'."""
        return self._polarity

    @polarity.setter
    def polarity(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'polarity' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'polarity' field must be an integer in [-2147483648, 2147483647]"
        self._polarity = value

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


class Metaclass_GetCalibrationSrv(type):
    """Metaclass of service 'GetCalibrationSrv'."""

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
                'deepracer_interfaces_pkg.srv.GetCalibrationSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_calibration_srv

            from deepracer_interfaces_pkg.srv import _get_calibration_srv
            if _get_calibration_srv.Metaclass_GetCalibrationSrv_Request._TYPE_SUPPORT is None:
                _get_calibration_srv.Metaclass_GetCalibrationSrv_Request.__import_type_support__()
            if _get_calibration_srv.Metaclass_GetCalibrationSrv_Response._TYPE_SUPPORT is None:
                _get_calibration_srv.Metaclass_GetCalibrationSrv_Response.__import_type_support__()


class GetCalibrationSrv(metaclass=Metaclass_GetCalibrationSrv):
    from deepracer_interfaces_pkg.srv._get_calibration_srv import GetCalibrationSrv_Request as Request
    from deepracer_interfaces_pkg.srv._get_calibration_srv import GetCalibrationSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
