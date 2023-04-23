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
    owl::OwlApplication app(argc, &argv);

    // owl::AppWindow appwindow;
    // appwindow.setSource(QUrl("qrc:/qml/main.qml"));
    // "qrc:/qml/serverPanel.qml"

    QQmlApplicationEngine engine("qrc:/qml/main.qml");
//    appwindow.show();
//    engine.show();

    return app.exec();


    // int retval = 0;

    // try
    // {
    //     owl::OwlApplication app(argc, &argv);

    //     owl::SplashScreen splash(QPixmap{":/images/splash-bg.png"});
    //     splash.show();
    //     app.processEvents();

    //     owl::MainWindow window;

    //     // finish the splash screen
    //     splash.finish(&window);

    //     // show the main window
    //     window.show();
    //     retval = app.exec();
    // }
    // catch (const std::exception& ex)
    // {
    //     std::cerr
    //         << "There was an unrecoverable error: "
    //         << ex.what()
    //         << std::endl;

    //     retval = 1;
    // }
    // catch(...)
    // {
    //     std::cerr << "There was an unknown error" << std::endl;
    // }

    // return retval;
}
