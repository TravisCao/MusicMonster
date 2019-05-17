#ifndef CHANGEFACTOR_H
#define CHANGEFACTOR_H

#include <QWidget>
#include <QDialog>

namespace Ui {
    class changeDialog;
}

class ChangeFactor : public QDialog
{
    Q_OBJECT

public:

    ChangeFactor(QWidget *parent = nullptr);

    void dialogInit();

private:
    Ui::changeDialog *ui;

};

#endif // CHANGEFACTOR_H
