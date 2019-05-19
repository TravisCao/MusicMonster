#include "wavWidget.h"
#include "fft.h"	
#include <QPainter>
#include "readwav.h"

WavWidget::WavWidget(QWidget *parent)
	:QWidget(parent)
{	
}

WavWidget::~WavWidget()
{
}

void WavWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::white);

	int x_offset = 10;
	int y_offset = 10;
	int y_space = 20;
	if (m_freq.size() != 0)
	{
		int w = width();
		int h = height() - y_space - y_offset * 2;		
		int freq_h = h / 4 * 3;
		int wav_h = h - freq_h;
		int freq_y = y_offset;
		int line_y = y_offset + freq_h + y_space / 2;
		int wav_y = y_offset + freq_h + y_space;

		//设fs为采样频率，fft长度为N， 那么频率分辨率为fs/N, 如果N增加那么频率分辨率增加。这是下面一篇文章的用的论据
		int num_samples_x = ceil_exp2(m_data.size()); //fft 点数
		float length_x = m_data.size() / m_sampleRate;      //总样本 / 采样率 = 时间 
		float time_res = length_x / (num_samples_x - 1);  //时间分辨率
		float freq_res = 1.0f / length_x;                 //频率分辨率		

		//声音作为一种波，频率在20 Hz~20 kHz之间的声音是可以被人耳识别的。
		float start_freq = 0;      //显示起始频率
        float end_freq = 200;    //显示截止频率

		//freq		
		vector<float> freqs;		
		float max_freq = *std::max_element(m_freq.begin(), m_freq.end());
		int s = start_freq / freq_res, e = end_freq / freq_res;
		e = min(e, (int)m_freq.size());
		
		int x_gap = (e - s) / (w - x_offset * 2);
		for (int i = s; i < e; i += x_gap)
		{
			int size = i + x_gap < e ? x_gap : e - i;
			float max = *std::max_element(m_freq.begin() + i, m_freq.begin() + i + size);		
			freqs.push_back(max);
		}		

		QVector<QPoint> points;		
		float min_freq = *std::min_element(freqs.begin(), freqs.end());
		float max_gap = (max_freq - min_freq);
		for (int i = 0; i < freqs.size(); i++)
		{
			int x = x_offset + i;
			int y = (freqs[i] - min_freq) / max_gap * freq_h;
			y = freq_h - y + freq_y;

			points.push_back(QPoint(x, y));
		}
		
		painter.setPen(QPen(QBrush(qRgb(79,146,128)),2));
		for (int i = 0; i < points.size() - 1; i++)
			painter.drawLine(points[i], points[i + 1]);

		painter.setPen(qRgb(225, 225, 225));
		painter.drawLine(QPoint(x_offset, line_y), QPoint(w - x_offset, line_y));

		//wav	
		x_gap = m_freq.size() / (w - x_offset * 2);

		painter.setPen(qRgb(75, 173, 248));
		for (int i = 0,i_x = 0; i < m_data.size(); i += x_gap, i_x++)
		{
			int size = i + x_gap < m_data.size() ? x_gap : m_data.size() - i;			

			float max_wav = *std::max_element(m_data.begin() + i, m_data.begin() + i + size);
			float min_wav = *std::min_element(m_data.begin() + i, m_data.begin() + i + size);

			int max_l = int(max_wav * wav_h);
			int min_l = int(abs(min_wav) * wav_h);
			int x = x_offset + i_x;
			int cy = wav_y + wav_h/2;

			painter.drawLine(QPoint(x, cy - max_l / 2), QPoint(x, cy + min_l / 2));
		}		
	}
}

void WavWidget::setFile(QString filepath)
{
	m_data.clear();
	m_freq.clear();

	WavInFile file(filepath.toLocal8Bit().data());	
	file.read();	

	int len = file.buffer.getDataNum();
	float *ptr = file.buffer.pData;
	for (int i = 0; i < len; i++)
		m_data.push_back(ptr[i]);

	m_sampleRate = file.getSampleRate();
	m_freq = fourier_analyze(m_data, m_sampleRate, 1);
	
	update();
}

vector<float> WavWidget::fourier_analyze(const vector<float> &time_samples, float sample_rate, uint64_t zero_pad_multiplier)
{
	int num_samples_x = ceil_exp2(time_samples.size()) * zero_pad_multiplier;
	float length_x = time_samples.size() / sample_rate;      //总样本 / 采样率 = 时间 
	float time_res = length_x / (num_samples_x - 1);  //时间分辨率
	float freq_res = 1.0f / length_x;                 //频率分辨率

	vector<float> __time_samples = time_samples;
	__time_samples.resize(num_samples_x, 0);
	
	vector<float> freq_samples = fft(__time_samples);
	freq_samples.resize(m_data.size());	

	return freq_samples;
}
