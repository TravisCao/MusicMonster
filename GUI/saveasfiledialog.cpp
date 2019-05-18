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
}

void saveAsFileDialog::dialogInit()
{
    ui->locationEdit->setPlaceholderText(QDir::currentPath());
}

QString saveAsFileDialog::getLocation()
{
    return fileLocation;
}

QString saveAsFileDialog::getName()
{
    qDebug() << "location(get):" << location;
    fileName = fileLocation + "/" + ui->nameEdit->text();
    qDebug() << "fileLocation: " << fileLocation;
    qDebug() << "text: " << ui->nameEdit->text();
    qDebug() << "fileName(get): " << fileName;
    return fileName;
}


void saveAsFileDialog::on_browse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->locationEdit->setText(dir);
    fileLocation = dir;
    location = dir;
    qDebug() << "fileLocation(click): " << fileLocation;
    qDebug() << "location(click):" << location;
    fileName = fileLocation + "/" + "11.wav";
    qDebug() << "fileName(click):" << fileName;
}
