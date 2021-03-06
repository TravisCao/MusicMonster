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
    GUI/filewidget.cpp \
    GUI/mainwindow.cpp \
    GUI/newfiledialog.cpp \
    DataProcessing/readwav.cpp \
    GUI/saveasfiledialog.cpp \
    Filter/decon.cpp \
    Filter/filter.cpp \
    Filter/WavIO.cpp \
    Filter/cell.cpp \
    GUI/filterdialog.cpp \
    changerate1.cpp \
    GUI/changepitch.cpp \
    GUI/playbackdialog.cpp \
    Waveform/wavWidget.cpp \
    Waveform/fft.cpp \
    GUI/cutdialog.cpp


HEADERS += \
    GUI/audio.h \
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
    DataProcessing/mmrate.h \
    changerate1.h \
    GUI/changepitch.h \
    GUI/playbackdialog.h \
    DataProcessing/mmtempo.h \
    Waveform/wavWidget.h \
    Waveform/fft.h \
    GUI/cutdialog.h

FORMS += \
    GUI/newdialogForm.ui \
    GUI/mainwindowForm.ui \
    GUI/savefiledialog.ui \
    GUI/filterhighlowpassdialog.ui \
    changerate1.ui \
    GUI/changepitch.ui \
    GUI/playbackdialog.ui \
    GUI/highlowshelfdialog.ui \
    GUI/bandnotchdialog.ui \
    GUI/cutdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/DataProcessing
INCLUDEPATH += $$PWD/GUI
INCLUDEPATH += $$PWD/Filter
INCLUDEPATH += $$PWD/VersionForTest
INCLUDEPATH += $$PWD/Waveform


RESOURCES += \
    images.qrc \
    Waveform/wavDraw.qrc

SUBDIRS += \
    MusicMonster.pro

