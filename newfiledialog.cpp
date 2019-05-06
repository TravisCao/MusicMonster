#include "newfiledialog.h"
#include "ui_newdialogForm.h"

#include <QDialog>

newFileDialog::newFileDialog(QWidget *parent) :QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

newFileDialog::~newFileDialog()
{

}
