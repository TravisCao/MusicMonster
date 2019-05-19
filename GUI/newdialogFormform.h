/********************************************************************************
** Form generated from reading UI file 'newdialogForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOGFORM_H
#define UI_NEWDIALOGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *locationLabel;
    QLabel *sampleRateLabel;
    QComboBox *bitDepthComboBox;
    QLabel *bitDepthLabel;
    QLineEdit *nameEdit;
    QComboBox *rateComboBox;
    QPushButton *browseButton;
    QLineEdit *locationEdit;
    QLabel *sampleRateLabel_2;
    QLabel *bitDepthLabel_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newDialog)
    {
        if (newDialog->objectName().isEmpty())
            newDialog->setObjectName(QString::fromUtf8("newDialog"));
        newDialog->resize(400, 300);
        newDialog->setSizeGripEnabled(false);
        newDialog->setModal(false);
        horizontalLayout = new QHBoxLayout(newDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(15);
        nameLabel = new QLabel(newDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        locationLabel = new QLabel(newDialog);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(locationLabel, 1, 0, 1, 1);

        sampleRateLabel = new QLabel(newDialog);
        sampleRateLabel->setObjectName(QString::fromUtf8("sampleRateLabel"));
        sampleRateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(sampleRateLabel, 2, 0, 1, 1);

        bitDepthComboBox = new QComboBox(newDialog);
        bitDepthComboBox->setObjectName(QString::fromUtf8("bitDepthComboBox"));

        gridLayout->addWidget(bitDepthComboBox, 3, 1, 1, 1);

        bitDepthLabel = new QLabel(newDialog);
        bitDepthLabel->setObjectName(QString::fromUtf8("bitDepthLabel"));
        bitDepthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(bitDepthLabel, 3, 0, 1, 1);

        nameEdit = new QLineEdit(newDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        rateComboBox = new QComboBox(newDialog);
        rateComboBox->setObjectName(QString::fromUtf8("rateComboBox"));

        gridLayout->addWidget(rateComboBox, 2, 1, 1, 1);

        browseButton = new QPushButton(newDialog);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        gridLayout->addWidget(browseButton, 1, 2, 1, 1);

        locationEdit = new QLineEdit(newDialog);
        locationEdit->setObjectName(QString::fromUtf8("locationEdit"));

        gridLayout->addWidget(locationEdit, 1, 1, 1, 1);

        sampleRateLabel_2 = new QLabel(newDialog);
        sampleRateLabel_2->setObjectName(QString::fromUtf8("sampleRateLabel_2"));

        gridLayout->addWidget(sampleRateLabel_2, 2, 2, 1, 1);

        bitDepthLabel_2 = new QLabel(newDialog);
        bitDepthLabel_2->setObjectName(QString::fromUtf8("bitDepthLabel_2"));

        gridLayout->addWidget(bitDepthLabel_2, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(newDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(newDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newDialog);
    } // setupUi

    void retranslateUi(QDialog *newDialog)
    {
        newDialog->setWindowTitle(QApplication::translate("newDialog", "New Multitrack Session", nullptr));
        nameLabel->setText(QApplication::translate("newDialog", "Session Name:", nullptr));
        locationLabel->setText(QApplication::translate("newDialog", "Folder Location:", nullptr));
        sampleRateLabel->setText(QApplication::translate("newDialog", "Sample Rate:", nullptr));
        bitDepthLabel->setText(QApplication::translate("newDialog", "Bit Depth:", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("newDialog", "Untitled Session 1", nullptr));
        rateComboBox->setCurrentText(QString());
        browseButton->setText(QApplication::translate("newDialog", "Browse", nullptr));
        sampleRateLabel_2->setText(QApplication::translate("newDialog", "Hz", nullptr));
        bitDepthLabel_2->setText(QApplication::translate("newDialog", "bits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newDialog: public Ui_newDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOGFORM_H
