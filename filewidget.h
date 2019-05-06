#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>

namespace Ui {
    class Form;
}

class fileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit fileWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    Ui::Form *ui;
};

#endif // FILEWIDGET_H
