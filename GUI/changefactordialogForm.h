/********************************************************************************
** Form generated from reading UI file 'changefactordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEFACTORDIALOG_H
#define UI_CHANGEFACTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_changeDialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *ratebox;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label;
    QComboBox *pitchbox;
    QLabel *label_5;
    QComboBox *tempobox;
    QLabel *label_3;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *changeDialog)
    {
        if (changeDialog->objectName().isEmpty())
            changeDialog->setObjectName(QString::fromUtf8("changeDialog"));
        changeDialog->resize(434, 344);
        changeDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(changeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ratebox = new QComboBox(changeDialog);
        ratebox->setObjectName(QString::fromUtf8("ratebox"));

        gridLayout->addWidget(ratebox, 0, 1, 1, 1);

        label_7 = new QLabel(changeDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_6 = new QLabel(changeDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label = new QLabel(changeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pitchbox = new QComboBox(changeDialog);
        pitchbox->setObjectName(QString::fromUtf8("pitchbox"));

        gridLayout->addWidget(pitchbox, 2, 1, 1, 1);

        label_5 = new QLabel(changeDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        tempobox = new QComboBox(changeDialog);
        tempobox->setObjectName(QString::fromUtf8("tempobox"));

        gridLayout->addWidget(tempobox, 1, 1, 1, 1);

        label_3 = new QLabel(changeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(changeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(changeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);


        retranslateUi(changeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), changeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeDialog);
    } // setupUi

    void retranslateUi(QDialog *changeDialog)
    {
        changeDialog->setWindowTitle(QApplication::translate("changeDialog", "Dialog", nullptr));
        label_7->setText(QApplication::translate("changeDialog", "times", nullptr));
        label_6->setText(QApplication::translate("changeDialog", "times", nullptr));
        label->setText(QApplication::translate("changeDialog", "Rate:", nullptr));
        label_5->setText(QApplication::translate("changeDialog", "times", nullptr));
        label_3->setText(QApplication::translate("changeDialog", "Pitch:", nullptr));
        label_2->setText(QApplication::translate("changeDialog", "Tempo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeDialog: public Ui_changeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEFACTORDIALOG_H
