#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filewidget.h"
#include "newfiledialog.h"
#include "changefactor.h"
#include "audio.h"
#include "saveasfiledialog.h"

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

    void changeFactor();

    void about();

    void saveFile();

    void removeItemSender();

    void saveAsFile();

    void musicSelected(const QModelIndex & index);

    void musicPlay();

    QString uintToQString(uint number);

    void changePlayIcon(bool flag);

    void changeSlider(qint64 position);


private:

    void modelInit();

    void connectionInit();

    void buttonInit();

    void buttonRecover();

    void playButtonChange();

private:

    Audio *audio;

    QList<QString> openedFileNames;

    saveAsFileDialog *saveasFileDialog;

    NewFileDialog *newFileDialog;

    FileWidget *fileWidget;

    Ui::MainWindow *uiMainWindow;

    Ui::Dialog *uiNewFileDialog;

    QStandardItemModel *fileModel;

    QStandardItemModel *effectModel;

    QStandardItemModel *historyModel;

};

#endif // MAINWINDOW_H
