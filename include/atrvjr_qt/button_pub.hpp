#ifndef BUTTON_PUB
#define BUTTON_PUB

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class ButtonPublisher : public rclcpp::Node, public QObject{
 private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
    QPushButton* button;

    void process_click() {
      publishMsg("This is a message from ATRV-JR's Interface!");
    }

 public:
   ButtonPublisher(const char* name, QRect layout, QMainWindow* window) : Node(name){
      publisher = this->create_publisher<std_msgs::msg::String>("string_msg_topic", 10);

      button = new QPushButton(QApplication::translate(
        "ATRV-JR", "Publish"), window);
      button->move(layout.x(), layout.y());
      button->resize(layout.width(), layout.height());
      connect(button, &QPushButton::clicked, this, &ButtonPublisher::process_click);
      button->show();
   }

   void publishMsg(const std::string msg){
      std_msgs::msg::String m;
      m.data = msg;
      publisher->publish(m);
   }

   ~ButtonPublisher() { delete button; }
};

#endif