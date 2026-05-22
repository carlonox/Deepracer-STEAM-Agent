# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/BeginSoftwareUpdateSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BeginSoftwareUpdateSrv_Request(type):
    """Metaclass of message 'BeginSoftwareUpdateSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.BeginSoftwareUpdateSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__begin_software_update_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__begin_software_update_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__begin_software_update_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__begin_software_update_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__begin_software_update_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BeginSoftwareUpdateSrv_Request(metaclass=Metaclass_BeginSoftwareUpdateSrv_Request):
    """Message class 'BeginSoftwareUpdateSrv_Request'."""

    __slots__ = [
        '_sleep_time_before_reboot',
    ]

    _fields_and_field_types = {
        'sleep_time_before_reboot': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sleep_time_before_reboot = kwargs.get('sleep_time_before_reboot', int())

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
        if self.sleep_time_before_reboot != other.sleep_time_before_reboot:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def sleep_time_before_reboot(self):
        """Message field 'sleep_time_before_reboot'."""
        return self._sleep_time_before_reboot

    @sleep_time_before_reboot.setter
    def sleep_time_before_reboot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sleep_time_before_reboot' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'sleep_time_before_reboot' field must be an integer in [-2147483648, 2147483647]"
        self._sleep_time_before_reboot = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_BeginSoftwareUpdateSrv_Response(type):
    """Metaclass of message 'BeginSoftwareUpdateSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.BeginSoftwareUpdateSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__begin_software_update_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__begin_software_update_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__begin_software_update_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__begin_software_update_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__begin_software_update_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BeginSoftwareUpdateSrv_Response(metaclass=Metaclass_BeginSoftwareUpdateSrv_Response):
    """Message class 'BeginSoftwareUpdateSrv_Response'."""

    __slots__ = [
        '_response_status',
    ]

    _fields_and_field_types = {
        'response_status': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.response_status = kwargs.get('response_status', bool())

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
        if self.response_status != other.response_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def response_status(self):
        """Message field 'response_status'."""
        return self._response_status

    @response_status.setter
    def response_status(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'response_status' field must be of type 'bool'"
        self._response_status = value


class Metaclass_BeginSoftwareUpdateSrv(type):
    """Metaclass of service 'BeginSoftwareUpdateSrv'."""

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
                'deepracer_interfaces_pkg.srv.BeginSoftwareUpdateSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__begin_software_update_srv

            from deepracer_interfaces_pkg.srv import _begin_software_update_srv
            if _begin_software_update_srv.Metaclass_BeginSoftwareUpdateSrv_Request._TYPE_SUPPORT is None:
                _begin_software_update_srv.Metaclass_BeginSoftwareUpdateSrv_Request.__import_type_support__()
            if _begin_software_update_srv.Metaclass_BeginSoftwareUpdateSrv_Response._TYPE_SUPPORT is None:
                _begin_software_update_srv.Metaclass_BeginSoftwareUpdateSrv_Response.__import_type_support__()


class BeginSoftwareUpdateSrv(metaclass=Metaclass_BeginSoftwareUpdateSrv):
    from deepracer_interfaces_pkg.srv._begin_software_update_srv import BeginSoftwareUpdateSrv_Request as Request
    from deepracer_interfaces_pkg.srv._begin_software_update_srv import BeginSoftwareUpdateSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
