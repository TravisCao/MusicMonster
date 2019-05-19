/********************************************************************************
** Form generated from reading UI file 'cutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTDIALOG_H
#define UI_CUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_cutDialog
{
public:
    QGridLayout *gridLayout;
    QTimeEdit *timebegin;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QTimeEdit *timeend;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *cutDialog)
    {
        if (cutDialog->objectName().isEmpty())
            cutDialog->setObjectName(QString::fromUtf8("cutDialog"));
        cutDialog->resize(400, 300);
        gridLayout = new QGridLayout(cutDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        timebegin = new QTimeEdit(cutDialog);
        timebegin->setObjectName(QString::fromUtf8("timebegin"));

        gridLayout->addWidget(timebegin, 0, 2, 1, 1);

        label_2 = new QLabel(cutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        buttonBox = new QDialogButtonBox(cutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 3);

        timeend = new QTimeEdit(cutDialog);
        timeend->setObjectName(QString::fromUtf8("timeend"));

        gridLayout->addWidget(timeend, 1, 2, 1, 1);

        label = new QLabel(cutDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnMinimumWidth(0, 1);
        gridLayout->setColumnMinimumWidth(1, 2);
        gridLayout->setColumnMinimumWidth(2, 1);

        retranslateUi(cutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), cutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(cutDialog);
    } // setupUi

    void retranslateUi(QDialog *cutDialog)
    {
        cutDialog->setWindowTitle(QApplication::translate("cutDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("cutDialog", "Time end:", nullptr));
        label->setText(QApplication::translate("cutDialog", "Time begin:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cutDialog: public Ui_cutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTDIALOG_H
