#ifndef PLAYBACKDIALOG_H
#define PLAYBACKDIALOG_H

#include <QDialog>

namespace Ui {
class playbackDialog;
}

class playbackDialog : public QDialog
{
    Q_OBJECT

public:
    explicit playbackDialog(QWidget *parent = nullptr);
    ~playbackDialog();
    QString getPlaybackRate();

private:
    Ui::playbackDialog *ui;
};

#endif // PLAYBACKDIALOG_H
