#include "saveasfiledialog.h"
#include "ui_savefiledialog.h"

#include <QDialog>
#include <QLineEdit>
#include <QFileInfo>
#include <QFileDialog>
#include <QDir>
#include <QDebug>

saveAsFileDialog::saveAsFileDialog(QWidget *parent) : QDialog(parent), ui(new Ui::saveAsDialog)
{
    ui->setupUi(this);
    dialogInit();

    connect(ui->browse,&QPushButton::clicked, this, &saveAsFileDialog::getLocation);
}

void saveAsFileDialog::dialogInit()
{
    ui->locationEdit->setPlaceholderText(QDir::currentPath());
}

QString saveAsFileDialog::getName()
{
    qDebug() << "location(get):" << this-> fileLocation;
    fileName = fileLocation + "/" + ui->nameEdit->text();
    return fileName;
}

void saveAsFileDialog::getLocation()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->locationEdit->setText(dir);
    this->fileLocation = dir;
    qDebug() << "fileLocation(click): " << fileLocation;
    qDebug() << getName();

}
