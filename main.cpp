
#include "BSB_MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BSB_MainWindow w;
    w.show();

    return a.exec();
}
