#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QWidget>
#include <QDialog>

namespace Ui {
    class BandNotchDialog;
    class HighLowPassDialog;
    class HighLowShelfDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FilterDialog(QWidget *parent = nullptr);

signals:

public slots:

    void showHighLowShelf();

    void showBandNotch();

    void showHighLowPass();

    QString getBandNotchFreq();

    QString getBandNotchSpan();

    QString getHighLowShelfFreq();

    QString getHighLowShelfSpan();

    QString getHighLowShelfGain();

    QString getHighLowPassCutoff();

    QString getHighLowPassResonance();


private:
    Ui::HighLowShelfDialog *ui_HighLowShelf; // 3
    Ui::BandNotchDialog *ui_BandNotch; // 2
    Ui::HighLowPassDialog *ui_highlowPass; //2
};

#endif // FILTERDIALOG_H
