//#include "mainwindow.h"
#include "startdialog_maslov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    StartDialog_Maslov startDialog;
    startDialog.show();

    return a.exec();
}
