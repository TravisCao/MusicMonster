#ifndef SAVEASFILEDIALOG_H
#define SAVEASFILEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QString>
#include <QDir>

namespace Ui {
    class saveAsDialog;
}

class saveAsFileDialog : public QDialog
{
    Q_OBJECT

public:
    saveAsFileDialog(QWidget *parent = nullptr);
    void dialogInit();
    QString getName();

signals:

public slots:
    void getLocation();

private:

    Ui::saveAsDialog *ui;
    QString fileName;
    QString fileLocation;

};

#endif // SAVEASFILEDIALOG_H
