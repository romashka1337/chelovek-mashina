#ifndef DOCWINDOW_MASLOV_H
#define DOCWINDOW_MASLOV_H

#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>

class DocWindow_Maslov : public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindow_Maslov(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};

#endif // DOCWINDOW_MASLOV_H
