#include "atrvjr_qt/button_pub.hpp"

InterfaceNode::InterfaceNode() : Node("Interface_Node"){
    publisher = this->create_publisher<std_msgs::msg::String>("string_msg_topic", 10);
}

void InterfaceNode::publishMsg(const std::string msg){
    std_msgs::msg::String m;
    m.data = msg;
    publisher->publish(m);
}