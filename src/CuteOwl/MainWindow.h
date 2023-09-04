#pragma once
#include <QtGui>

#include <QQuickView>
#include <QQmlEngine>

#include <QQmlApplicationEngine>

#include "ui_MainWindow.h"

namespace Ui
{  
	class MainWindow;
}

namespace owl
{

class AppWindow : public QQmlApplicationEngine
{
    Q_OBJECT

public:
//    using QQmlApplicationEngine::QQmlApplicationEngine;
    explicit AppWindow(const QUrl &url);
//    explicit App

protected:
    void closeEvent(QCloseEvent* event);

private:
    void quitApplication();
};

//class AppWindow : public QQuickView
//{
//    Q_OBJECT
//    QML_ELEMENT
//    QML_UNCREATABLE("AppWindow is not creatable from QML")

//public:
//    explicit AppWindow();
//    ~AppWindow();
//};

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent* event);

private:
    void loadMenus();

    void loadSettings();
    void writeSettings();

};

} // namespace
