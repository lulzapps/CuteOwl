#include <QUrl>
#include <QMenuBar>

#include "MainWindow.h"

#if defined(Q_OS_MAC)
extern "C" void setupTitleBar(WId winId);
#endif
namespace owl
{

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setupTitleBar(this->winId());

    // create a blank title bar for the post view dock
    // serverPanel->setTitleBarWidget(new QWidget(dockWidget));

    QTimer::singleShot(0, this,
        [this]()
        {
            this->loadSettings();
            this->loadMenus();
        });
}

void MainWindow::loadMenus()
{
    // // File
    // {
    //     dockWidget->setTitleBarWidget(new QWidget(dockWidget));
    // }

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
