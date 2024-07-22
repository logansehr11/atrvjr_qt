#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class InterfaceNode : public rclcpp::Node {
 private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;

 public:
    InterfaceNode();
    void publishMsg(const std::string msg);
};