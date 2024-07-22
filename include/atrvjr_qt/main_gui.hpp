#pragma once

#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>

#include "atrvjr_qt/button_pub.hpp"

class MainGUI : public QMainWindow {
    //Q_OBJECT
 private:
    void process_click();

    const std::shared_ptr<InterfaceNode> pubNode;
    QWidget window;
    QPushButton* button;
    QCamera camera;
    QCameraViewfinder* vf;

 public: 
    MainGUI(const std::shared_ptr<InterfaceNode>& initPubNode);
    ~MainGUI();
};