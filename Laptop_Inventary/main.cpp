#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    window.resize(420, 500);
    window.show();

    return a.exec();
}
