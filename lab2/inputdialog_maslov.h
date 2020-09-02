#ifndef INPUTDIALOG_MASLOV_H
#define INPUTDIALOG_MASLOV_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Maslov : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* m_ptxtFirstName;
    QLineEdit* m_ptxtLastName;
public:
    InputDialog_Maslov(QWidget* pwgt = 0);
    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_MASLOV_H
