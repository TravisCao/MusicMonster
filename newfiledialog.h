#ifndef NEWFILEDIALOG_H
#define NEWFILEDIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class newFileDialog : public QDialog
{
    Q_OBJECT
public:
    newFileDialog(QWidget *parent = nullptr);
    ~newFileDialog();

private:
    Ui::Dialog *ui;
};

#endif // NEWFILEDIALOG_H
