#include "newfiledialog.h"
#include "ui_newdialogForm.h"

#include <QDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>

NewFileDialog::NewFileDialog(QWidget *parent) :QDialog(parent), ui(new Ui::newDialog)
{

    ui->setupUi(this);
    dialogInit();

}

void NewFileDialog::dialogInit()

{

    ui->rateComboBox->setEditable(false);
    ui->rateComboBox->addItem(tr("32"));
    ui->rateComboBox->addItem(tr("24"));
    ui->rateComboBox->addItem(tr("16"));

    ui->bitDepthComboBox->setEditable(false);
    ui->bitDepthComboBox->addItem(tr("60000"));
    ui->bitDepthComboBox->addItem(tr("48000"));
    ui->bitDepthComboBox->addItem(tr("36000"));

    ui->locationEdit->setPlaceholderText(QDir::currentPath());

}

QString NewFileDialog::getLocation()

{
    return ui->locationEdit->text();
}

QString NewFileDialog::getName()

{
    return ui->nameEdit->text();
}

QString NewFileDialog::getSampleRate()

{
    return ui->rateComboBox->currentText();
}

QString NewFileDialog::getBitDepth()
{
    return ui->bitDepthComboBox->currentText();
}

void NewFileDialog::on_browseButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->locationEdit->setText(dir);
}
