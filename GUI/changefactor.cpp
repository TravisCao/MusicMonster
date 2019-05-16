#include "changefactor.h"
#include "ui_changefactordialog.h"

#include <QDialog>
#include <QDebug>
#include <QStandardItem>

ChangeFactor::ChangeFactor(QWidget *parent) : QDialog(parent), ui(new Ui::changeDialog)
{
    ui->setupUi(this);
    dialogInit();
}

void ChangeFactor::dialogInit()
{

    ui->ratebox->addItem(tr("0.5"));
    ui->ratebox->addItem(tr("1.5"));
    ui->ratebox->addItem(tr("2"));

    ui->pitchbox->addItem(tr("0.5"));
    ui->pitchbox->addItem(tr("1.5"));
    ui->pitchbox->addItem(tr("2"));

    ui->tempobox->addItem(tr("0.5"));
    ui->tempobox->addItem(tr("1.5"));
    ui->tempobox->addItem(tr("2"));

}
