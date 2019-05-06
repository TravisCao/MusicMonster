#include "mainwindow.h"
#include "ui_mainwindowForm.h"
#include "ui_newdialogForm.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>
#include <QString>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    uiMainWindow(new Ui::MainWindow)
{
    uiMainWindow->setupUi(this);
    modelInit();
    actionInit();
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
}

void MainWindow::newFile()
{
    qDebug() << "new";
}
void MainWindow::openFile()
{
    qDebug() << "open";
}

void MainWindow::about()
{
    qDebug() << "about";
}

void MainWindow::saveFile()
{
    qDebug() << "save";
}

void MainWindow::modelInit()
{
    fileModel = new QStandardItemModel(10, 6);
    fileModel->setHorizontalHeaderLabels(QStringList() << "Name:" << "Duration" << "Sample Rates" << "Channels" << "Bit Depth" << "Source Format");

    uiMainWindow->tableView->setModel(fileModel);

    for (int i = 0; i < 10; ++i) {
        uiMainWindow->tableView->setRowHeight(i,10);
    }

    uiMainWindow->tableView->setShowGrid(false);


    effectModel = new QStandardItemModel(20,1);
    uiMainWindow->listView_1->setModel(effectModel);

    for (int i = 0; i < 20; ++i) {
        QStandardItem *item = new QStandardItem();
        effectModel->appendRow(item);
    }

    historyModel = new QStandardItemModel(20,1);
    uiMainWindow->listView_2->setModel(historyModel);

    for (int i = 0; i < 20; ++i) {
        QStandardItem *item = new QStandardItem();
        historyModel->appendRow(item);
    }


}

void MainWindow::actionInit()
{
    connect(uiMainWindow->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(uiMainWindow->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(uiMainWindow->actionAbout_Music_Mosnter, SIGNAL(triggered()), this, SLOT(about()));
    connect(uiMainWindow->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
}


