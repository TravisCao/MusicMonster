/********************************************************************************
** Form generated from reading UI file 'effecthistorywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFECTHISTORYWIDGET_H
#define UI_EFFECTHISTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *subTabWidget;
    QWidget *effectTab;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView_1;
    QWidget *historyTab;
    QHBoxLayout *horizontalLayout_4;
    QListView *listView_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        subTabWidget = new QTabWidget(Form);
        subTabWidget->setObjectName(QString::fromUtf8("subTabWidget"));
        effectTab = new QWidget();
        effectTab->setObjectName(QString::fromUtf8("effectTab"));
        horizontalLayout_3 = new QHBoxLayout(effectTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        listView_1 = new QListView(effectTab);
        listView_1->setObjectName(QString::fromUtf8("listView_1"));

        horizontalLayout_3->addWidget(listView_1);

        subTabWidget->addTab(effectTab, QString());
        historyTab = new QWidget();
        historyTab->setObjectName(QString::fromUtf8("historyTab"));
        horizontalLayout_4 = new QHBoxLayout(historyTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        listView_2 = new QListView(historyTab);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        horizontalLayout_4->addWidget(listView_2);

        subTabWidget->addTab(historyTab, QString());

        horizontalLayout->addWidget(subTabWidget);


        retranslateUi(Form);

        subTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        subTabWidget->setTabText(subTabWidget->indexOf(effectTab), QApplication::translate("Form", "Effect", nullptr));
        subTabWidget->setTabText(subTabWidget->indexOf(historyTab), QApplication::translate("Form", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFECTHISTORYWIDGET_H
