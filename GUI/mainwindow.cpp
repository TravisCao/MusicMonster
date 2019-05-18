#include "mainwindow.h"
#include "newfiledialog.h"
#include "ui_mainwindowForm.h"
#include "audio.h"
#include "changefactor.h"
#include "readwav.h"
#include "filterdialog.h"
#include "saveasfiledialog.h"

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
#include <QMediaPlaylist>
#include <QStringList>
#include <QFileInfo>
#include <QAudioFormat>
#include <QAudioInput>
#include <QHeaderView>
#include <QModelIndex>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    uiMainWindow(new Ui::MainWindow)
{

    uiMainWindow->setupUi(this);

    audio = new Audio(this);
    fileWidget = new FileWidget(this);
    saveasFileDialog = new saveAsFileDialog(this);

    filterDialog_1 = new FilterDialog(this);
    filterDialog_2 = new FilterDialog(this);
    filterDialog_3 = new FilterDialog(this);
    filterDialog_4 = new FilterDialog(this);
    filterDialog_5 = new FilterDialog(this);
    filterDialog_6 = new FilterDialog(this);
    filterDialog_7 = new FilterDialog(this);

    uiMainWindow->timeNow->display("00:00");
    uiMainWindow->timeTotal->display("00:00");

    bufferIndex = -1;

    modelInit();
    connectionInit();
    buttonInit();
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
        audio->addToPlayList(fileName);
    }

    buttonRecover();
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
    QList<int> rows;
    qDebug() << "saveFile";
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    qDebug() << "rows:" << rows;
    for (int i = 0; i < rows.size(); ++i) {
        std::string fileNameString = openedFileNames.at(i).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(i).bufferList;
        int bufferIndex = fileWidget->fileList.at(i).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        WavOutFile outFile(fileNameString.data(), *buffer); //  save file
    }

    qDebug() << "save";
}

void MainWindow::removeItemSender()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.isEmpty())
        return;
    else {
        for (int i = 0; i < rows.size(); ++i) {
            emit removeItem(rows.at(i));
        }
    }
}

void MainWindow::saveAsFile()
{
    saveasFileDialog = new saveAsFileDialog(this);
    saveasFileDialog->show();

    qDebug() << "saveAsFile";

    QList<int> rows;
    std::string fileName = saveasFileDialog->getName().toStdString();
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    qDebug() << "saveAsFile";
    qDebug() << "size: " << rows.size();
    if (rows.size() == 1) {
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        qDebug() << "name: " << QString::fromStdString(fileName);
        WavOutFile outFile(fileName.data(), *buffer); //  save as file in a new name
    }
    else {
        for (int i = 0; i < rows.size(); ++i) {
            QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(i)).bufferList;
            int bufferIndex = fileWidget->fileList.at(rows.at(i)).bufferIndex;
            MMbuffer<float> *buffer = bufferList.at(bufferIndex);
            WavOutFile outFile(fileName.data(), *buffer); //  save as file in a new name
        }
    }
}

void MainWindow::musicSelected(const QModelIndex & index)
{
    qDebug() << index;
}

