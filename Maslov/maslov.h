#ifndef MASLOV_H
#define MASLOV_H

#include <QWidget>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDialogButtonBox>

namespace Ui {
class Maslov;
}

class Maslov : public QWidget
{
    Q_OBJECT

public:
    explicit Maslov(QWidget *parent = 0);
    ~Maslov();

private:
    Ui::Maslov *ui;

public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // MASLOV_H
