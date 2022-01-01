#include <QLabel>

#include "SplashScreen.h"
#include "Core.h"

namespace owl
{

SplashScreen::SplashScreen(const QPixmap & pixmap)
    : QSplashScreen(pixmap),
      _bDoCheck(true)
{
    QLabel* label = new QLabel(this);
    label->move(10, this->size().height() - 17);
    label->setText("version " OWL_VERSION);
    label->show();
}

} // namespace owl
