#include "docwindow_maslov.h"

DocWindow_Maslov::DocWindow_Maslov(QWidget* pwgt) : QTextEdit(pwgt)
{

}

void DocWindow_Maslov::slotLoad()
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
        setPlainText(stream.readAll());
        file.close();
        m_strFileName = str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindow_Maslov::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName();
    if (not str.isEmpty())
    {
        m_strFileName = str;
        slotSave();
    }
}

void DocWindow_Maslov::slotSave()
{
    if (m_strFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }
    QFile file(m_strFileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(0, "Status", "Success");
    }
}
