# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/SoftwareUpdateStateSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SoftwareUpdateStateSrv_Request(type):
    """Metaclass of message 'SoftwareUpdateStateSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateStateSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__software_update_state_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__software_update_state_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__software_update_state_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__software_update_state_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__software_update_state_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SoftwareUpdateStateSrv_Request(metaclass=Metaclass_SoftwareUpdateStateSrv_Request):
    """Message class 'SoftwareUpdateStateSrv_Request'."""

    __slots__ = [
        '_request',
    ]

    _fields_and_field_types = {
        'request': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.request = kwargs.get('request', bool())

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
        if self.request != other.request:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'request' field must be of type 'bool'"
        self._request = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SoftwareUpdateStateSrv_Response(type):
    """Metaclass of message 'SoftwareUpdateStateSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateStateSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__software_update_state_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__software_update_state_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__software_update_state_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__software_update_state_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__software_update_state_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SoftwareUpdateStateSrv_Response(metaclass=Metaclass_SoftwareUpdateStateSrv_Response):
    """Message class 'SoftwareUpdateStateSrv_Response'."""

    __slots__ = [
        '_update_state',
    ]

    _fields_and_field_types = {
        'update_state': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.update_state = kwargs.get('update_state', int())

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
        if self.update_state != other.update_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def update_state(self):
        """Message field 'update_state'."""
        return self._update_state

    @update_state.setter
    def update_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'update_state' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'update_state' field must be an integer in [-2147483648, 2147483647]"
        self._update_state = value


class Metaclass_SoftwareUpdateStateSrv(type):
    """Metaclass of service 'SoftwareUpdateStateSrv'."""

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
                'deepracer_interfaces_pkg.srv.SoftwareUpdateStateSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__software_update_state_srv

            from deepracer_interfaces_pkg.srv import _software_update_state_srv
            if _software_update_state_srv.Metaclass_SoftwareUpdateStateSrv_Request._TYPE_SUPPORT is None:
                _software_update_state_srv.Metaclass_SoftwareUpdateStateSrv_Request.__import_type_support__()
            if _software_update_state_srv.Metaclass_SoftwareUpdateStateSrv_Response._TYPE_SUPPORT is None:
                _software_update_state_srv.Metaclass_SoftwareUpdateStateSrv_Response.__import_type_support__()


class SoftwareUpdateStateSrv(metaclass=Metaclass_SoftwareUpdateStateSrv):
    from deepracer_interfaces_pkg.srv._software_update_state_srv import SoftwareUpdateStateSrv_Request as Request
    from deepracer_interfaces_pkg.srv._software_update_state_srv import SoftwareUpdateStateSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
