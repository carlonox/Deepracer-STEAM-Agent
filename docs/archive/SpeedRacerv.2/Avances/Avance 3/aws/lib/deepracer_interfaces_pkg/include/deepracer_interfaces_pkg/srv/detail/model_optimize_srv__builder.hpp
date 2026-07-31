// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/ModelOptimizeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ModelOptimizeSrv_Request_platform
{
public:
  explicit Init_ModelOptimizeSrv_Request_platform(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request platform(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_platform_type arg)
  {
    msg_.platform = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_lidar_channels
{
public:
  explicit Init_ModelOptimizeSrv_Request_lidar_channels(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_platform lidar_channels(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_lidar_channels_type arg)
  {
    msg_.lidar_channels = std::move(arg);
    return Init_ModelOptimizeSrv_Request_platform(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_num_channels
{
public:
  explicit Init_ModelOptimizeSrv_Request_num_channels(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_lidar_channels num_channels(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_num_channels_type arg)
  {
    msg_.num_channels = std::move(arg);
    return Init_ModelOptimizeSrv_Request_lidar_channels(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_height
{
public:
  explicit Init_ModelOptimizeSrv_Request_height(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_num_channels height(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ModelOptimizeSrv_Request_num_channels(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_width
{
public:
  explicit Init_ModelOptimizeSrv_Request_width(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_height width(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ModelOptimizeSrv_Request_height(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_img_format
{
public:
  explicit Init_ModelOptimizeSrv_Request_img_format(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_width img_format(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_img_format_type arg)
  {
    msg_.img_format = std::move(arg);
    return Init_ModelOptimizeSrv_Request_width(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_training_algorithm
{
public:
  explicit Init_ModelOptimizeSrv_Request_training_algorithm(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_img_format training_algorithm(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_training_algorithm_type arg)
  {
    msg_.training_algorithm = std::move(arg);
    return Init_ModelOptimizeSrv_Request_img_format(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_model_metadata_sensors
{
public:
  explicit Init_ModelOptimizeSrv_Request_model_metadata_sensors(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_ModelOptimizeSrv_Request_training_algorithm model_metadata_sensors(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_model_metadata_sensors_type arg)
  {
    msg_.model_metadata_sensors = std::move(arg);
    return Init_ModelOptimizeSrv_Request_training_algorithm(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

class Init_ModelOptimizeSrv_Request_model_name
{
public:
  Init_ModelOptimizeSrv_Request_model_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModelOptimizeSrv_Request_model_metadata_sensors model_name(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request::_model_name_type arg)
  {
    msg_.model_name = std::move(arg);
    return Init_ModelOptimizeSrv_Request_model_metadata_sensors(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ModelOptimizeSrv_Request_model_name();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_ModelOptimizeSrv_Response_error
{
public:
  explicit Init_ModelOptimizeSrv_Response_error(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response error(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response msg_;
};

class Init_ModelOptimizeSrv_Response_artifact_path
{
public:
  Init_ModelOptimizeSrv_Response_artifact_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModelOptimizeSrv_Response_error artifact_path(::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response::_artifact_path_type arg)
  {
    msg_.artifact_path = std::move(arg);
    return Init_ModelOptimizeSrv_Response_error(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_ModelOptimizeSrv_Response_artifact_path();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__BUILDER_HPP_
