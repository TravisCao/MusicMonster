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

class Audio : public QWidget
{
    Q_OBJECT
public:
    Audio(int sampleRate, int channelCount,QWidget *parent = nullptr); // new audio file
    Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent = nullptr); // open an existed file
    void readAudioFile(QString fileName);
    int getSampleRate();
    int getChannelCount();
    qint64 getAudioDuration();
    void audioOnPlay(QString fileDir);
    void handleStateChanged(QAudio::State state);
    void getAudioDuration(qint64 &position);
    void audioOnStop();


private:
    QFile *destinationFile;
    QAudioFormat *format;
    QAudioInput *audioInput;
    QAudioOutput *audioOutput;
    QTimer *timer;
};

#endif // AUDIO_H
