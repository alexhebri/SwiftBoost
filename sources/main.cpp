#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    //setWindowTitle("Titlu");
    w.show();
    return a.exec();
}

//Welcome to SwiftBoost — your system, your rules.
