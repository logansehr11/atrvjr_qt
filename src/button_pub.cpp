#include "atrvjr_qt/button_pub.hpp"

ButtonPublisher::ButtonPublisher() : Node("Button_Node"){
    publisher = this->create_publisher<std_msgs::msg::String>("string_msg_topic", 10);
}

void ButtonPublisher::publishMsg(const std::string msg){
    std_msgs::msg::String m;
    m.data = msg;
    publisher->publish(m);
}