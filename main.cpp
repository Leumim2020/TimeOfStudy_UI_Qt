#include "form1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    form1 w;
    w.show();
    return a.exec();

}
