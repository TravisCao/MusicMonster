#include "mainwindow.h"
#include "newfiledialog.h"
#include "ui_mainwindowForm.h"
#include "audio.h"
#include "readwav.h"
#include "filterdialog.h"
#include "saveasfiledialog.h"
#include "changepitch.h"
#include "changerate1.h"
#include "playbackdialog.h"
#include "mmtempo.h"
#include "mmrate.h"
#include "wavWidget.h"
#include "cutdialog.h"

#include <string>

#include <QProcess>
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
    changeRateDialog = new ChangeRate1(this);
    changePitchDialog = new changepitch(this);
    playbackdialog = new playbackDialog(this);
    cutdialog = new  cutDialog(this);

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
//        uiMainWindow->waveWidget->setFile(fileName);
//        uiMainWindow->waveWidget->update();
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
    qDebug() << "rows(to be removed): " << rows;
    fileWidget->selectionModel->reset();
    if (fileWidget->fileList.isEmpty())
        return;
    else {
        for (int i = 0; i < rows.size(); ++i) {
            qDebug() << "removeItemAtRow: 0 ";
            emit removeItem(rows.at(i));
        }
    }
}

void MainWindow::playback()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);

        MMbuffer<float> dbuffer;
        dbuffer.setDataSize(2 * dbuffer.getDataSize());
        dbuffer.initializeData();
        dbuffer = *buffer;

        if (playbackdialog->getPlaybackRate() == "1.0")
            setTempo(99.0, *buffer, dbuffer); // 1.0 speed playback
        if (playbackdialog->getPlaybackRate() == "2.0")
            setTempo(98.0, *buffer, dbuffer); // 2.0 speed playback
        if (playbackdialog->getPlaybackRate() == "0.5")
            setTempo(97.0, *buffer, dbuffer); // 0.5 speed playback

        qDebug() << "name: " << QString::fromStdString(fileName);
        WavOutFile outFile(fileName.data(), dbuffer); //  save as file in a new name
    }

}

void MainWindow::changeRate()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);

        MMbuffer<float> dbuffer;
        dbuffer.setDataSize(2 * dbuffer.getDataSize());
        dbuffer.initializeData();
        if (changeRateDialog->getRate() == "0.25" || changeRateDialog->getRate() == "0.5" || \
                changeRateDialog->getRate() == "0.33" || changeRateDialog->getRate() == "2.0"){

            dbuffer = *buffer;
            double newtempo = static_cast<double>(stod(changeRateDialog->getRate().toStdString()));
            qDebug() << "newtempo :" << newtempo;
            setTempo(newtempo, *buffer, dbuffer);
            WavOutFile(fileName.data(), dbuffer);
        }
        else {
            double newRate = static_cast<double>(stod(changeRateDialog->getRate().toStdString()));
            setRate(newRate, *buffer, dbuffer, 1);
            WavOutFile(fileName.data(), dbuffer);
        }
     }

}

void MainWindow::changePitch()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);

        MMbuffer<float> dbuffer;
        dbuffer.setDataSize(2 * dbuffer.getDataSize());
        dbuffer.initializeData();
        dbuffer = *buffer;
        if (changePitchDialog->getPitch() == "Low") {
            setTempo(89, *buffer, dbuffer);
            WavOutFile(fileName.data(), dbuffer);
        }
        else {
            setTempo(88, *buffer, dbuffer);
            WavOutFile(fileName.data(), dbuffer);
        }
     }
}

void MainWindow::saveAsFile()
{
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
}

void MainWindow::showSaveAsFile()
{
   saveasFileDialog->show();

}

