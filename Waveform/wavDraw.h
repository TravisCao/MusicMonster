#ifndef _WAV_DRAW_H_
#define _WAV_DRAW_H_

#include <QtWidgets/QMainWindow>
#include "fft.h"

using namespace std;

class wavDraw : public QMainWindow
{
	Q_OBJECT

public:
	wavDraw(QWidget *parent = Q_NULLPTR);

};

#endif
