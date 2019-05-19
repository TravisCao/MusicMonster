#ifndef CHANGEPITCH_H
#define CHANGEPITCH_H

#include <QDialog>

namespace Ui {
class changepitch;
}

class changepitch : public QDialog
{
    Q_OBJECT

public:
    explicit changepitch(QWidget *parent = nullptr);
    ~changepitch();
    QString getPitch();

private:
    Ui::changepitch *ui;
};

#endif // CHANGEPITCH_H
