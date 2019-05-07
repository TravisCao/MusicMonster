#ifndef CHANGEFACTOR_H
#define CHANGEFACTOR_H

#include <QWidget>
#include <QDialog>

namespace Ui {
    class Dialog;
}

class ChangeFactor : public QDialog
{
    Q_OBJECT
public:
    explicit ChangeFactor(QWidget *parent = nullptr);
    void dialogInit();

signals:

public slots:

private:
    Ui::Dialog *ui;

};

#endif // CHANGEFACTOR_H
