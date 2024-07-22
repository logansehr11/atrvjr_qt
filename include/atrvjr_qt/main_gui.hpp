#pragma once

#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QApplication>

#include "atrvjr_qt/button_pub.hpp"

class MainGUI : public QMainWindow {
    //Q_OBJECT
 
    void process_click();

    const std::shared_ptr<InterfaceNode> pubNode;
    QWidget window;
    QPushButton* button;

 public: 
    MainGUI(const std::shared_ptr<InterfaceNode>& initPubNode);
    ~MainGUI();
};