#ifndef CUTDIALOG_H
#define CUTDIALOG_H

#include <QDialog>

namespace Ui {
class cutDialog;
}

class cutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cutDialog(QWidget *parent = nullptr);
    ~cutDialog();
    double get_timeBegin();
    double get_timeEnd();

private:
    Ui::cutDialog *ui;
};

#endif // CUTDIALOG_H
