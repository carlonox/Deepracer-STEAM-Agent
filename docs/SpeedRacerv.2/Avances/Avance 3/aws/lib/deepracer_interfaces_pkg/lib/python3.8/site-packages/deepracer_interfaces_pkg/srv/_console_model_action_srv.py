# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/ConsoleModelActionSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConsoleModelActionSrv_Request(type):
    """Metaclass of message 'ConsoleModelActionSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.ConsoleModelActionSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__console_model_action_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__console_model_action_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__console_model_action_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__console_model_action_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__console_model_action_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConsoleModelActionSrv_Request(metaclass=Metaclass_ConsoleModelActionSrv_Request):
    """Message class 'ConsoleModelActionSrv_Request'."""

    __slots__ = [
        '_model_path',
        '_action',
    ]

    _fields_and_field_types = {
        'model_path': 'string',
        'action': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.model_path = kwargs.get('model_path', str())
        self.action = kwargs.get('action', int())

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
        if self.model_path != other.model_path:
            return False
        if self.action != other.action:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def model_path(self):
        """Message field 'model_path'."""
        return self._model_path

    @model_path.setter
    def model_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_path' field must be of type 'str'"
        self._model_path = value

    @property
    def action(self):
        """Message field 'action'."""
        return self._action

    @action.setter
    def action(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'action' field must be an integer in [-2147483648, 2147483647]"
        self._action = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_ConsoleModelActionSrv_Response(type):
    """Metaclass of message 'ConsoleModelActionSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.ConsoleModelActionSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__console_model_action_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__console_model_action_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__console_model_action_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__console_model_action_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__console_model_action_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConsoleModelActionSrv_Response(metaclass=Metaclass_ConsoleModelActionSrv_Response):
    """Message class 'ConsoleModelActionSrv_Response'."""

    __slots__ = [
        '_status',
    ]

    _fields_and_field_types = {
        'status': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', str())

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
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value


class Metaclass_ConsoleModelActionSrv(type):
    """Metaclass of service 'ConsoleModelActionSrv'."""

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
                'deepracer_interfaces_pkg.srv.ConsoleModelActionSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__console_model_action_srv

            from deepracer_interfaces_pkg.srv import _console_model_action_srv
            if _console_model_action_srv.Metaclass_ConsoleModelActionSrv_Request._TYPE_SUPPORT is None:
                _console_model_action_srv.Metaclass_ConsoleModelActionSrv_Request.__import_type_support__()
            if _console_model_action_srv.Metaclass_ConsoleModelActionSrv_Response._TYPE_SUPPORT is None:
                _console_model_action_srv.Metaclass_ConsoleModelActionSrv_Response.__import_type_support__()


class ConsoleModelActionSrv(metaclass=Metaclass_ConsoleModelActionSrv):
    from deepracer_interfaces_pkg.srv._console_model_action_srv import ConsoleModelActionSrv_Request as Request
    from deepracer_interfaces_pkg.srv._console_model_action_srv import ConsoleModelActionSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
