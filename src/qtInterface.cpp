#include <iostream>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>
#include <QPushButton>
#include "rclcpp/rclcpp.hpp"

class Camera {
    QCamera* camera;
    QCameraViewfinder* viewfinder;
public:
    Camera(): camera(new QCamera), viewfinder(new QCameraViewfinder){
        viewfinder->show();
        camera->setViewfinder(viewfinder);
        camera->start();
    }
    ~Camera(){
        delete camera;
        delete viewfinder;
    }
};

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    Camera c;
    return app.exec();
}