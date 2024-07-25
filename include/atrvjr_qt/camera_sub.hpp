#ifndef CAMERA_SUB
#define CAMERA_SUB

#include "rclcpp/rclcpp.hpp"
#include "ros_image_to_qimage/ros_image_to_qimage.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <QImage>
#include <QLabel>
#include <QMainWindow>

class CameraSubscriber : public rclcpp::Node{
 private:
   rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber;
   void image_callback(const sensor_msgs::msg::Image::SharedPtr msg){
      label->setPixmap(QPixmap::fromImage(ros_image_to_qimage::Convert(*msg)));
   }
   QLabel* label;
 public:
   CameraSubscriber(const char* name, QRect layout, QMainWindow* window) : Node(name), label(new QLabel(window)){
      subscriber = this->create_subscription<sensor_msgs::msg::Image>(
         "/image_raw", 
         10, 
         std::bind(
            &CameraSubscriber::image_callback,
            this, 
            std::placeholders::_1
         )
      );

      label->move(layout.x(), layout.y());
      label->resize(layout.width(), layout.height());
      label->show();
   }

   ~CameraSubscriber(){ delete label; }
};

#endif