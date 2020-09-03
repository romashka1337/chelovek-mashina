#include "mainwindow_maslov.h"
#include "maslov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_Maslov w;
    w.show();

    return a.exec();
}
