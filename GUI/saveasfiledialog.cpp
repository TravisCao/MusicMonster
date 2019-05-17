#include "saveasfiledialog.h"
#include "ui_savefiledialog.h"

#include <QDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>

saveAsFileDialog::saveAsFileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::saveAsDialog)
{
    ui->setupUi(this);
}

void saveAsFileDialog::dialogInit()
{
    ui->locationEdit->setPlaceholderText(QDir::currentPath());
}


void saveAsFileDialog::on_browse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->locationEdit->setText(dir);
}
