#ifndef MAINWINDOW_MASLOV_H
#define MAINWINDOW_MASLOV_H

#include <QMainWindow>
#include "maslov.h"
#include <QFileDialog>
#include <QObject>

namespace Ui {
class MainWindow_Maslov;
}

class MainWindow_Maslov : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Maslov(QWidget *parent = 0);
    ~MainWindow_Maslov();

private:
    Ui::MainWindow_Maslov *ui;
    Maslov* maslov;

signals:
    void sendData(QString str);

private slots:
//    void onButtonSend();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_MASLOV_H
