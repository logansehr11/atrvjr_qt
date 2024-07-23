#pragma once

#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>

#include "atrvjr_qt/button_pub.hpp"

class ATRVJR_GUI : public QMainWindow {
    //Q_OBJECT
 private:
    void process_click();

    const std::shared_ptr<ButtonPublisher> pubNode;
    QWidget* window;
    QPushButton* button;
    QCamera camera;
    QCameraViewfinder* vf;

 public: 
    ATRVJR_GUI(const std::shared_ptr<ButtonPublisher>& initPubNode);
    bool isClosed() { return window->isVisible(); }
    ~ATRVJR_GUI();
};