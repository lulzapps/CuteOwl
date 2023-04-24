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
        owl::OwlApplication app(argc, &argv);
        owl::AppEngine engine("qrc:/qml/main.qml");
        return app.exec();
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
