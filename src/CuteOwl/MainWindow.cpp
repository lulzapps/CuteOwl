#include <QUrl>
#include <QMenuBar>

#include "MainWindow.h"

#if defined(Q_OS_MAC)
extern "C" void setupTitleBar(WId winId);
#endif
namespace owl
{

AppWindow::AppWindow(const QUrl &url)
    : QQmlApplicationEngine(url)
{
    QMenuBar *menuBar = new QMenuBar(nullptr);
    auto editMenu = menuBar->addMenu("Edit");
    auto newBoardAction = editMenu->addAction(tr("New Connection"));
    QObject::connect(newBoardAction, &QAction::triggered, this, &QQmlApplicationEngine::quit);

    auto aboutAction = menuBar->addAction("&About...");
    aboutAction->setMenuRole(QAction::AboutRole);
    QObject::connect(aboutAction, &QAction::triggered, this, &QQmlApplicationEngine::quit);


    auto helpMenu = menuBar->addMenu("Help");
    auto twitterAction = helpMenu->addAction("Twitter");
    QObject::connect(twitterAction, &QAction::triggered, this, &QQmlApplicationEngine::quit);

    auto quitAction = menuBar->addAction("E&xit");
    quitAction->setMenuRole(QAction::QuitRole);
    quitAction->setShortcuts(QKeySequence::Quit);
    QObject::connect(quitAction, &QAction::triggered, this, &QQmlApplicationEngine::quit);

//    auto bobMenu = menuBar->addMenu("BOB");
//    auto mikeAction = helpMenu->addAction("&About...");
//    twitterAction->setMenuRole(QAction::AboutRole);
//    QObject::connect(twitterAction, &QAction::triggered, this, &QQmlApplicationEngine::quit);
}

//AppWindow::AppWindow()
//{
//    QMenuBar *menuBar = new QMenuBar(nullptr);
//    QAction* boob = menuBar->addMenu("TVDAD")->addAction("BOB");
//    QAction *quitAction = menuBar->addMenu("File")->addAction("Quit");
//    QObject::connect(quitAction, &QAction::triggered, this, &QQuickView::close);
//}

//AppWindow::~AppWindow()
//{
    
//}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi(this);

    // create a blank title bar for the post view dock
     leftHandPanel->setTitleBarWidget(new QWidget(leftHandPanel));

    QTimer::singleShot(0, this,
        [this]()
        {
            this->loadSettings();
            this->loadMenus();
        });
}

void MainWindow::loadMenus()
{
     // File
     {
         leftHandPanel->setTitleBarWidget(new QWidget(leftHandPanel));
     }

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
}

void MainWindow::loadSettings()
{
    const QString writePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    const QString iniFile = QDir(writePath).absoluteFilePath("cuteowl.ini");

    if (!QFile(iniFile).exists())
    {
        qDebug() << "no windows settings file found, loading defaults";
        return;
    }

    qDebug() << "loading settings from: " << iniFile;

    QSettings settings(iniFile, QSettings::IniFormat);

    settings.beginGroup("MainWindow");

    const auto geometry = settings.value("geometry").value<QByteArray>();
    this->restoreGeometry(geometry);

    const auto state = settings.value("state").value<QByteArray>();
    this->restoreState(state);

    menuBar()->setVisible(settings.value("showMenuBar").toBool());
}

void MainWindow::writeSettings()
{
    const QString writePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    const QString iniFile = QDir(writePath).absoluteFilePath("cuteowl.ini");

    qDebug() << "savings settings to    : " << iniFile;

    QSettings settings(iniFile, QSettings::IniFormat);

    // write windows settings
    settings.beginGroup("MainWindow");

    settings.setValue("geometry",saveGeometry());
    settings.setValue("state", saveState());
    settings.setValue("showMenuBar", menuBar()->isVisible());
}


} // namespace
