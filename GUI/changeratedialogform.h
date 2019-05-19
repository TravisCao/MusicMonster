/********************************************************************************
** Form generated from reading UI file 'changeratedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGERATEDIALOG_H
#define UI_CHANGERATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_changeRateDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *changeRateDialog)
    {
        if (changeRateDialog->objectName().isEmpty())
            changeRateDialog->setObjectName(QString::fromUtf8("changeRateDialog"));
        changeRateDialog->resize(353, 242);
        gridLayout = new QGridLayout(changeRateDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(changeRateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 2, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(changeRateDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(changeRateDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.250000000000000);
        doubleSpinBox->setMaximum(400.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(changeRateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), changeRateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changeRateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeRateDialog);
    } // setupUi

    void retranslateUi(QDialog *changeRateDialog)
    {
        changeRateDialog->setWindowTitle(QApplication::translate("changeRateDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("changeRateDialog", "Change rate to:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeRateDialog: public Ui_changeRateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGERATEDIALOG_H
