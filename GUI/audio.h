#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include <QAudioOutput>
#include <QAudioInput>
#include <QAudioFormat>
#include <QFile>
#include <QAudio>
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QPoint>
#include <QSlider>
#include <QLCDNumber>

class Audio : public QWidget
{
    Q_OBJECT

public:

    Audio(int sampleRate, int channelCount,QWidget *parent = nullptr); // new audio file

    Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent = nullptr); // open an existed file

    int getSampleRate();

    int getChannelCount();

signals:

    int musicStart();

public slots:

    void playAndPause(int index);

    QString getAudioDuration();

    void musicRecycle(bool flag);

    void musicSpeedUp();

    void musicRecoverSpeed();

    void musicSlowDown();

    void musicStop();

    void volumeControl(int volume);

    void positionUpdate(qint64 position, QSlider *slider, QLCDNumber *number);

    void record();

    bool isPlayListEmpty();

    void sliderChange(int position, QLCDNumber *number);

    void updateTimeNow(QLCDNumber *number, qint64 position);

private:

    QFile *destinationFile;

    bool recycleFlag;

    QMediaPlaylist *playList;

    QMediaPlayer *player;

    QAudioFormat *format;

    QAudioInput *audioInput;

    QAudioOutput *audioOutput;

    QTimer *timer;

    QString timeString;
};

#endif // AUDIO_H
