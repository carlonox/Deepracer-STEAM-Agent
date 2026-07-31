# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/USBFileSystemSubscribeSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_USBFileSystemSubscribeSrv_Request(type):
    """Metaclass of message 'USBFileSystemSubscribeSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.USBFileSystemSubscribeSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__usb_file_system_subscribe_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__usb_file_system_subscribe_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__usb_file_system_subscribe_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__usb_file_system_subscribe_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__usb_file_system_subscribe_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class USBFileSystemSubscribeSrv_Request(metaclass=Metaclass_USBFileSystemSubscribeSrv_Request):
    """Message class 'USBFileSystemSubscribeSrv_Request'."""

    __slots__ = [
        '_file_name',
        '_callback_name',
        '_verify_name_exists',
    ]

    _fields_and_field_types = {
        'file_name': 'string',
        'callback_name': 'string',
        'verify_name_exists': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.file_name = kwargs.get('file_name', str())
        self.callback_name = kwargs.get('callback_name', str())
        self.verify_name_exists = kwargs.get('verify_name_exists', bool())

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
        if self.file_name != other.file_name:
            return False
        if self.callback_name != other.callback_name:
            return False
        if self.verify_name_exists != other.verify_name_exists:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def file_name(self):
        """Message field 'file_name'."""
        return self._file_name

    @file_name.setter
    def file_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'file_name' field must be of type 'str'"
        self._file_name = value

    @property
    def callback_name(self):
        """Message field 'callback_name'."""
        return self._callback_name

    @callback_name.setter
    def callback_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'callback_name' field must be of type 'str'"
        self._callback_name = value

    @property
    def verify_name_exists(self):
        """Message field 'verify_name_exists'."""
        return self._verify_name_exists

    @verify_name_exists.setter
    def verify_name_exists(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'verify_name_exists' field must be of type 'bool'"
        self._verify_name_exists = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_USBFileSystemSubscribeSrv_Response(type):
    """Metaclass of message 'USBFileSystemSubscribeSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.USBFileSystemSubscribeSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__usb_file_system_subscribe_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__usb_file_system_subscribe_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__usb_file_system_subscribe_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__usb_file_system_subscribe_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__usb_file_system_subscribe_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class USBFileSystemSubscribeSrv_Response(metaclass=Metaclass_USBFileSystemSubscribeSrv_Response):
    """Message class 'USBFileSystemSubscribeSrv_Response'."""

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


class Metaclass_USBFileSystemSubscribeSrv(type):
    """Metaclass of service 'USBFileSystemSubscribeSrv'."""

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
                'deepracer_interfaces_pkg.srv.USBFileSystemSubscribeSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__usb_file_system_subscribe_srv

            from deepracer_interfaces_pkg.srv import _usb_file_system_subscribe_srv
            if _usb_file_system_subscribe_srv.Metaclass_USBFileSystemSubscribeSrv_Request._TYPE_SUPPORT is None:
                _usb_file_system_subscribe_srv.Metaclass_USBFileSystemSubscribeSrv_Request.__import_type_support__()
            if _usb_file_system_subscribe_srv.Metaclass_USBFileSystemSubscribeSrv_Response._TYPE_SUPPORT is None:
                _usb_file_system_subscribe_srv.Metaclass_USBFileSystemSubscribeSrv_Response.__import_type_support__()


class USBFileSystemSubscribeSrv(metaclass=Metaclass_USBFileSystemSubscribeSrv):
    from deepracer_interfaces_pkg.srv._usb_file_system_subscribe_srv import USBFileSystemSubscribeSrv_Request as Request
    from deepracer_interfaces_pkg.srv._usb_file_system_subscribe_srv import USBFileSystemSubscribeSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
