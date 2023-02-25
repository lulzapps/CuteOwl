#pragma once
#include <QtGui>
#include "ui_MainWindow.h"

namespace Ui
{  
	class MainWindow;
}

namespace owl
{

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
