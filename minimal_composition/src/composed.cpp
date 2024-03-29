#include <memory>
#include "../include/publisher_node.hpp"
#include "../include/subscriber_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;
  auto publisher_node = std::make_shared<PublisherNode>(options);
  auto subscriber_node = std::make_shared<SubscriberNode>(options);
  exec.add_node(publisher_node);
  exec.add_node(subscriber_node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
