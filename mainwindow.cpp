#include "mainwindow.h"
#include "newfiledialog.h"
#include "ui_mainwindowForm.h"
#include "readwav.h"
#include "audio.h"
#include "changefactor.h"

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
    change = new ChangeFactor(this);
    change->show();
    qDebug() << "change";
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
        string filenameString = fileName.toStdString();
        QMediaPlayer *player = new QMediaPlayer();
        player->setMedia(QUrl::fromLocalFile(fileName));
        player->setVolume(50);
        player->play();

        openedFileNames << fileName;
        WavInFile *wavfile = new WavInFile(filenameString.data());
        QString sampleRate(wavfile->getSampleRate());
        QString channel(wavfile->getChannels());
        QString bitBepth(wavfile->getBitsPerSample());
        QString duration(wavfile->getLengthInMS());

        QFileInfo info = QFileInfo(fileName);
        QAudioFormat format;

        QList<QStandardItem *> itemList;
        struct FileWidget::fileItem item;

        //waiting
        QString name = info.fileName();
        item.fileName = new QStandardItem(name);
        item.bitDepth = new QStandardItem(bitBepth);
        item.channels = new QStandardItem(channel);
        item.duration = new QStandardItem(duration);
        item.sampleRate = new QStandardItem(sampleRate);
        fileWidget->addItem(item);
    }

    qDebug() << "open";
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
    uiMainWindow->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    uiMainWindow->tableView->resizeColumnsToContents();
    uiMainWindow->tableView->setAlternatingRowColors(true);
    uiMainWindow->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    uiMainWindow->tableView->setStyleSheet("QTableView::item { \
                                               height: 10px; \
                                               }");
    fileWidget->modelInit(uiMainWindow->tableView);

    effectModel = new QStandardItemModel(20,1);
    uiMainWindow->effectList->setModel(effectModel);

    for (int i = 0; i < 20; ++i) {
        QStandardItem *item = new QStandardItem();
        effectModel->appendRow(item);
    }

    historyModel = new QStandardItemModel(20,1);
    uiMainWindow->historyList->setModel(historyModel);

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
    connect(uiMainWindow->actionChangeFactor, SIGNAL(triggered()), this, SLOT(changeFactor()));
}


