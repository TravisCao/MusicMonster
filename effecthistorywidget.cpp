#include "effecthistorywidget.h"
#include "ui_effecthistorywidget.h"

#include <QWidget>

effectHistoryWidget::effectHistoryWidget(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}
