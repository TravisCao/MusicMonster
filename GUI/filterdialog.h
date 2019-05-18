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

    void highPass();

    void lowPass();

    void bandPass();

    void peaking();

    void notch();

    void lowShelf();

    void highShelf();





private:
    Ui::HighLowShelfDialog *ui_HighLowShelf;
    Ui::BandNotchDialog *ui_BandNotch;
    Ui::HighLowPassDialog *ui_highlowPass;
};

#endif // FILTERDIALOG_H
