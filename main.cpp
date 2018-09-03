#include "ScoreboardMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScoreboardMainWindow w;
    w.show();

    return a.exec();
}
