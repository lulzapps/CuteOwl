#include "Core.h"
#include "OwlApplication.h"

namespace owl
{

OwlApplication::OwlApplication(int& argc, char **argv[])
    : QApplication(argc,*argv)
{
}

void OwlApplication::init()
{
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANZATION_DOMAIN);
    QCoreApplication::setApplicationName(APP_NAME);
}

} // namespace owl
