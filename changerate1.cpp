#include "changerate1.h"
#include "ui_changerate1.h"

ChangeRate1::ChangeRate1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeRate1)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("0.5"));
    ui->comboBox->addItem(tr("0.25"));
    ui->comboBox->addItem(tr("0.33"));
    ui->comboBox->addItem(tr("2.0"));
    ui->comboBox->addItem(tr("1.5"));
    ui->comboBox->addItem(tr("1.7"));
    ui->comboBox->addItem(tr("0.4"));
    ui->comboBox->addItem(tr("1.3"));
}

ChangeRate1::~ChangeRate1()
{
    delete ui;
}

QString ChangeRate1::getRate()
{
    return ui->comboBox->currentText();
}
