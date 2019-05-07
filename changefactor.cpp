#include "changefactor.h"
#include "ui_changefactordialog.h"

#include <QWidget>
#include <QDialog>

ChangeFactor::ChangeFactor(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    dialogInit();
}

void ChangeFactor::dialogInit()
{
    ui->ratebox->setEditable(false);
    ui->ratebox->addItem(tr("0.5"));
    ui->ratebox->addItem(tr("1.5"));
    ui->ratebox->addItem(tr("2"));

    ui->ratebox->setEditable(false);
    ui->pitchbox->addItem(tr("0.5"));
    ui->pitchbox->addItem(tr("1.5"));
    ui->pitchbox->addItem(tr("2"));

    ui->ratebox->setEditable(false);
    ui->tempobox->addItem(tr("0.5"));
    ui->tempobox->addItem(tr("1.5"));
    ui->tempobox->addItem(tr("2"));
}
