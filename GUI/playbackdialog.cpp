#include "playbackdialog.h"
#include "ui_playbackdialog.h"

playbackDialog::playbackDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playbackDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("1.0"));
    ui->comboBox->addItem(tr("2.0"));
    ui->comboBox->addItem(tr("0.5"));
}

playbackDialog::~playbackDialog()
{
    delete ui;
}

QString playbackDialog::getPlaybackRate()
{
    return ui->comboBox->currentText();
}
