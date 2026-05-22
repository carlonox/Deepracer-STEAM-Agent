# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/LoadModelSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LoadModelSrv_Request(type):
    """Metaclass of message 'LoadModelSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.LoadModelSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__load_model_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__load_model_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__load_model_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__load_model_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__load_model_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadModelSrv_Request(metaclass=Metaclass_LoadModelSrv_Request):
    """Message class 'LoadModelSrv_Request'."""

    __slots__ = [
        '_artifact_path',
        '_task_type',
        '_pre_process_type',
        '_action_space_type',
    ]

    _fields_and_field_types = {
        'artifact_path': 'string',
        'task_type': 'int8',
        'pre_process_type': 'int8',
        'action_space_type': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.artifact_path = kwargs.get('artifact_path', str())
        self.task_type = kwargs.get('task_type', int())
        self.pre_process_type = kwargs.get('pre_process_type', int())
        self.action_space_type = kwargs.get('action_space_type', int())

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
        if self.artifact_path != other.artifact_path:
            return False
        if self.task_type != other.task_type:
            return False
        if self.pre_process_type != other.pre_process_type:
            return False
        if self.action_space_type != other.action_space_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def artifact_path(self):
        """Message field 'artifact_path'."""
        return self._artifact_path

    @artifact_path.setter
    def artifact_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'artifact_path' field must be of type 'str'"
        self._artifact_path = value

    @property
    def task_type(self):
        """Message field 'task_type'."""
        return self._task_type

    @task_type.setter
    def task_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'task_type' field must be an integer in [-128, 127]"
        self._task_type = value

    @property
    def pre_process_type(self):
        """Message field 'pre_process_type'."""
        return self._pre_process_type

    @pre_process_type.setter
    def pre_process_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pre_process_type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'pre_process_type' field must be an integer in [-128, 127]"
        self._pre_process_type = value

    @property
    def action_space_type(self):
        """Message field 'action_space_type'."""
        return self._action_space_type

    @action_space_type.setter
    def action_space_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_space_type' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'action_space_type' field must be an integer in [-128, 127]"
        self._action_space_type = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_LoadModelSrv_Response(type):
    """Metaclass of message 'LoadModelSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.LoadModelSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__load_model_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__load_model_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__load_model_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__load_model_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__load_model_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LoadModelSrv_Response(metaclass=Metaclass_LoadModelSrv_Response):
    """Message class 'LoadModelSrv_Response'."""

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


class Metaclass_LoadModelSrv(type):
    """Metaclass of service 'LoadModelSrv'."""

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
                'deepracer_interfaces_pkg.srv.LoadModelSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__load_model_srv

            from deepracer_interfaces_pkg.srv import _load_model_srv
            if _load_model_srv.Metaclass_LoadModelSrv_Request._TYPE_SUPPORT is None:
                _load_model_srv.Metaclass_LoadModelSrv_Request.__import_type_support__()
            if _load_model_srv.Metaclass_LoadModelSrv_Response._TYPE_SUPPORT is None:
                _load_model_srv.Metaclass_LoadModelSrv_Response.__import_type_support__()


class LoadModelSrv(metaclass=Metaclass_LoadModelSrv):
    from deepracer_interfaces_pkg.srv._load_model_srv import LoadModelSrv_Request as Request
    from deepracer_interfaces_pkg.srv._load_model_srv import LoadModelSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
