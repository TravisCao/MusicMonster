#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
    class newDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:

    NewFileDialog(QWidget *parent = nullptr);
    void dialogInit();
    QString getLocation();
    QString getName();
    QString getSampleRate();
    QString getBitDepth();


private slots:
    void on_browseButton_clicked();


private:
    Ui::newDialog *ui;

};

#endif // NEWFILEDIALOG_H
