/********************************************************************************
** Form generated from reading UI file 'playbackdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYBACKDIALOG_H
#define UI_PLAYBACKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playbackDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QDialog *playbackDialog)
    {
        if (playbackDialog->objectName().isEmpty())
            playbackDialog->setObjectName(QString::fromUtf8("playbackDialog"));
        playbackDialog->resize(380, 252);
        buttonBox = new QDialogButtonBox(playbackDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(playbackDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 90, 281, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        retranslateUi(playbackDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), playbackDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), playbackDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(playbackDialog);
    } // setupUi

    void retranslateUi(QDialog *playbackDialog)
    {
        playbackDialog->setWindowTitle(QApplication::translate("playbackDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("playbackDialog", "Set playback rate:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playbackDialog: public Ui_playbackDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYBACKDIALOG_H
