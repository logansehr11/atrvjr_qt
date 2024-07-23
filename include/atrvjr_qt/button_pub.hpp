#ifndef BUTTON_PUB
#define BUTTON_PUB

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ButtonPublisher : public rclcpp::Node {
 private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;

 public:
    ButtonPublisher();
    void publishMsg(const std::string msg);
};

#endif