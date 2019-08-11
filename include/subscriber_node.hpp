#ifndef MINIMAL_COMPOSITION__SUBSCRIBER_NODE_HPP_
#define MINIMAL_COMPOSITION__SUBSCRIBER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visibility.h"

class SubscriberNode : public rclcpp::Node
{
public:
  MINIMAL_COMPOSITION_PUBLIC SubscriberNode(rclcpp::NodeOptions options);

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif  // MINIMAL_COMPOSITION__SUBSCRIBER_NODE_HPP_
