/********************************************************************************
** Form generated from reading UI file 'highlowshelfdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHLOWSHELFDIALOG_H
#define UI_HIGHLOWSHELFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_HighLowShelfDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *freq;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *span;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QDoubleSpinBox *gain;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HighLowShelfDialog)
    {
        if (HighLowShelfDialog->objectName().isEmpty())
            HighLowShelfDialog->setObjectName(QString::fromUtf8("HighLowShelfDialog"));
        HighLowShelfDialog->resize(400, 300);
        gridLayout = new QGridLayout(HighLowShelfDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(HighLowShelfDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        freq = new QDoubleSpinBox(HighLowShelfDialog);
        freq->setObjectName(QString::fromUtf8("freq"));
        freq->setMaximum(400.000000000000000);

        gridLayout->addWidget(freq, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(HighLowShelfDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        span = new QDoubleSpinBox(HighLowShelfDialog);
        span->setObjectName(QString::fromUtf8("span"));
        span->setMaximum(100.000000000000000);

        gridLayout->addWidget(span, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label_3 = new QLabel(HighLowShelfDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        gain = new QDoubleSpinBox(HighLowShelfDialog);
        gain->setObjectName(QString::fromUtf8("gain"));
        gain->setMinimum(-120.000000000000000);
        gain->setMaximum(120.000000000000000);

        gridLayout->addWidget(gain, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        buttonBox = new QDialogButtonBox(HighLowShelfDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 3);

        retranslateUi(HighLowShelfDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HighLowShelfDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HighLowShelfDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HighLowShelfDialog);
    } // setupUi

    void retranslateUi(QDialog *HighLowShelfDialog)
    {
        HighLowShelfDialog->setWindowTitle(QApplication::translate("HighLowShelfDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("HighLowShelfDialog", "Frequancy (Hz)", nullptr));
        label_2->setText(QApplication::translate("HighLowShelfDialog", "Span (Hz)", nullptr));
        label_3->setText(QApplication::translate("HighLowShelfDialog", "Gain (db)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HighLowShelfDialog: public Ui_HighLowShelfDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHLOWSHELFDIALOG_H
