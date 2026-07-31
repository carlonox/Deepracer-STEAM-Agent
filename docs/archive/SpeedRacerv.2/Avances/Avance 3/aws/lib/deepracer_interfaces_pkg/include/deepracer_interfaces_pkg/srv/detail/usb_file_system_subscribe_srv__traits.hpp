// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/USBFileSystemSubscribeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/usb_file_system_subscribe_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/USBFileSystemSubscribeSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/USBFileSystemSubscribeSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv>()
{
  return "deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv>()
{
  return "deepracer_interfaces_pkg/srv/USBFileSystemSubscribeSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__TRAITS_HPP_
