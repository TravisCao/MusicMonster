/********************************************************************************
** Form generated from reading UI file 'mainwindowForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWFORM_H
#define UI_MAINWINDOWFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionOpen_Recent;
    QAction *actionClose;
    QAction *actionClose_All;
    QAction *actionSave;
    QAction *actionSave_All;
    QAction *actionSave_As;
    QAction *actionImport_File;
    QAction *actionExport_File;
    QAction *actionundo;
    QAction *actionRedo;
    QAction *actionTime_Selection;
    QAction *actionRazor;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout_Music_Mosnter;
    QAction *actionChangeFactor;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *newButton;
    QPushButton *saveButton;
    QPushButton *openButton;
    QPushButton *deleteButton;
    QLabel *label;
    QLineEdit *searchLine;
    QTableView *tableView;
    QFrame *line_6;
    QTabWidget *subTabWidget;
    QWidget *effectTab;
    QHBoxLayout *horizontalLayout_3;
    QListView *effectList;
    QWidget *historyTab;
    QHBoxLayout *horizontalLayout_4;
    QListView *historyList;
    QWidget *mainWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *waveform;
    QSpacerItem *horizontalSpacer_3;
    QProgressBar *volumeBar;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *playloop;
    QPushButton *stop;
    QPushButton *slow;
    QPushButton *play;
    QPushButton *speed;
    QPushButton *record;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QLCDNumber *timeNow;
    QSlider *slider;
    QLCDNumber *timeTotal;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuAsbout;
    QMenu *menuEffect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1108, 777);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #3"
                        "43434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b"
                        "1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgb(42,42,42), stop: 0.1 rgb(42,42,42), stop: 0.5 #212121, stop: 0.9 rgb(42,42,42), stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #464646, stop: 0.1 #151515, stop: 0.5 #464646, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QL"
                        "inearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"    "
                        " image: url(:/down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2ox solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      w"
                        "idth: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"  "
                        "    background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QS"
                        "crollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0"
                        ", x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(35,35,35) , stop: 0.5 rgb(35,35,35), stop: 0.6 rgb(35,35,35), stop:1 rgb(35,35,35));\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(35,35,35), stop:0.5 rgb(35,35,35) stop:1 rgb(35,35,35));\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar"
                        "::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
""
                        "{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1"
                        ";\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}\n"
"\n"
"QLine\n"
"{\n"
"  color: rgb(158, 158, 158)\n"
"}\n"
"\n"
"QProgressBar {\n"
"  color: rgb(240, 240, 240);\n"
"  border-width: 1px; \n"
"  border-radius: 10px"
                        ";\n"
"  border-color: rgb(58, 58, 58);\n"
"  background-color:#484848;\n"
"}\n"
"QProgressBar::chunk {\n"
"  background-color:#ffaa00;\n"
"  border-radius: 5px;\n"
"}\n"
"\n"
"QTreeView,\n"
"QListView,\n"
"QTableView,\n"
"QColumnView {\n"
"  background-color: #19232D;\n"
"  border: 1px solid #32414B;\n"
"  color: #F0F0F0;\n"
"  gridline-color: #32414B;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTreeView:disabled,\n"
"QListView:disabled,\n"
"QTableView:disabled,\n"
"QColumnView:disabled {\n"
"  background-color: #19232D;\n"
"  color: #787878;\n"
"}\n"
"\n"
"QTreeView:selected,\n"
"QListView:selected,\n"
"QTableView:selected,\n"
"QColumnView:selected {\n"
"  background: #1464A0;\n"
"  color: #32414B;\n"
"}\n"
"\n"
"QTreeView::hover,\n"
"QListView::hover,\n"
"QTableView::hover,\n"
"QColumnView::hover {\n"
"  background-color: #19232D;\n"
"  border: 1px solid #148CD2;\n"
"}\n"
"\n"
"QTreeView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTableView::item:pressed,\n"
"QColumnView::item:pressed {\n"
"  background-c"
                        "olor: #1464A0;\n"
"}\n"
"\n"
"QTreeView::item:selected:hover,\n"
"QListView::item:selected:hover,\n"
"QTableView::item:selected:hover,\n"
"QColumnView::item:selected:hover {\n"
"  background: #1464A0;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active,\n"
"QTableView::item:selected:active,\n"
"QColumnView::item:selected:active {\n"
"  background-color: #1464A0;\n"
"}\n"
"\n"
"QTreeView::item:!selected:hover,\n"
"QListView::item:!selected:hover,\n"
"QTableView::item:!selected:hover,\n"
"QColumnView::item:!selected:hover {\n"
"  outline: 0;\n"
"  color: #148CD2;\n"
"  background-color: #32414B;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"  background-color: #19232D;\n"
"  border: 1px transparent #32414B;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color: #ffaa00\n"
"}"));
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_Recent = new QAction(MainWindow);
        actionOpen_Recent->setObjectName(QString::fromUtf8("actionOpen_Recent"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose_All = new QAction(MainWindow);
        actionClose_All->setObjectName(QString::fromUtf8("actionClose_All"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionImport_File = new QAction(MainWindow);
        actionImport_File->setObjectName(QString::fromUtf8("actionImport_File"));
        actionExport_File = new QAction(MainWindow);
        actionExport_File->setObjectName(QString::fromUtf8("actionExport_File"));
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QString::fromUtf8("actionundo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionTime_Selection = new QAction(MainWindow);
        actionTime_Selection->setObjectName(QString::fromUtf8("actionTime_Selection"));
        actionRazor = new QAction(MainWindow);
        actionRazor->setObjectName(QString::fromUtf8("actionRazor"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionAbout_Music_Mosnter = new QAction(MainWindow);
        actionAbout_Music_Mosnter->setObjectName(QString::fromUtf8("actionAbout_Music_Mosnter"));
        actionChangeFactor = new QAction(MainWindow);
        actionChangeFactor->setObjectName(QString::fromUtf8("actionChangeFactor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 12, 12, 0);
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newButton = new QPushButton(groupBox);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/openFile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);

        horizontalLayout->addWidget(newButton);

        saveButton = new QPushButton(groupBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
        saveButton->setStyleSheet(QString::fromUtf8(""));
        saveButton->setText(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/newFile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);

        horizontalLayout->addWidget(saveButton);

        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/importFile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon2);

        horizontalLayout->addWidget(openButton);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/delete.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(deleteButton);


        horizontalLayout_5->addLayout(horizontalLayout);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:rgb(57,57,57);\n"
"}\n"
""));
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        searchLine = new QLineEdit(groupBox);
        searchLine->setObjectName(QString::fromUtf8("searchLine"));
        searchLine->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(searchLine);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 3);

        verticalLayout_6->addLayout(horizontalLayout_5);

        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_6->addWidget(tableView);


        verticalLayout_7->addLayout(verticalLayout_6);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_6);


        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addWidget(widget);

        subTabWidget = new QTabWidget(widget_4);
        subTabWidget->setObjectName(QString::fromUtf8("subTabWidget"));
        subTabWidget->setTabShape(QTabWidget::Rounded);
        subTabWidget->setDocumentMode(false);
        subTabWidget->setTabsClosable(false);
        subTabWidget->setTabBarAutoHide(true);
        effectTab = new QWidget();
        effectTab->setObjectName(QString::fromUtf8("effectTab"));
        horizontalLayout_3 = new QHBoxLayout(effectTab);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        effectList = new QListView(effectTab);
        effectList->setObjectName(QString::fromUtf8("effectList"));

        horizontalLayout_3->addWidget(effectList);

        subTabWidget->addTab(effectTab, QString());
        historyTab = new QWidget();
        historyTab->setObjectName(QString::fromUtf8("historyTab"));
        horizontalLayout_4 = new QHBoxLayout(historyTab);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        historyList = new QListView(historyTab);
        historyList->setObjectName(QString::fromUtf8("historyList"));

        horizontalLayout_4->addWidget(historyList);

        subTabWidget->addTab(historyTab, QString());

        verticalLayout_2->addWidget(subTabWidget);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 4);

        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_8->addWidget(widget_4);

        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setStyleSheet(QString::fromUtf8("QWidget#mainWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-color: #ffa02f;\n"
"    border-width: 1px;\n"
"}\n"
"\n"
"QWidget#mainWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"    color: #ffa02f;\n"
"}\n"
""));
        gridLayout = new QGridLayout(mainWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(-1);
        gridLayout->setContentsMargins(5, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        waveform = new QPushButton(mainWidget);
        waveform->setObjectName(QString::fromUtf8("waveform"));
        waveform->setStyleSheet(QString::fromUtf8("QPushButton#waveform\n"
"{\n"
"	background-color: rgb(16,25,25);\n"
"	border-width: 1;\n"
"	border-radius: 5;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/waveform!.png"), QSize(), QIcon::Normal, QIcon::Off);
        waveform->setIcon(icon4);
        waveform->setIconSize(QSize(88, 20));
        waveform->setCheckable(true);
        waveform->setChecked(true);

        horizontalLayout_2->addWidget(waveform);


        horizontalLayout_10->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(578, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        volumeBar = new QProgressBar(mainWidget);
        volumeBar->setObjectName(QString::fromUtf8("volumeBar"));
        volumeBar->setValue(23);
        volumeBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        volumeBar->setTextVisible(false);
        volumeBar->setOrientation(Qt::Vertical);
        volumeBar->setInvertedAppearance(false);
        volumeBar->setTextDirection(QProgressBar::BottomToTop);

        gridLayout->addWidget(volumeBar, 0, 1, 4, 1);

        widget_2 = new QWidget(mainWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        groupBox_3 = new QGroupBox(mainWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        playloop = new QPushButton(groupBox_3);
        playloop->setObjectName(QString::fromUtf8("playloop"));
        playloop->setMaximumSize(QSize(30, 30));
        playloop->setSizeIncrement(QSize(0, 0));
        playloop->setBaseSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/playloop.png"), QSize(), QIcon::Normal, QIcon::Off);
        playloop->setIcon(icon5);
        playloop->setIconSize(QSize(20, 20));
        playloop->setCheckable(true);

        horizontalLayout_6->addWidget(playloop);

        stop = new QPushButton(groupBox_3);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon6);
        stop->setIconSize(QSize(20, 20));

        horizontalLayout_6->addWidget(stop);

        slow = new QPushButton(groupBox_3);
        slow->setObjectName(QString::fromUtf8("slow"));
        slow->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/slow.png"), QSize(), QIcon::Normal, QIcon::Off);
        slow->setIcon(icon7);
        slow->setIconSize(QSize(20, 20));

        horizontalLayout_6->addWidget(slow);

        play = new QPushButton(groupBox_3);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon8);
        play->setIconSize(QSize(20, 20));
        play->setCheckable(true);
        play->setChecked(false);

        horizontalLayout_6->addWidget(play);

        speed = new QPushButton(groupBox_3);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setMaximumSize(QSize(30, 30));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/speed.png"), QSize(), QIcon::Normal, QIcon::Off);
        speed->setIcon(icon9);
        speed->setIconSize(QSize(20, 21));

        horizontalLayout_6->addWidget(speed);

        record = new QPushButton(groupBox_3);
        record->setObjectName(QString::fromUtf8("record"));
        record->setMaximumSize(QSize(30, 30));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        record->setIcon(icon10);
        record->setIconSize(QSize(20, 20));

        horizontalLayout_6->addWidget(record);


        horizontalLayout_7->addWidget(groupBox_3);

        horizontalSpacer_2 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        timeNow = new QLCDNumber(mainWidget);
        timeNow->setObjectName(QString::fromUtf8("timeNow"));
        timeNow->setStyleSheet(QString::fromUtf8(""));
        timeNow->setFrameShape(QFrame::Box);
        timeNow->setFrameShadow(QFrame::Raised);
        timeNow->setDigitCount(7);
        timeNow->setSegmentStyle(QLCDNumber::Filled);

        horizontalLayout_9->addWidget(timeNow);

        slider = new QSlider(mainWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMaximum(100);
        slider->setPageStep(100);
        slider->setValue(0);
        slider->setSliderPosition(0);
        slider->setOrientation(Qt::Horizontal);
        slider->setInvertedAppearance(false);
        slider->setInvertedControls(true);
        slider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_9->addWidget(slider);

        timeTotal = new QLCDNumber(mainWidget);
        timeTotal->setObjectName(QString::fromUtf8("timeTotal"));
        timeTotal->setFrameShape(QFrame::Box);

        horizontalLayout_9->addWidget(timeTotal);


        gridLayout->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 20);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);

        horizontalLayout_8->addWidget(mainWidget);

        horizontalLayout_8->setStretch(0, 2);
        horizontalLayout_8->setStretch(1, 5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1108, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuEdit);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuAsbout = new QMenu(menuBar);
        menuAsbout->setObjectName(QString::fromUtf8("menuAsbout"));
        menuEffect = new QMenu(menuBar);
        menuEffect->setObjectName(QString::fromUtf8("menuEffect"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAsbout->menuAction());
        menuBar->addAction(menuEffect->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Recent);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_All);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionImport_File);
        menuFile->addAction(actionExport_File);
        menuFile->addSeparator();
        menuEdit->addAction(actionundo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(menuTools->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuTools->addAction(actionTime_Selection);
        menuTools->addAction(actionRazor);
        menuAsbout->addAction(actionAbout_Music_Mosnter);
        menuEffect->addSeparator();
        menuEffect->addAction(actionChangeFactor);

        retranslateUi(MainWindow);

        deleteButton->setDefault(false);
        subTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MusicMonster", nullptr));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>This MusicMonster</p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen_Recent->setText(QApplication::translate("MainWindow", "Open Recent", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_All->setText(QApplication::translate("MainWindow", "Close All", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_All->setText(QApplication::translate("MainWindow", "Save All", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionImport_File->setText(QApplication::translate("MainWindow", "Import File", nullptr));
        actionExport_File->setText(QApplication::translate("MainWindow", "Export File", nullptr));
        actionundo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionundo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionTime_Selection->setText(QApplication::translate("MainWindow", "Time Selection", nullptr));
        actionRazor->setText(QApplication::translate("MainWindow", "Razor", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_Music_Mosnter->setText(QApplication::translate("MainWindow", "About Music Mosnter", nullptr));
        actionChangeFactor->setText(QApplication::translate("MainWindow", "ChangeFactor", nullptr));
        groupBox->setTitle(QString());
        newButton->setText(QString());
        openButton->setText(QString());
        deleteButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#1293ff;\">Find:</span></p></body></html>", nullptr));
        searchLine->setPlaceholderText(QString());
        subTabWidget->setTabText(subTabWidget->indexOf(effectTab), QApplication::translate("MainWindow", "Effect", nullptr));
        subTabWidget->setTabText(subTabWidget->indexOf(historyTab), QApplication::translate("MainWindow", "History", nullptr));
        waveform->setText(QString());
        groupBox_3->setTitle(QString());
        playloop->setText(QString());
        stop->setText(QString());
        slow->setText(QString());
        play->setText(QString());
        speed->setText(QString());
        record->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuAsbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
        menuEffect->setTitle(QApplication::translate("MainWindow", "Effect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWFORM_H
