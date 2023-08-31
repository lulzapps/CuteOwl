#include <iostream>
#include <sstream>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include <QQmlApplicationEngine>

#include "../MyLib/MyClass.h"

#include "SplashScreen.h"
#include "MainWindow.h"
#include "OwlApplication.h"
 
int main(int argc, char *argv[]) 
{
    int retval = 0;

    try
    {
        auto app = std::make_unique<owl::OwlApplication>(argc, &argv);
        auto engine = std::make_unique<owl::AppWindow>(QUrl("qrc:/qml/main.qml"));
        retval = app->exec();

        engine.release();
        app.release();
    }
     catch (const std::exception& ex)
     {
         std::cerr
             << "There was an unrecoverable error: "
             << ex.what()
             << std::endl;

         retval = 1;
     }
     catch(...)
     {
         std::cerr << "There was an unknown error" << std::endl;
     }

     return retval;
}
