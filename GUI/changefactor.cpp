#include "changefactor.h"
#include "ui_changeratedialog.h"

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


}
