#include "cutdialog.h"
#include "ui_cutdialog.h"

cutDialog::cutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cutDialog)
{
    ui->setupUi(this);
}

cutDialog::~cutDialog()
{
    delete ui;
}

double cutDialog::get_timeBegin()
{
    QString time = ui->timebegin->text();
    QString min = time.mid(0,2);
    QString sec = time.mid(3,2);
    double minDou = min.toDouble();
    double secDou = sec.toDouble();

    return minDou * 60 + secDou;

}

double cutDialog::get_timeEnd()
{
    QString time = ui->timeend->text();
    QString min = time.mid(0,2);
    QString sec = time.mid(3,2);
    double minDou = min.toDouble();
    double secDou = sec.toDouble();

    return minDou * 60 + secDou;
}
