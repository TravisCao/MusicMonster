/********************************************************************************
** Form generated from reading UI file 'savefiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFILEDIALOG_H
#define UI_SAVEFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_saveAsDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *nameEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLineEdit *locationEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *browse;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *saveAsDialog)
    {
        if (saveAsDialog->objectName().isEmpty())
            saveAsDialog->setObjectName(QString::fromUtf8("saveAsDialog"));
        saveAsDialog->resize(400, 300);
        saveAsDialog->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(saveAsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 2);

        label = new QLabel(saveAsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        nameEdit = new QLineEdit(saveAsDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 3, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(47, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        label_2 = new QLabel(saveAsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        locationEdit = new QLineEdit(saveAsDialog);
        locationEdit->setObjectName(QString::fromUtf8("locationEdit"));

        gridLayout->addWidget(locationEdit, 1, 3, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        browse = new QPushButton(saveAsDialog);
        browse->setObjectName(QString::fromUtf8("browse"));

        horizontalLayout->addWidget(browse);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 1, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(166, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 4);

        buttonBox = new QDialogButtonBox(saveAsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 4, 1, 2);


        retranslateUi(saveAsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), saveAsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), saveAsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(saveAsDialog);
    } // setupUi

    void retranslateUi(QDialog *saveAsDialog)
    {
        saveAsDialog->setWindowTitle(QApplication::translate("saveAsDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("saveAsDialog", "Name", nullptr));
        label_2->setText(QApplication::translate("saveAsDialog", "Location", nullptr));
        browse->setText(QApplication::translate("saveAsDialog", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveAsDialog: public Ui_saveAsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFILEDIALOG_H