void MainWindow::musicPlay()
{
    qDebug() << "musicPlay Receive";
    QList<int> musics;
    if (!fileWidget->selectionModel->hasSelection()) return;
    musics = fileWidget->getSelectedRows();
    qDebug() << musics.first();
    // if the user doesn't select any music files, press play button will make no difference
    if (musics.isEmpty())
        return;
    // if the user selected multiple files to play, pick up the first music to play
    if ( musics.size() > 1) {
        int smallest = 1000;
        for (int i = 0; i < musics.size(); ++i) {
            if (musics.at(i) < smallest) smallest = musics.at(i);
        }
        emit playMusic(smallest);
    }
    else {
        emit playMusic(musics.first());
    }
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


void MainWindow::connectionInit()
{

    connect(uiMainWindow->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(uiMainWindow->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(uiMainWindow->actionAbout_Music_Mosnter, &QAction::triggered, this, &MainWindow::about);
    connect(uiMainWindow->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(uiMainWindow->actionChangeFactor, &QAction::triggered, this, &MainWindow::changeFactor);

    connect(uiMainWindow->actionSave_As, &QAction::triggered, saveasFileDialog, &saveAsFileDialog::show);

    connect(saveasFileDialog, &saveAsFileDialog::accepted, this, &MainWindow::saveAsFile);

    connect(uiMainWindow->openButton, &QPushButton::pressed, this, &MainWindow::openFile);
    connect(uiMainWindow->newButton, &QPushButton::pressed, this, &MainWindow::newFile);
    connect(uiMainWindow->saveButton, &QPushButton::pressed, this, &MainWindow::saveFile);
    connect(uiMainWindow->deleteButton, &QPushButton::pressed, this, &MainWindow::removeItemSender);
    connect(this, &MainWindow::removeItem, fileWidget, &FileWidget::removeItem);
    connect(this, &MainWindow::removeItem, audio, &Audio::removeMusic);

    connect(uiMainWindow->tableView, &QAbstractItemView::clicked, this, &MainWindow::musicSelected);


    connect(uiMainWindow->play, &QPushButton::pressed, this, &MainWindow::musicPlay);
    connect(uiMainWindow->play, &QPushButton::toggled, this, &MainWindow::changePlayIcon);
    connect(this, &MainWindow::playMusic, audio, &Audio::playAndPause);

    connect(uiMainWindow->stop, &QPushButton::pressed, audio, &Audio::musicStop);
    connect(uiMainWindow->stop, &QPushButton::pressed, this, &MainWindow::playButtonChange);

    connect(uiMainWindow->speed, &QPushButton::pressed, audio , &Audio::musicSpeedUp);

    connect(uiMainWindow->speed, &QPushButton::released, audio, &Audio::musicRecoverSpeed);

    connect(uiMainWindow->slow, &QPushButton::pressed, audio, &Audio::musicSlowDown);

    connect(uiMainWindow->slow, &QPushButton::released, audio, &Audio::musicRecoverSpeed);

    connect(audio, &Audio::positionChange, this, &MainWindow::changeSlider);
    connect(uiMainWindow->slider, &QSlider::sliderMoved, audio, &Audio::sliderChange);

    connect(uiMainWindow->actionHighPass, &QAction::triggered, filterDialog_1, &FilterDialog::showHighLowPass);
    connect(uiMainWindow->actionLowPass, &QAction::triggered, filterDialog_2, &FilterDialog::showHighLowPass);
    connect(uiMainWindow->actionNotch, &QAction::triggered, filterDialog_3, &FilterDialog::showBandNotch);
    connect(uiMainWindow->actionBandPass, &QAction::triggered, filterDialog_4, &FilterDialog::showBandNotch);
    connect(uiMainWindow->actionPeaking, &QAction::triggered, filterDialog_5, &FilterDialog::showHighLowShelf);
    connect(uiMainWindow->actionHighShelf, &QAction::triggered, filterDialog_6, &FilterDialog::showHighLowShelf);
    connect(uiMainWindow->actionLowShelf, &QAction::triggered, filterDialog_7, &FilterDialog::showHighLowShelf);



}

void MainWindow::buttonInit()
{
    uiMainWindow->play->setEnabled(false);
    uiMainWindow->stop->setEnabled(false);
    uiMainWindow->speed->setEnabled(false);
    uiMainWindow->slow->setEnabled(false);
    uiMainWindow->playloop->setEnabled(false);
    uiMainWindow->record->setEnabled(false);
}

void MainWindow::buttonRecover()
{
    uiMainWindow->play->setEnabled(true);
    uiMainWindow->stop->setEnabled(true);
    uiMainWindow->speed->setEnabled(true);
    uiMainWindow->slow->setEnabled(true);
    uiMainWindow->playloop->setEnabled(true);
}

void MainWindow::playButtonChange()
{
    uiMainWindow->play->setChecked(false);
    changePlayIcon(false);
}

QString MainWindow::uintToQString(uint number)
{

   std::string string = to_string(number);
   QString qString = QString(QString::fromLocal8Bit(string.c_str()));
   return qString;

}

void MainWindow::changePlayIcon(bool flag)
{
    qDebug() << uiMainWindow->play->isChecked();
    QIcon play, pause;
    qDebug() << QDir::currentPath();
    play.addFile(tr("/Users/travis/Documents/MusicMonster/icon/play.png"));
    pause.addFile(tr("/Users/travis/Documents/MusicMonster/icon/pause.png"));
    if (flag == false) {
        uiMainWindow->play->setIcon(play);
    }
    else {
        uiMainWindow->play->setIcon(pause);
    }
}

void MainWindow::changeSlider(qint64 position)
{
    uiMainWindow->slider->setMaximum(static_cast<int>(audio->player->duration() / 1000));
    uiMainWindow->slider->setValue(static_cast<int>(position / 1000));
    int duration = static_cast<int>(audio->player->duration());
    QTime timenow(0, (position / 60000) % 60, (position / 1000) % 60);
    QTime timetotal(0, (duration / 60000) % 60, (duration / 1000) % 60);
    QString timenowString = timenow.toString("mm:ss");
    QString timetotalString = timetotal.toString("mm:ss");
    uiMainWindow->timeNow->display(timenowString);
    uiMainWindow->timeTotal->display(timetotalString);
}


