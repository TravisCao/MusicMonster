#include "filterdialog.h"
#include "ui_bandnotchdialog.h"
#include "ui_highlowshelfdialog.h"
#include "ui_filterhighlowpassdialog.h"

#include <QDialog>
#include <QWidget>
#include <QProcess>
#include <QtGlobal>

FilterDialog::FilterDialog(QWidget *parent) : QDialog(parent), ui_HighLowShelf(new Ui::HighLowShelfDialog),
    ui_BandNotch(new Ui::BandNotchDialog), ui_highlowPass(new Ui::HighLowPassDialog)
{

}

void FilterDialog::showHighLowShelf()
{
    if (this->layout() == nullptr) ui_HighLowShelf->setupUi(this);
    show();
}

void FilterDialog::showBandNotch()
{
    if (this->layout() == nullptr) ui_BandNotch->setupUi(this);
    show();
}

void FilterDialog::showHighLowPass()
{
    if (this->layout() == nullptr) ui_highlowPass->setupUi(this);
    show();
}

void FilterDialog::highPass()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif


}

void FilterDialog::lowPass()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}

void FilterDialog::bandPass()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}

void FilterDialog::peaking()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}

void FilterDialog::notch()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}

void FilterDialog::lowShelf()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}

void FilterDialog::highShelf()
{
    QStringList args;  //如果需要启动参数的话

#ifdef Q_OS_WIN

    QProcess::startDetached("/Users/travis/Documents/MusicMonster/a.exe", args);

#endif

#ifdef Q_OS_MAC

    QProcess proc;

    proc.start("/Users/travis/Documents/MusicMonster/Filter/a.out", args);

    proc.waitForFinished(-1);  //

#endif
}


