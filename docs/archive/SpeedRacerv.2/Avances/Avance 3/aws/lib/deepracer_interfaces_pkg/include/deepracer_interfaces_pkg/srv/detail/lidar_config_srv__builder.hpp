// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/LidarConfigSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/lidar_config_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_LidarConfigSrv_Request_preprocess_type
{
public:
  explicit Init_LidarConfigSrv_Request_preprocess_type(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request preprocess_type(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_preprocess_type_type arg)
  {
    msg_.preprocess_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_num_sectors
{
public:
  explicit Init_LidarConfigSrv_Request_num_sectors(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_preprocess_type num_sectors(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_num_sectors_type arg)
  {
    msg_.num_sectors = std::move(arg);
    return Init_LidarConfigSrv_Request_preprocess_type(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_clipping_distance
{
public:
  explicit Init_LidarConfigSrv_Request_clipping_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_num_sectors clipping_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_clipping_distance_type arg)
  {
    msg_.clipping_distance = std::move(arg);
    return Init_LidarConfigSrv_Request_num_sectors(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_max_distance
{
public:
  explicit Init_LidarConfigSrv_Request_max_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_clipping_distance max_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_max_distance_type arg)
  {
    msg_.max_distance = std::move(arg);
    return Init_LidarConfigSrv_Request_clipping_distance(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_min_distance
{
public:
  explicit Init_LidarConfigSrv_Request_min_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_max_distance min_distance(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_min_distance_type arg)
  {
    msg_.min_distance = std::move(arg);
    return Init_LidarConfigSrv_Request_max_distance(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_num_values
{
public:
  explicit Init_LidarConfigSrv_Request_num_values(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_min_distance num_values(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_num_values_type arg)
  {
    msg_.num_values = std::move(arg);
    return Init_LidarConfigSrv_Request_min_distance(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_max_angle
{
public:
  explicit Init_LidarConfigSrv_Request_max_angle(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_num_values max_angle(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_max_angle_type arg)
  {
    msg_.max_angle = std::move(arg);
    return Init_LidarConfigSrv_Request_num_values(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_min_angle
{
public:
  explicit Init_LidarConfigSrv_Request_min_angle(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request & msg)
  : msg_(msg)
  {}
  Init_LidarConfigSrv_Request_max_angle min_angle(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_min_angle_type arg)
  {
    msg_.min_angle = std::move(arg);
    return Init_LidarConfigSrv_Request_max_angle(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

class Init_LidarConfigSrv_Request_use_lidar
{
public:
  Init_LidarConfigSrv_Request_use_lidar()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarConfigSrv_Request_min_angle use_lidar(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request::_use_lidar_type arg)
  {
    msg_.use_lidar = std::move(arg);
    return Init_LidarConfigSrv_Request_min_angle(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::LidarConfigSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_LidarConfigSrv_Request_use_lidar();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_LidarConfigSrv_Response_error
{
public:
  Init_LidarConfigSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Response error(::deepracer_interfaces_pkg::srv::LidarConfigSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::LidarConfigSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::LidarConfigSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_LidarConfigSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__BUILDER_HPP_
