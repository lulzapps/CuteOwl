#pragma once
#include <QQuickWidget>

namespace owl
{

class ServerPanel : public QQuickWidget
{

Q_OBJECT

public:
    ServerPanel(QWidget* parent = nullptr);
    virtual ~ServerPanel() = default;

};

} // namespace owl