void MainWindow::musicPlay()
{
    qDebug() << "musicPlay Receive";
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        uiMainWindow->volumeBar->setMaximum(static_cast<int>(buffer->findPeak()));
        uiMainWindow->volumeBar->setMinimum(static_cast<int>(buffer->findMinPeak()));
    }

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

    connect(uiMainWindow->actionSave_As, &QAction::triggered, this, &MainWindow::showSaveAsFile);

    connect(saveasFileDialog, &saveAsFileDialog::accepted, this, &MainWindow::saveAsFile);

    connect(uiMainWindow->record, &QPushButton::toggled, audio, &Audio::record);
    connect(uiMainWindow->record, &QPushButton::toggled, this, &MainWindow::toggleRecordButton);

    connect(uiMainWindow->playloop, &QPushButton::toggled, audio, &Audio::musicRecycle);
    connect(uiMainWindow->playloop, &QPushButton::toggled, this, &MainWindow::togglePlayloopButton);

    connect(uiMainWindow->openButton, &QPushButton::pressed, this, &MainWindow::openFile);
    connect(uiMainWindow->newButton, &QPushButton::pressed, this, &MainWindow::newFile);
    connect(uiMainWindow->saveButton, &QPushButton::pressed, this, &MainWindow::saveFile);
    connect(uiMainWindow->deleteButton, &QPushButton::pressed, this, &MainWindow::removeItemSender);

    connect(this, &MainWindow::removeItem, fileWidget, &FileWidget::removeItem);
    connect(this, &MainWindow::removeItem, audio, &Audio::removeMusic);

    connect(uiMainWindow->play, &QPushButton::pressed, this, &MainWindow::musicPlay);
    connect(uiMainWindow->play, &QPushButton::toggled, this, &MainWindow::togglePlayButton);
    connect(this, &MainWindow::playMusic, audio, &Audio::playAndPause);

    connect(uiMainWindow->stop, &QPushButton::pressed, audio, &Audio::musicStop);
    connect(uiMainWindow->stop, &QPushButton::pressed, this, &MainWindow::playButtonChange);

    connect(uiMainWindow->speed, &QPushButton::pressed, audio , &Audio::musicSpeedUp);

    connect(uiMainWindow->speed, &QPushButton::released, audio, &Audio::musicRecoverSpeed);

    connect(uiMainWindow->slow, &QPushButton::pressed, audio, &Audio::musicSlowDown);

    connect(uiMainWindow->slow, &QPushButton::released, audio, &Audio::musicRecoverSpeed);

    connect(audio, &Audio::positionChange, this, &MainWindow::changeSlider);
    connect(audio, &Audio::update, this, &MainWindow::changeVolumeBar);
    connect(uiMainWindow->slider, &QSlider::sliderMoved, audio, &Audio::sliderChange);

    connect(uiMainWindow->actionHighPass, &QAction::triggered, filterDialog_1, &FilterDialog::showHighLowPass);
    connect(uiMainWindow->actionLowPass, &QAction::triggered, filterDialog_2, &FilterDialog::showHighLowPass);
    connect(uiMainWindow->actionNotch, &QAction::triggered, filterDialog_3, &FilterDialog::showBandNotch);
    connect(uiMainWindow->actionBandPass, &QAction::triggered, filterDialog_4, &FilterDialog::showBandNotch);
    connect(uiMainWindow->actionPeaking, &QAction::triggered, filterDialog_5, &FilterDialog::showHighLowShelf);
    connect(uiMainWindow->actionHighShelf, &QAction::triggered, filterDialog_6, &FilterDialog::showHighLowShelf);
    connect(uiMainWindow->actionLowShelf, &QAction::triggered, filterDialog_7, &FilterDialog::showHighLowShelf);

    connect(filterDialog_1,&FilterDialog::accepted, this, &MainWindow::highPass);
    connect(filterDialog_2,&FilterDialog::accepted, this, &MainWindow::lowPass);
    connect(filterDialog_3,&FilterDialog::accepted, this, &MainWindow::notch);
    connect(filterDialog_4,&FilterDialog::accepted, this, &MainWindow::bandPass);
    connect(filterDialog_5,&FilterDialog::accepted, this, &MainWindow::peaking);
    connect(filterDialog_6,&FilterDialog::accepted, this, &MainWindow::highShelf);
    connect(filterDialog_7,&FilterDialog::accepted, this, &MainWindow::lowShelf);

    connect(uiMainWindow->actionRate, &QAction::triggered, changeRateDialog, &ChangeRate1::show);
    connect(changeRateDialog,&ChangeRate1::accepted, this, &MainWindow::changeRate);

    connect(uiMainWindow->actionPitch, &QAction::triggered, changePitchDialog, &changepitch::show);
    connect(changePitchDialog, &changepitch::accepted, this, &MainWindow::changePitch);

    connect(uiMainWindow->actionPlayback, &QAction::triggered, playbackdialog, &playbackDialog::show);
    connect(playbackdialog, &playbackDialog::accepted, this, &MainWindow::playback);

    connect(audio, &Audio::musicStart, this, &MainWindow::togglePlayButton);
    connect(audio, &Audio::musicPause, this, &MainWindow::togglePlayButton);

    connect(uiMainWindow->actionundo, &QAction::triggered, this, &MainWindow::undo);
    connect(uiMainWindow->actionRedo, &QAction::triggered, this, &MainWindow::redo);

    connect(uiMainWindow->actionCut, &QAction::triggered, cutdialog, &cutDialog::show);
    connect(uiMainWindow->actionCut, &QAction::triggered,
            []{
                qDebug() << "cutClicked";
             });
    connect(cutdialog,&cutDialog::accepted, this, &MainWindow::cutTime);

}

