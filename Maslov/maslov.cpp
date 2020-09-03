#include "maslov.h"
#include "ui_maslov.h"

Maslov::Maslov(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Maslov)
{
    ui->setupUi(this);
}

Maslov::~Maslov()
{
    delete ui;
}
void Maslov::recieveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(1) + "\n" + lst.at(0));
    if (lst.size() > 1)
    {
        QImage image(lst.at(0));
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
}

void Maslov::on_buttonBox_clicked(QAbstractButton *button)
{
    if ((QPushButton *)button == ui->buttonBox->button(QDialogButtonBox::Reset))
    {
        ui->textEdit->clear();
        ui->label->clear();
    }
    else if ((QPushButton *)button == ui->buttonBox->button(QDialogButtonBox::Save))
    {
        QString str = QFileDialog::getSaveFileName();
        QFile file(str);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream(&file) << ui->textEdit->toPlainText();
            file.close();
            QMessageBox::information(0, "Status", "Success");
        }
    }
    else
    {
        QString str = QFileDialog::getOpenFileName();
        if (str.isEmpty())
        {
            return;
        }
        QFile file(str);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->textEdit->setPlainText(stream.readAll());
            file.close();
            QStringList inf = ui->textEdit->toPlainText().split("\n");
            QImage image(inf.at(5));
            ui->label->setPixmap(QPixmap::fromImage(image));
        }
    }
}
