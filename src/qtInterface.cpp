#include <iostream>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>
#include <QPushButton>
#include <QWidget>
#include "rclcpp/rclcpp.hpp"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QWidget window;

    window.resize(1000, 1000);
    window.setWindowTitle(QApplication::translate(
        "JuniorWindow", "Junior Window"));

    QPushButton button(QApplication::translate(
        "JuniorWindow", "Button"), &window);
    button.resize(256, 64);
    button.move((window.size().width() - button.size().width())/2, 900);
    button.show();

    QCamera camera;
    QCameraViewfinder vf(&window);
    vf.resize(800, 600);
    vf.move((window.size().width() - vf.size().width())/2, (window.size().height() - vf.size().height())/2);

    vf.show();
    camera.setViewfinder(&vf);
    camera.start();

    window.show();

    return app.exec();
}