void MainWindow::buttonInit()
{
    uiMainWindow->play->setEnabled(false);
    uiMainWindow->stop->setEnabled(false);
    uiMainWindow->speed->setEnabled(false);
    uiMainWindow->slow->setEnabled(false);
    uiMainWindow->playloop->setEnabled(false);
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
    togglePlayButton(false);
}

QString MainWindow::uintToQString(uint number)
{

   std::string string = to_string(number);
   QString qString = QString(QString::fromLocal8Bit(string.c_str()));
   return qString;

}

void MainWindow::togglePlayButton(bool flag)
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

void MainWindow::togglePlayloopButton(bool flag)
{
   QIcon playloop, playloopStop;
   playloop.addFile(tr("/Users/travis/Documents/MusicMonster/icon/playloop.png"));
   playloopStop.addFile(tr("/Users/travis/Documents/MusicMonster/icon/playLoopToggle.png"));

   if (flag == false) uiMainWindow->playloop->setIcon(playloop);
   else uiMainWindow->playloop->setIcon(playloopStop);
}

void MainWindow::toggleRecordButton(bool flag)
{
   QIcon record, stop_record;
   record.addFile(tr("/Users/travis/Documents/MusicMonster/icon/record.png"));
   stop_record.addFile(tr("/Users/travis/Documents/MusicMonster/icon/recordToggle.png"));

   if (flag == false) uiMainWindow->record->setIcon(record);
   else uiMainWindow->record->setIcon(stop_record);

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

void MainWindow::changeVolumeBar(int value)
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        uiMainWindow->volumeBar->setValue(static_cast<int>(buffer->getCurrent(value)));
    }
}

void MainWindow::highPass()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_HighPass.wav";
        qDebug() << "outputFileName:" << outputFileName;


#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("highpass");
        args.append(filterDialog_1->getHighLowPassCutoff());
        args.append(filterDialog_1->getHighLowPassResonance());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);


#endif

#ifdef Q_OS_MAC

    QProcess proc;
    qDebug() << "mac: ";

    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("highpass");
    args.append(filterDialog_1->getHighLowPassCutoff());
    args.append(filterDialog_1->getHighLowPassResonance());

    qDebug() << filterDialog_1->getHighLowPassCutoff();
    qDebug() << filterDialog_1->getHighLowPassResonance();
//    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
//    args.append("/Users/travis/Desktop/ttt.wav");
//    args.append("/Users/travis/Desktop/ttt_11.wav");
//    args.append("highpass");
//    args.append("20");
//    args.append("20");

    proc.setProgram("/Users/travis/Documents/MusicMonster/Filter/a.out");
    proc.setArguments(args);
    qDebug() << "mac: ";
    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::lowPass()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_LowPass.wav";

#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("lowpass");
        args.append(filterDialog_2->getHighLowPassCutoff());
        args.append(filterDialog_2->getHighLowPassResonance());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("lowpass");
    args.append(filterDialog_2->getHighLowPassCutoff());
    args.append(filterDialog_2->getHighLowPassResonance());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::bandPass()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_bandPass.wav";

