#ifndef CHANGERATE1_H
#define CHANGERATE1_H

#include <QDialog>

namespace Ui {
class ChangeRate1;
}

class ChangeRate1 : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeRate1(QWidget *parent = nullptr);
    ~ChangeRate1();
    QString getRate();

private:
    Ui::ChangeRate1 *ui;
};

#endif // CHANGERATE1_H
