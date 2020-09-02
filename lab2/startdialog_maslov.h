#ifndef STARTDIALOG_MASLOV_H
#define STARTDIALOG_MASLOV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_maslov.h"

class StartDialog_Maslov : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Maslov(QWidget* pwgt = 0) : QPushButton("Push", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        InputDialog_Maslov* pInputDialog = new InputDialog_Maslov;
        if (pInputDialog->exec() == QDialog::Accepted)
        {
            QMessageBox::information(0,
                                     "Your info: ",
                                     "Name: "
                                     + pInputDialog->firstName()
                                     + "\nLast name: "
                                     + pInputDialog->lastName()
                                     );
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_MASLOV_H
