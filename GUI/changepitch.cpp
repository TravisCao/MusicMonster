#include "changepitch.h"
#include "ui_changepitch.h"

changepitch::changepitch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepitch)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("Low"));
    ui->comboBox->addItem(tr("High"));
}

changepitch::~changepitch()
{
    delete ui;
}

QString changepitch::getPitch()
{
    return ui->comboBox->currentText();
}
