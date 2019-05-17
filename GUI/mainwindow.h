#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filewidget.h"
#include "newfiledialog.h"
#include "changefactor.h"
#include "audio.h"

#include <QMainWindow>
#include <QList>
#include <QStandardItemModel>

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

public slots:

    void newFile();

    QList<QString> *openFile();

    void changeFactor();

    void about();

    void saveFile();

private:

    void modelInit();

    void audioInit();

    void actionInit();

private:

    QList<QString> openedFileNames;
    Audio *audio;
    NewFileDialog *newFileDialog;
    FileWidget *fileWidget;
    Ui::MainWindow *uiMainWindow;
    Ui::Dialog *uiNewFileDialog;
    QStandardItemModel *fileModel;
    QStandardItemModel *effectModel;
    QStandardItemModel *historyModel;

};

#endif // MAINWINDOW_H
