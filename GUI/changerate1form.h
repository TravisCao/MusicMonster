/********************************************************************************
** Form generated from reading UI file 'changerate1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGERATE1_H
#define UI_CHANGERATE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeRate1
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QDialog *ChangeRate1)
    {
        if (ChangeRate1->objectName().isEmpty())
            ChangeRate1->setObjectName(QString::fromUtf8("ChangeRate1"));
        ChangeRate1->resize(400, 300);
        buttonBox = new QDialogButtonBox(ChangeRate1);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ChangeRate1);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 120, 321, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        retranslateUi(ChangeRate1);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeRate1, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeRate1, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeRate1);
    } // setupUi

    void retranslateUi(QDialog *ChangeRate1)
    {
        ChangeRate1->setWindowTitle(QApplication::translate("ChangeRate1", "Dialog", nullptr));
        label->setText(QApplication::translate("ChangeRate1", "Change rate:", nullptr));
        label_2->setText(QApplication::translate("ChangeRate1", "times", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeRate1: public Ui_ChangeRate1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGERATE1_H
