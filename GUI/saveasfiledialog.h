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
    QString getLocation();
    QString getName();

signals:

public slots:

private slots:
    void on_browse_clicked();

private:
    Ui::saveAsDialog *ui;
    QString fileName;
    QString fileLocation;
    QString location;

};

#endif // SAVEASFILEDIALOG_H
