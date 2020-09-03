#include "mainwindow_maslov.h"
#include "ui_mainwindow_maslov.h"

MainWindow_Maslov::MainWindow_Maslov(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Maslov)
{
    ui->setupUi(this);
    maslov = new Maslov();
//    connect(ui->pushButton_2, SIGNAL(clicked()), maslov, SLOT(show()));
//    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString)), maslov, SLOT(recieveData(QString)));
}

void MainWindow_Maslov::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Select picture", QDir::currentPath(), "*.png *.jpeg");
    ui->lineEdit_4->setText(filename);
    QImage image(filename);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

MainWindow_Maslov::~MainWindow_Maslov()
{
    delete ui;
}

void MainWindow_Maslov::on_pushButton_2_clicked()
{
    QString st = ui->lineEdit_4->text() + "*" + ui->lineEdit->text() + "\n" + ui->lineEdit_2->text() + "\n"
            + ui->dateEdit->text() + "\n" + ui->lineEdit_3->text();
    if (ui->lineEdit_4->text() == "" or ui->lineEdit->text() == "" or
            ui->lineEdit_2->text() == "" or ui->lineEdit_3->text() == "")
    {
        QMessageBox::information(0, "Error", "Incorrect input");
        return;
    }
    if (ui->radioButton->isChecked() == true) st += "\nGender: Male";
    else st += "\nGender: Female";
    emit sendData(st);
    maslov->show();
}
