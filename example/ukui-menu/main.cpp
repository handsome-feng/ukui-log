#include "mainwindow.h"
#include "../../common/log.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    auto log = Log::getInstance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    delete log;
}
