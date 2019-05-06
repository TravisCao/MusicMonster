#include "filewidget.h"
#include "ui_filewidget.h"

#include <QWidget>

fileWidget::fileWidget(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}
