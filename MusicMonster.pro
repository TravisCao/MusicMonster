#-------------------------------------------------
#
# Project created by QtCreator 2019-05-04T20:16:00
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicMonster
TEMPLATE = app
ICON =  final.icns

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    GUI/audio.cpp \
    GUI/changefactor.cpp \
    GUI/effecthistorywidget.cpp \
    GUI/filewidget.cpp \
    GUI/mainwindow.cpp \
    GUI/newfiledialog.cpp \
    DataProcessing/readwav.cpp \
    GUI/saveasfiledialog.cpp \
    Filter/decon.cpp \
    Filter/filter.cpp \
    Filter/WavIO.cpp \
    Filter/cell.cpp \
    GUI/filterdialog.cpp


HEADERS += \
    GUI/audio.h \
    GUI/changefactor.h \
    GUI/effecthistorywidget.h \
    GUI/filewidget.h \
    GUI/mainwindow.h \
    GUI/newfiledialog.h \
    DataProcessing/readwav.h \
    GUI/saveasfiledialog.h \
    Filter/filter.h \
    Filter/wavio.h \
    Filter/cell.h \
    Filter/decon.h \
    GUI/filterdialog.h \
    DataProcessing/mmrate.h

FORMS += \
    GUI/newdialogForm.ui \
    GUI/mainwindowForm.ui \
    GUI/changefactordialog.ui \
    GUI/effecthistorywidget.ui \
    GUI/savefiledialog.ui \
    GUI/filterhighlowpassdialog.ui \
    GUI/bandnotchdialog.ui \
    GUI/highlowshelfdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /Users/travis/Documents/MusicMonster/DataProcessing
INCLUDEPATH += /Users/travis/Documents/MusicMonster/GUI
INCLUDEPATH += /Users/travis/Documents/MusicMonster/Filter
INCLUDEPATH += /Users/travis/Documents/MusicMonster/VersionForTest

RESOURCES += \
    images.qrc

SUBDIRS += \
    MusicMonster.pro

