#ifndef SAVEASFILEDIALOG_H
#define SAVEASFILEDIALOG_H

#include <QObject>
#include <QDialog>

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

};

#endif // SAVEASFILEDIALOG_H
