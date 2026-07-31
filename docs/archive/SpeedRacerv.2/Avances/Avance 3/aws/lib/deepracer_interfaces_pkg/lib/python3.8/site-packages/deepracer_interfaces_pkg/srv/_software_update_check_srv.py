# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/SoftwareUpdateCheckSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SoftwareUpdateCheckSrv_Request(type):
    """Metaclass of message 'SoftwareUpdateCheckSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateCheckSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__software_update_check_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__software_update_check_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__software_update_check_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__software_update_check_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__software_update_check_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SoftwareUpdateCheckSrv_Request(metaclass=Metaclass_SoftwareUpdateCheckSrv_Request):
    """Message class 'SoftwareUpdateCheckSrv_Request'."""

    __slots__ = [
        '_force_update_check',
    ]

    _fields_and_field_types = {
        'force_update_check': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.force_update_check = kwargs.get('force_update_check', int())

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
        if self.force_update_check != other.force_update_check:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def force_update_check(self):
        """Message field 'force_update_check'."""
        return self._force_update_check

    @force_update_check.setter
    def force_update_check(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'force_update_check' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'force_update_check' field must be an integer in [-2147483648, 2147483647]"
        self._force_update_check = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SoftwareUpdateCheckSrv_Response(type):
    """Metaclass of message 'SoftwareUpdateCheckSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateCheckSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__software_update_check_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__software_update_check_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__software_update_check_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__software_update_check_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__software_update_check_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SoftwareUpdateCheckSrv_Response(metaclass=Metaclass_SoftwareUpdateCheckSrv_Response):
    """Message class 'SoftwareUpdateCheckSrv_Response'."""

    __slots__ = [
        '_software_update_state',
    ]

    _fields_and_field_types = {
        'software_update_state': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.software_update_state = kwargs.get('software_update_state', int())

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
        if self.software_update_state != other.software_update_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def software_update_state(self):
        """Message field 'software_update_state'."""
        return self._software_update_state

    @software_update_state.setter
    def software_update_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'software_update_state' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'software_update_state' field must be an integer in [-2147483648, 2147483647]"
        self._software_update_state = value


class Metaclass_SoftwareUpdateCheckSrv(type):
    """Metaclass of service 'SoftwareUpdateCheckSrv'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateCheckSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__software_update_check_srv

            from deepracer_interfaces_pkg.srv import _software_update_check_srv
            if _software_update_check_srv.Metaclass_SoftwareUpdateCheckSrv_Request._TYPE_SUPPORT is None:
                _software_update_check_srv.Metaclass_SoftwareUpdateCheckSrv_Request.__import_type_support__()
            if _software_update_check_srv.Metaclass_SoftwareUpdateCheckSrv_Response._TYPE_SUPPORT is None:
                _software_update_check_srv.Metaclass_SoftwareUpdateCheckSrv_Response.__import_type_support__()


class SoftwareUpdateCheckSrv(metaclass=Metaclass_SoftwareUpdateCheckSrv):
    from deepracer_interfaces_pkg.srv._software_update_check_srv import SoftwareUpdateCheckSrv_Request as Request
    from deepracer_interfaces_pkg.srv._software_update_check_srv import SoftwareUpdateCheckSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
