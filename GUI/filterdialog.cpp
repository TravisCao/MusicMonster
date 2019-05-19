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

QString FilterDialog::getHighLowShelfFreq()
{
    return ui_HighLowShelf->freq->text();
}

QString FilterDialog::getHighLowShelfSpan()
{
    return ui_HighLowShelf->span->text();
}

QString FilterDialog::getBandNotchFreq()
{
    return ui_BandNotch->freq->text();
}

QString FilterDialog::getBandNotchSpan()
{
    return ui_BandNotch->span->text();
}

QString FilterDialog::getHighLowShelfGain()
{
    return ui_HighLowShelf->gain->text();
}

QString FilterDialog::getHighLowPassCutoff()
{
    return ui_highlowPass->cutoff->text();
}

QString FilterDialog::getHighLowPassResonance()
{
    return ui_highlowPass->resonance->text();
}

