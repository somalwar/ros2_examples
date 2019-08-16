#include <memory>

#include "../include/gnss_state/state_node.hpp"
#include "rclcpp/rclcpp.hpp"


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor exec;
    auto gnss_node = std::make_shared<GnssStateNode>();
    exec.add_node(gnss_node);
    exec.spin();
    rclcpp::shutdown();
    return 0;
}