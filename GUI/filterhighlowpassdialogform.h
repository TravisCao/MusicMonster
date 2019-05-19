/********************************************************************************
** Form generated from reading UI file 'filterhighlowpassdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERHIGHLOWPASSDIALOG_H
#define UI_FILTERHIGHLOWPASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_HighLowPassDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *cutoff;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpinBox *resonance;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HighLowPassDialog)
    {
        if (HighLowPassDialog->objectName().isEmpty())
            HighLowPassDialog->setObjectName(QString::fromUtf8("HighLowPassDialog"));
        HighLowPassDialog->resize(400, 300);
        gridLayout = new QGridLayout(HighLowPassDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(HighLowPassDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cutoff = new QDoubleSpinBox(HighLowPassDialog);
        cutoff->setObjectName(QString::fromUtf8("cutoff"));
        cutoff->setMaximum(400.000000000000000);

        gridLayout->addWidget(cutoff, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(HighLowPassDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        resonance = new QSpinBox(HighLowPassDialog);
        resonance->setObjectName(QString::fromUtf8("resonance"));
        resonance->setMaximum(100);

        gridLayout->addWidget(resonance, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(HighLowPassDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 3);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 2);

        retranslateUi(HighLowPassDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HighLowPassDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HighLowPassDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HighLowPassDialog);
    } // setupUi

    void retranslateUi(QDialog *HighLowPassDialog)
    {
        HighLowPassDialog->setWindowTitle(QApplication::translate("HighLowPassDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("HighLowPassDialog", "Cutoff(Hz)", nullptr));
        label_2->setText(QApplication::translate("HighLowPassDialog", "Resonance(Hz)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HighLowPassDialog: public Ui_HighLowPassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERHIGHLOWPASSDIALOG_H
