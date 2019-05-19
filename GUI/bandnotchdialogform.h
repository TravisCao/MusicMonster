/********************************************************************************
** Form generated from reading UI file 'bandnotchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANDNOTCHDIALOG_H
#define UI_BANDNOTCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BandNotchDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *freq;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *span;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BandNotchDialog)
    {
        if (BandNotchDialog->objectName().isEmpty())
            BandNotchDialog->setObjectName(QString::fromUtf8("BandNotchDialog"));
        BandNotchDialog->resize(400, 300);
        gridLayout = new QGridLayout(BandNotchDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BandNotchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        freq = new QDoubleSpinBox(BandNotchDialog);
        freq->setObjectName(QString::fromUtf8("freq"));
        freq->setMaximum(400.000000000000000);

        gridLayout->addWidget(freq, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(BandNotchDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        span = new QDoubleSpinBox(BandNotchDialog);
        span->setObjectName(QString::fromUtf8("span"));
        span->setMaximum(100.000000000000000);

        gridLayout->addWidget(span, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(BandNotchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 3);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 3);

        retranslateUi(BandNotchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BandNotchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BandNotchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BandNotchDialog);
    } // setupUi

    void retranslateUi(QDialog *BandNotchDialog)
    {
        BandNotchDialog->setWindowTitle(QApplication::translate("BandNotchDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("BandNotchDialog", "Frequency(Hz)", nullptr));
        label_2->setText(QApplication::translate("BandNotchDialog", "Span(Hz)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BandNotchDialog: public Ui_BandNotchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANDNOTCHDIALOG_H
