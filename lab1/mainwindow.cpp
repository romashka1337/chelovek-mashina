#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "ui_auth.h"
#include "QFileDialog"
#include <QTextDocumentWriter>

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}

void MainWindow::slotOpen()
{
    QString filename = QFileDialog::getOpenFileName(0, "Open file", QDir::currentPath(), "*.cpp *.txt");
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->textEdit->setPlainText(file.readAll());
}

void MainWindow::slotSave()
{
    QString filename = QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(), "*.cpp *.txt");
    QTextDocumentWriter writer;
    writer.setFileName(filename);
    writer.write(ui->textEdit->document());
}

void MainWindow::slotClear()
{
    ui->textEdit->clear();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAuthors, SIGNAL(triggered()), this, SLOT(About_Lab1()));

    QAction* pactOpen = new QAction("file open action", 0);
    pactOpen->setText("&Open");
    pactOpen->setShortcut(QKeySequence("CTRL+S"));
    pactOpen->setToolTip("Open document");
    pactOpen->setStatusTip("Open file");
    pactOpen->setWhatsThis("Open file");;
    pactOpen->setIcon(QPixmap("HugFRGS.jpeg"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));
    QMenu* pmnuFile = new QMenu("&File");
    pmnuFile->addAction(pactOpen);
    menuBar()->addMenu(pmnuFile);

    QAction* pactSave = new QAction("file save action", 0);
    pactSave->setText("&Save");
    pactSave->setShortcut(QKeySequence("CTRL+D"));
    pactSave->setToolTip("Save document");
    pactSave->setStatusTip("Save file");
    pactSave->setWhatsThis("Save file");;
    pactSave->setIcon(QPixmap("HugFRGS.jpeg"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));
    pmnuFile->addAction(pactSave);

    QAction* pactClear = new QAction("file clear action", 0);
    pactClear->setText("&Clear");
    pactClear->setShortcut(QKeySequence("CTRL+C"));
    pactClear->setToolTip("Clear document");
    pactClear->setStatusTip("Clear file");
    pactClear->setWhatsThis("Clear file");;
    pactClear->setIcon(QPixmap("HugFRGS.jpeg"));
    connect(pactClear, SIGNAL(triggered()), SLOT(slotClear()));
    pmnuFile->addAction(pactClear);

    ui->mainToolBar->addAction(pactOpen);
    ui->mainToolBar->addAction(pactSave);
    ui->mainToolBar->addAction(pactClear);
}

MainWindow::~MainWindow()
{
    delete ui;
}
