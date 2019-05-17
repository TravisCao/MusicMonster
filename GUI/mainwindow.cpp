#include "mainwindow.h"
#include "newfiledialog.h"
#include "ui_mainwindowForm.h"
#include "audio.h"
#include "changefactor.h"

#include <string>

#include <QStandardItemModel>
#include <QAbstractItemView>
#include <QStandardItem>
#include <QDebug>
#include <QList>
#include <QString>
#include <QAction>
#include <QSound>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QMediaPlayer>
#include <QStringList>
#include <QFileInfo>
#include <QAudioFormat>
#include <QAudioInput>
#include <QHeaderView>

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
    newFileDialog = new NewFileDialog(this);
    newFileDialog->show();
    qDebug() << "new";
}

void MainWindow::changeFactor()
{
    ChangeFactor *change = new ChangeFactor(this);
    change->show();
}

QList<QString> *MainWindow::openFile()
{

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),
                                                     "/home",
                                                     tr("Audios (*.wav *.mp3)"));
    for (int i = 0; i < fileNames.size(); ++i) {
        QString fileName = fileNames.at(i);
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly)) {
            QMessageBox::warning(this, tr("MusicMonster"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(fileName), file.errorString()));
            return &openedFileNames;
        }
        openedFileNames << fileName;
        fileWidget->addItem(fileName);
    }

//    audioInit();

    return &openedFileNames;
}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About MusicMonster"),
             tr("An audio workstation project for CSC3002."));
    qDebug() << "about";
}

void MainWindow::saveFile()
{
    qDebug() << "save";
}

void MainWindow::modelInit()
{
    // the headerview of the tabel to control the size of the section
    QHeaderView *verticalView = new QHeaderView(Qt::Vertical);
    QHeaderView *horizontalView = new QHeaderView(Qt::Horizontal);
    verticalView->setSectionResizeMode(QHeaderView::Fixed);
    verticalView->setDefaultSectionSize(10);
    horizontalView->setSectionResizeMode(QHeaderView::ResizeToContents);
    horizontalView->setMaximumSectionSize(180);
    uiMainWindow->tableView->setVerticalHeader(verticalView);
    uiMainWindow->tableView->setHorizontalHeader(horizontalView);

    uiMainWindow->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    uiMainWindow->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    uiMainWindow->tableView->resizeColumnsToContents();
    uiMainWindow->tableView->setAlternatingRowColors(true);
    uiMainWindow->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    uiMainWindow->tableView->setStyleSheet("QTableView::item { \
                                               height: 10px; \
                                               }");

    fileWidget->modelInit(uiMainWindow->tableView);

    effectModel = new QStandardItemModel(20,1);
    uiMainWindow->effectList->setModel(effectModel);

    historyModel = new QStandardItemModel(20,1);
    uiMainWindow->historyList->setModel(historyModel);

    for (int i = 0; i < 20; ++i) {
        QStandardItem *item = new QStandardItem();
        historyModel->appendRow(item);
    }

}

void MainWindow::audioInit()
{
   uiMainWindow->timeNow->display("00:00:000");
   uiMainWindow->timeTotal->display("00:00");

//   connect(uiMainWindow->timeNow, SIGNAL())

//    connect(uiMainWindow->play, SIGNAL(triggered()), audio, SLOT(playAndPause())); connect(uiMainWindow->stop, SIGNAL(triggered()), audio, SLOT(musicStop()));
//    connect(uiMainWindow->speed, SIGNAL(pressed()), audio , SLOT(musicSpeedUp()));
//    connect(uiMainWindow->speed, SIGNAL(released()), audio, SLOT(musicRecoverSpeed()));
//    connect(uiMainWindow->slow, SIGNAL(pressed()), audio, SLOT(musicSlowDown()));
//    connect(uiMainWindow->slow, SIGNAL(released()), audio, SLOT(musicRecoverSpeed()));

}

void MainWindow::actionInit()
{
    connect(uiMainWindow->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(uiMainWindow->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(uiMainWindow->actionAbout_Music_Mosnter, SIGNAL(triggered()), this, SLOT(about()));
    connect(uiMainWindow->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(uiMainWindow->actionChangeFactor, SIGNAL(triggered()), this, SLOT(changeFactor()));
}
