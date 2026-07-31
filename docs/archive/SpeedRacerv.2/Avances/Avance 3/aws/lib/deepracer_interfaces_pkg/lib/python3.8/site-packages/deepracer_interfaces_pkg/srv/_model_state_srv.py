# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:srv/ModelStateSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'model_metadata_sensors'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ModelStateSrv_Request(type):
    """Metaclass of message 'ModelStateSrv_Request'."""

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
                'deepracer_interfaces_pkg.srv.ModelStateSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__model_state_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__model_state_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__model_state_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__model_state_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__model_state_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ModelStateSrv_Request(metaclass=Metaclass_ModelStateSrv_Request):
    """Message class 'ModelStateSrv_Request'."""

    __slots__ = [
        '_model_name',
        '_model_metadata_sensors',
        '_training_algorithm',
        '_action_space_type',
        '_img_format',
        '_width',
        '_height',
        '_num_channels',
        '_lidar_channels',
        '_platform',
        '_task_type',
        '_pre_process_type',
    ]

    _fields_and_field_types = {
        'model_name': 'string',
        'model_metadata_sensors': 'sequence<int32>',
        'training_algorithm': 'int8',
        'action_space_type': 'int8',
        'img_format': 'string',
        'width': 'int32',
        'height': 'int32',
        'num_channels': 'int32',
        'lidar_channels': 'int32',
        'platform': 'int32',
        'task_type': 'int8',
        'pre_process_type': 'int8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.model_name = kwargs.get('model_name', str())
        self.model_metadata_sensors = array.array('i', kwargs.get('model_metadata_sensors', []))
        self.training_algorithm = kwargs.get('training_algorithm', int())
        self.action_space_type = kwargs.get('action_space_type', int())
        self.img_format = kwargs.get('img_format', str())
        self.width = kwargs.get('width', int())
        self.height = kwargs.get('height', int())
        self.num_channels = kwargs.get('num_channels', int())
        self.lidar_channels = kwargs.get('lidar_channels', int())
        self.platform = kwargs.get('platform', int())
        self.task_type = kwargs.get('task_type', int())
        self.pre_process_type = kwargs.get('pre_process_type', int())

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
        if self.model_name != other.model_name:
            return False
        if self.model_metadata_sensors != other.model_metadata_sensors:
            return False
        if self.training_algorithm != other.training_algorithm:
            return False
        if self.action_space_type != other.action_space_type:
            return False
        if self.img_format != other.img_format:
            return False
        if self.width != other.width:
            return False
        if self.height != other.height:
            return False
        if self.num_channels != other.num_channels:
            return False
        if self.lidar_channels != other.lidar_channels:
            return False
        if self.platform != other.platform:
            return False
        if self.task_type != other.task_type:
            return False
        if self.pre_process_type != other.pre_process_type:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def model_name(self):
        """Message field 'model_name'."""
        return self._model_name

    @model_name.setter
    def model_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_name' field must be of type 'str'"
        self._model_name = value

    @property
    def model_metadata_sensors(self):
        """Message field 'model_metadata_sensors'."""
        return self._model_metadata_sensors

    @model_metadata_sensors.setter
    def model_metadata_sensors(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'model_metadata_sensors' array.array() must have the type code of 'i'"
            self._model_metadata_sensors = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'model_metadata_sensors' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._model_metadata_sensors = array.array('i', value)

    @property
    def training_algorithm(self):
        """Message field 'training_algorithm'."""
        return self._training_algorithm

    @training_algorithm.setter
    def training_algorithm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'training_algorithm' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'training_algorithm' field must be an integer in [-128, 127]"
        self._training_algorithm = value

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

    @property
    def img_format(self):
        """Message field 'img_format'."""
        return self._img_format

    @img_format.setter
    def img_format(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'img_format' field must be of type 'str'"
        self._img_format = value

    @property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'width' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'width' field must be an integer in [-2147483648, 2147483647]"
        self._width = value

    @property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'height' field must be an integer in [-2147483648, 2147483647]"
        self._height = value

    @property
    def num_channels(self):
        """Message field 'num_channels'."""
        return self._num_channels

    @num_channels.setter
    def num_channels(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_channels' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_channels' field must be an integer in [-2147483648, 2147483647]"
        self._num_channels = value

    @property
    def lidar_channels(self):
        """Message field 'lidar_channels'."""
        return self._lidar_channels

    @lidar_channels.setter
    def lidar_channels(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lidar_channels' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lidar_channels' field must be an integer in [-2147483648, 2147483647]"
        self._lidar_channels = value

    @property
    def platform(self):
        """Message field 'platform'."""
        return self._platform

    @platform.setter
    def platform(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'platform' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'platform' field must be an integer in [-2147483648, 2147483647]"
        self._platform = value

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


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_ModelStateSrv_Response(type):
    """Metaclass of message 'ModelStateSrv_Response'."""

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
                'deepracer_interfaces_pkg.srv.ModelStateSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__model_state_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__model_state_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__model_state_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__model_state_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__model_state_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ModelStateSrv_Response(metaclass=Metaclass_ModelStateSrv_Response):
    """Message class 'ModelStateSrv_Response'."""

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


class Metaclass_ModelStateSrv(type):
    """Metaclass of service 'ModelStateSrv'."""

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
                'deepracer_interfaces_pkg.srv.ModelStateSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__model_state_srv

            from deepracer_interfaces_pkg.srv import _model_state_srv
            if _model_state_srv.Metaclass_ModelStateSrv_Request._TYPE_SUPPORT is None:
                _model_state_srv.Metaclass_ModelStateSrv_Request.__import_type_support__()
            if _model_state_srv.Metaclass_ModelStateSrv_Response._TYPE_SUPPORT is None:
                _model_state_srv.Metaclass_ModelStateSrv_Response.__import_type_support__()


class ModelStateSrv(metaclass=Metaclass_ModelStateSrv):
    from deepracer_interfaces_pkg.srv._model_state_srv import ModelStateSrv_Request as Request
    from deepracer_interfaces_pkg.srv._model_state_srv import ModelStateSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
