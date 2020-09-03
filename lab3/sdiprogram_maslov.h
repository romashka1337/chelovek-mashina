#ifndef SDIPROGRAM_MASLOV_H
#define SDIPROGRAM_MASLOV_H

#include <QMainWindow>
#include <QtWidgets>
#include "docwindow_maslov.h"

class SDIProgram_Maslov : public QMainWindow
{
    Q_OBJECT

private:
    DocWindow_Maslov* pdoc;
public:
    SDIProgram_Maslov(QWidget *pwgt = 0) : QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        QMenu* pmnuColor = new QMenu("&Color");
        pdoc = new DocWindow_Maslov;
        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O")
                            );
        pmnuFile->addAction("&Save",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );
        pmnuFile->addAction("&Save as...",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+SHIFT+S")
                            );
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit",
                            qApp,
                            SLOT(quit()),
                            QKeySequence("CTRL+Q")
                            );
        pmnuHelp->addAction("&Help",
                            this,
                            SLOT(slotAbout()),
                            QKeySequence(Qt::Key_F1)
                            );
        pmnuColor->addAction("&Color");
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        menuBar()->addMenu(pmnuColor);
        setCentralWidget(pdoc);
        connect(pmnuColor,
                SIGNAL(triggered(QAction*)),
                this,
                SLOT(slotColor())
                );
        connect(pdoc,
                SIGNAL(changeWindowTitle(const QString&)),
                SLOT(slotChangeWindowTitle(const QString&))
                );
        statusBar()->showMessage("Ready", 2000);
    }
public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Maslov Roman EP-815");
    }
    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
    void slotColor()
    {
        QColor color = QColorDialog::getColor(Qt::black);
        pdoc->setTextColor(color);
//        return color;
    }
};

#endif // SDIPROGRAM_MASLOV_H
