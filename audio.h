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
    Audio(QWidget *parent = nullptr); // new audio file
    void readAudioFile(QString fileName);
    int getSampleRate();
    int getChannelCount();
    qint64 getAudioDuration();
    void audioOnPlay();
    void handleStateChanged(QAudio::State state);
    void audioOnStop();


private:
    QFile *destinationFile;
    QAudioFormat *format;
    QAudioInput *audioInput;
    QAudioOutput *audioOutput;
    QTimer *timer;
};

#endif // AUDIO_H
