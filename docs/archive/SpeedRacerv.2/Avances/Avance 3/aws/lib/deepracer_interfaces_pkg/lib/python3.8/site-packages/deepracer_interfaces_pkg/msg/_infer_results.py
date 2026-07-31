# generated from rosidl_generator_py/resource/_idl.py.em
# with input from deepracer_interfaces_pkg:msg/InferResults.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_InferResults(type):
    """Metaclass of message 'InferResults'."""

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
                'deepracer_interfaces_pkg.msg.InferResults')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__infer_results
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__infer_results
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__infer_results
            cls._TYPE_SUPPORT = module.type_support_msg__msg__infer_results
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__infer_results

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class InferResults(metaclass=Metaclass_InferResults):
    """Message class 'InferResults'."""

    __slots__ = [
        '_class_label',
        '_class_prob',
        '_x_min',
        '_y_min',
        '_x_max',
        '_y_max',
    ]

    _fields_and_field_types = {
        'class_label': 'int32',
        'class_prob': 'float',
        'x_min': 'float',
        'y_min': 'float',
        'x_max': 'float',
        'y_max': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.class_label = kwargs.get('class_label', int())
        self.class_prob = kwargs.get('class_prob', float())
        self.x_min = kwargs.get('x_min', float())
        self.y_min = kwargs.get('y_min', float())
        self.x_max = kwargs.get('x_max', float())
        self.y_max = kwargs.get('y_max', float())

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
        if self.class_label != other.class_label:
            return False
        if self.class_prob != other.class_prob:
            return False
        if self.x_min != other.x_min:
            return False
        if self.y_min != other.y_min:
            return False
        if self.x_max != other.x_max:
            return False
        if self.y_max != other.y_max:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def class_label(self):
        """Message field 'class_label'."""
        return self._class_label

    @class_label.setter
    def class_label(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_label' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'class_label' field must be an integer in [-2147483648, 2147483647]"
        self._class_label = value

    @property
    def class_prob(self):
        """Message field 'class_prob'."""
        return self._class_prob

    @class_prob.setter
    def class_prob(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'class_prob' field must be of type 'float'"
        self._class_prob = value

    @property
    def x_min(self):
        """Message field 'x_min'."""
        return self._x_min

    @x_min.setter
    def x_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_min' field must be of type 'float'"
        self._x_min = value

    @property
    def y_min(self):
        """Message field 'y_min'."""
        return self._y_min

    @y_min.setter
    def y_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_min' field must be of type 'float'"
        self._y_min = value

    @property
    def x_max(self):
        """Message field 'x_max'."""
        return self._x_max

    @x_max.setter
    def x_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x_max' field must be of type 'float'"
        self._x_max = value

    @property
    def y_max(self):
        """Message field 'y_max'."""
        return self._y_max

    @y_max.setter
    def y_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y_max' field must be of type 'float'"
        self._y_max = value
