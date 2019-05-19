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
#include <QAudioRecorder>

class Audio : public QWidget
{
    Q_OBJECT

public:

    Audio(QWidget *parent = nullptr);

    Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent = nullptr); // open an existed file

    int getSampleRate();

    int getChannelCount();

signals:

    void musicStart(bool flag);

    void musicPause(bool flag);

    void positionChange(int position);

    void update(int position);


public slots:

    void playAndPause(int index);

    void addToPlayList(QString fileName);

    QString getAudioDuration();

    void musicRecycle(bool flag);

    void musicSpeedUp();

    void musicRecoverSpeed();

    void musicSlowDown();

    void musicStop();

    void volumeControl(int volume);

    void record(bool flag);

    void stop_record();

    void sliderChange(int position);

    void updateTimeNow(qint64 position);

    void removeMusic(int index);

    void updateDisplay();

    void updateSender();

protected:

    friend class MainWindow;

    QAudioRecorder *recorder;

    QFile *destinationFile;

    QFile *record_output;

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
