#ifndef EFFECTHISTORYWIDGET_H
#define EFFECTHISTORYWIDGET_H

#include <QObject>
#include <QWidget>

namespace Ui {
    class Form;
}

class effectHistoryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit effectHistoryWidget(QWidget *parent = nullptr);

signals:

public slots:
private:
    Ui::Form *ui;
};

#endif // EFFECTHISTORYWIDGET_H
