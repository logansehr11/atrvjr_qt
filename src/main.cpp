#include <iostream>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>
#include <QObject>
#include <QPushButton>
#include <QQuickItem>
#include <QWidget>
#include "atrvjr_qt/button_pub.hpp"
#include "atrvjr_qt/main_gui.hpp"


static void siginthandler(int sigint)
{
    std::cout << "SIGINT CODE " << sigint << std::endl;
    QApplication::quit();
}

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<ButtonPublisher>();
    auto gui = std::make_shared<ATRVJR_GUI>(node);
    
    app.processEvents();

    rclcpp::executors::MultiThreadedExecutor exec;
    exec.add_node(node);
    while (rclcpp::ok())
    {
        exec.spin_some();
        app.processEvents();
    }
    signal(SIGINT, siginthandler);

    exec.remove_node(node);
    rclcpp::shutdown();
}