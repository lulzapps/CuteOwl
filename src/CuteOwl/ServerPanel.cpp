#include "ServerPanel.h"

namespace owl
{

ServerPanel::ServerPanel(QWidget* parent/* = nullptr*/)
    : QQuickWidget(parent)
{

    setFocusPolicy(Qt::TabFocus);
    setResizeMode(QQuickWidget::SizeRootObjectToView);

    setSource(QUrl("qrc:/qml/serverPanel.qml"));
}

} // namespace owl
