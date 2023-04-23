#include <QAbstractListModel>
#include <QQmlContext>
#include <QQuickItem>

#include <QLayout>
#include <QQuickView>

#include "ServerPanel.h"

namespace owl
{

ServerPanel::ServerPanel(QWidget* parent/* = nullptr*/)
    : QWidget(parent)
{
    //setFocusPolicy(Qt::TabFocus);
    //setResizeMode(QQuickWidget::SizeRootObjectToView);

    //ServerObjectModel model;
    //model.addServerObject(ServerObject("one", "cone"));
    //model.addServerObject(ServerObject("two", "ctwo"));

    //this->setProperty({ "model", QVariant::fromValue(&model) });
    ////QQmlContext* root = rootContext();
    ////root = this->rootContext();
    ////root->setContextProperty("model", QVariant::fromValue(&model));
    //setSource(QUrl("qrc:/qml/serverPanel.qml"));

//    auto view = new QQuickView();
//    view->setSource(QUrl("qrc:/qml/serverPanel.qml"));
//    auto container = QWidget::createWindowContainer(view, this->parentWidget());

//    auto parentw = this->parentWidget();
//    auto layout = parentw->layout();
//    layout->addWidget(container);
    //this->parentWidget()->layout()->addWidget(container);
}

} // namespace owl
