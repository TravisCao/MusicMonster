#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void openFile();
    void about();
    void saveFile();

private:
    void modelInit();
    void actionInit();

private:
    Ui::MainWindow *uiMainWindow;
    Ui::Dialog *uiNewFileDialog;
    QStandardItemModel *fileModel;
    QStandardItemModel *effectModel;
    QStandardItemModel *historyModel;
};

#endif // MAINWINDOW_H
