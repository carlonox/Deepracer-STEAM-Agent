// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/InferResultsArray.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/infer_results_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_InferResultsArray_images
{
public:
  explicit Init_InferResultsArray_images(::deepracer_interfaces_pkg::msg::InferResultsArray & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::InferResultsArray images(::deepracer_interfaces_pkg::msg::InferResultsArray::_images_type arg)
  {
    msg_.images = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResultsArray msg_;
};

class Init_InferResultsArray_results
{
public:
  Init_InferResultsArray_results()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InferResultsArray_images results(::deepracer_interfaces_pkg::msg::InferResultsArray::_results_type arg)
  {
    msg_.results = std::move(arg);
    return Init_InferResultsArray_images(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResultsArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::InferResultsArray>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_InferResultsArray_results();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__BUILDER_HPP_