#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("bandpass");
        args.append(filterDialog_4->getBandNotchFreq());
        args.append(filterDialog_4->getBandNotchSpan());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;
    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("bandpass");
    args.append(filterDialog_4->getBandNotchFreq());
    args.append(filterDialog_4->getBandNotchSpan());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::peaking()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_peaking.wav";

#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("peaking");
        args.append(filterDialog_5->getHighLowShelfFreq());
        args.append(filterDialog_5->getHighLowShelfSpan());
        args.append(filterDialog_5->getHighLowShelfGain());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("peaking");
    args.append(filterDialog_5->getHighLowShelfFreq());
    args.append(filterDialog_5->getHighLowShelfSpan());
    args.append(filterDialog_5->getHighLowShelfGain());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::notch()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_notch.wav";

#ifdef Q_OS_WIN

        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("notch");
        args.append(filterDialog_3->getBandNotchFreq());
        args.append(filterDialog_3->getBandNotchSpan());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);


#endif

#ifdef Q_OS_MAC

    QProcess proc;
    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("notch");
    args.append(filterDialog_3->getBandNotchFreq());
    args.append(filterDialog_3->getBandNotchSpan());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::lowShelf()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_lowShelf.wav";


#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("lowshelf");
        args.append(filterDialog_7->getHighLowShelfFreq());
        args.append(filterDialog_7->getHighLowShelfSpan());
        args.append(filterDialog_7->getHighLowShelfGain());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);


#endif

#ifdef Q_OS_MAC

    QProcess proc;

        args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
        args.append(fileName);
        args.append(outputFileName);
        args.append("lowshelf");
        args.append(filterDialog_7->getHighLowShelfFreq());
        args.append(filterDialog_7->getHighLowShelfSpan());
        args.append(filterDialog_7->getHighLowShelfGain());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::highShelf()
{
    QStringList args;
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        QString fileName = openedFileNames.at(rows.at(0));
        fileName.chop(4);
        QString outputFileName = fileName + "_highShelf.wav";

#ifdef Q_OS_WIN
        args.append("/Users/travis/Documents/MusicMonster/Filter/a.exe");
        args.append(fileName);
        args.append(outputFileName);
        args.append("highshelf");
        args.append(filterDialog_6->getHighLowShelfFreq());
        args.append(filterDialog_6->getHighLowShelfSpan());
        args.append(filterDialog_6->getHighLowShelfGain());

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/Filter/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;
    args.append("/Users/travis/Documents/MusicMonster/Filter/a.out");
    args.append(fileName);
    args.append(outputFileName);
    args.append("highshelf");
    args.append(filterDialog_6->getHighLowShelfFreq());
    args.append(filterDialog_6->getHighLowShelfSpan());
    args.append(filterDialog_6->getHighLowShelfGain());

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
    }

}

void MainWindow::undo()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        if (bufferIndex > 0) {
        buffer = bufferList.at(bufferIndex - 1);
        WavOutFile outFile(fileName.data(), *buffer);
        }
    }

}

void MainWindow::redo()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);
        if (bufferIndex < bufferList.size()) {
        buffer = bufferList.at(bufferIndex + 1);
        WavOutFile outFile(fileName.data(), *buffer);
        }
    }
}

void MainWindow::cutTime()
{
    QList<int> rows;
    if (!fileWidget->selectionModel->hasSelection()) return;
    rows = fileWidget->getSelectedRows();
    if (rows.size() == 1) {
        std::string fileName = openedFileNames.at(rows.at(0)).toStdString();
        QList<MMbuffer<float>*> bufferList = fileWidget->fileList.at(rows.at(0)).bufferList;
        int bufferIndex = fileWidget->fileList.at(rows.at(0)).bufferIndex;
        MMbuffer<float> *buffer = bufferList.at(bufferIndex);

        MMbuffer<float> *dbuffer = buffer;

        MMcut(cutdialog->get_timeBegin(),cutdialog->get_timeEnd(), audio->getAudioDuration(), *buffer, *dbuffer);

//        (fileWidget->fileList.at(rows.at(0)).bufferList).

        WavOutFile outfile(fileName.data(), *dbuffer);

    }
}
