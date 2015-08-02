#include "astatine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("The Outer Space");
    QCoreApplication::setOrganizationDomain("theouter.space");
    QCoreApplication::setApplicationName("astatine");

    astatine w;
    w.show();

    return a.exec();
}
