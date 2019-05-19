#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filewidget.h"
#include "newfiledialog.h"
#include "audio.h"
#include "saveasfiledialog.h"
#include "filterdialog.h"
#include "saveasfiledialog.h"
#include "playbackdialog.h"
#include "changepitch.h"
#include "changerate1.h"
#include "cutdialog.h"

#include <QMainWindow>
#include <QList>
#include <QStandardItemModel>
#include <QModelIndex>

namespace Ui {

class MainWindow;

class Dialog;

}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

signals:

    void removeItem(int index);
    void playMusic(int index);
    void changePosition(int position);
    void stopMusic();


public slots:

    void newFile();

    QList<QString> *openFile();

    void about();

    void saveFile();

    void removeItemSender();

    void playback();

    void changeRate();

    void changePitch();

    void saveAsFile();

    void showSaveAsFile();

    void musicPlay();

    QString uintToQString(uint number);

    void togglePlayButton(bool flag);

    void togglePlayloopButton(bool flag);

    void toggleRecordButton(bool flag);

    void changeSlider(qint64 position);

    void changeVolumeBar(int value);

    void addTempFile(QString filename);

    // for filter

    void highPass();

    void lowPass();

    void bandPass();

    void peaking();

    void notch();

    void lowShelf();

    void highShelf();

    void undo();

    void redo();

    void cutTime();

private:

    void modelInit();

    void connectionInit();

    void buttonInit();

    void buttonRecover();

    void playButtonChange();

private:

    int bufferIndex;

    Audio *audio;

    cutDialog    *cutdialog;

    playbackDialog *playbackdialog;

    changepitch *changePitchDialog;

    ChangeRate1 *changeRateDialog;

    QList<QString> openedFileNames;

    saveAsFileDialog *saveasFileDialog;

    FilterDialog *filterDialog_1;

    FilterDialog *filterDialog_2;

    FilterDialog *filterDialog_3;

    FilterDialog *filterDialog_4;

    FilterDialog *filterDialog_5;

    FilterDialog *filterDialog_6;

    FilterDialog *filterDialog_7;

    NewFileDialog *newFileDialog;

    FileWidget *fileWidget;

    Ui::MainWindow *uiMainWindow;

    Ui::Dialog *uiNewFileDialog;

    QStandardItemModel *fileModel;

    QStandardItemModel *effectModel;

    QStandardItemModel *historyModel;

};

#endif // MAINWINDOW_H
