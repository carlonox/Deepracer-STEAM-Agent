// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from deepracer_interfaces_pkg:srv/USBMountPointManagerSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__TRAITS_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__TRAITS_HPP_

#include "deepracer_interfaces_pkg/srv/detail/usb_mount_point_manager_srv__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>()
{
  return "deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>()
{
  return "deepracer_interfaces_pkg/srv/USBMountPointManagerSrv_Request";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>()
{
  return "deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>()
{
  return "deepracer_interfaces_pkg/srv/USBMountPointManagerSrv_Response";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv>()
{
  return "deepracer_interfaces_pkg::srv::USBMountPointManagerSrv";
}

template<>
inline const char * name<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv>()
{
  return "deepracer_interfaces_pkg/srv/USBMountPointManagerSrv";
}

template<>
struct has_fixed_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>::value &&
    has_fixed_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>::value &&
    has_bounded_size<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>::value
  >
{
};

template<>
struct is_service<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv>
  : std::true_type
{
};

template<>
struct is_service_request<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__TRAITS_HPP_
