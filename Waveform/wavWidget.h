#ifndef _WAV_WIDGET_H_
#define _WAV_WIDGET_H_

#include <QWidget>
using namespace std;

class WavWidget : public QWidget
{
	Q_OBJECT

public:
	WavWidget(QWidget *parent = 0);
	virtual ~WavWidget();

	void setFile(QString filepath);

protected slots:


private:
	void paintEvent(QPaintEvent* event);	
	vector<float> fourier_analyze(const vector<float> &time_samples, float sample_rate, uint64_t zero_pad_multiplier);	

	vector<float> m_data;
	vector<float> m_freq;	

	float m_sampleRate;
};




#endif