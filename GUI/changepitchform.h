/********************************************************************************
** Form generated from reading UI file 'changepitch.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPITCH_H
#define UI_CHANGEPITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changepitch
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *changepitch)
    {
        if (changepitch->objectName().isEmpty())
            changepitch->setObjectName(QString::fromUtf8("changepitch"));
        changepitch->resize(343, 199);
        buttonBox = new QDialogButtonBox(changepitch);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 160, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(changepitch);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 80, 231, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        retranslateUi(changepitch);
        QObject::connect(buttonBox, SIGNAL(accepted()), changepitch, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changepitch, SLOT(reject()));

        QMetaObject::connectSlotsByName(changepitch);
    } // setupUi

    void retranslateUi(QDialog *changepitch)
    {
        changepitch->setWindowTitle(QApplication::translate("changepitch", "Dialog", nullptr));
        label->setText(QApplication::translate("changepitch", "Change Pitch:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changepitch: public Ui_changepitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPITCH_H
