#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include "../MyLib/MyClass.h"

#include "SplashScreen.h"
#include "MainWindow.h"
 
int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);

    owl::SplashScreen splash(QPixmap{":/images/splash-bg.png"});
    splash.show();
    app.processEvents();

    owl::MainWindow window;

    // finish the splash screen
    splash.finish(&window);

    // show the main window
    window.show();
    return app.exec();


 
//    QWidget widget;
//    widget.resize(640, 480);
//    widget.setWindowTitle("Hello, world!!!");
    
//    QGridLayout *gridLayout = new QGridLayout(&widget);

//    owl::MyClass obj("Hello");
//    QLabel* label = new QLabel(obj.appendIt("library world!!"));

//    QPushButton* btn1 = new QPushButton("Push Me");
//    QObject::connect(btn1, &QPushButton::released, &widget,
//        []()
//        {
//            owl::MainWindow* dialog = new owl::MainWindow();
//            dialog->setModal(true);
//            dialog->setWindowModality(Qt::ApplicationModal);
//            dialog->exec();
//            delete dialog;
//        });

//    label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
//    gridLayout->addWidget(label);
//    gridLayout->addWidget(btn1);
 
//    widget.show();
 
//    return app.exec();
}
