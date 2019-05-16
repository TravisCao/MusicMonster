#include "audio.h"

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QFile>
#include <QTimer>
#include <QAudio>
#include <QtDebug>
#include <QAudioDeviceInfo>
#include <QMediaPlayer>
#include <QTime>

// open a new file
Audio::Audio(int sampleRate, int channelCount, QWidget *parent)
{
        QAudioFormat format;
        // Set up the desired format, for example:
        format.setSampleRate(sampleRate);
        format.setChannelCount(channelCount);
        format.setSampleSize(8);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        if (!info.isFormatSupported(format)) {
            qWarning() << "Default format not supported, trying to use the nearest.";
            format = info.nearestFormat(format);
        }

        audioInput = new QAudioInput(format, this);
        connect(audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
}

// open an existed file
Audio::Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent) {

    destinationFile->setFileName(fileName);
    destinationFile->open(QIODevice::ReadWrite);

    QAudioFormat format;
    format.setSampleRate(sampleRate);
    format.setChannelCount(channelCount);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }

    audioInput = new QAudioInput(format, this);
    connect(audioInput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));

}

int Audio::getSampleRate()
{
    return format->sampleRate();
}

int Audio::getChannelCount()
{
    return format->channelCount();
}

qint64 Audio::getAudioDuration()
{
       if (destinationFile->open(QIODevice::ReadOnly)) {
           qint64 fileSize = destinationFile->size();
           qint64 time = qint64(fileSize / (16000.0 * 2.0));
           destinationFile->close();
           return time;
       }
       return -1;
}

void Audio::audioOnPlay(QString fileDir)
{
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(fileDir));
    player->setVolume(50);
    player->play();
    timer->start();

    audioOutput = new QAudioOutput(*format);
    connect(audioOutput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
}

void Audio::handleStateChanged(QAudio::State state)
{
    switch (state) {
        case QAudio::IdleState:
            // Finished playing (no more data)
            qDebug() << "elapsedUSecs:" << audioOutput->elapsedUSecs();
            audioOnStop();
            break;

        case QAudio::StoppedState:
            // Stopped for other reasons
            if (audioOutput->error() != QAudio::NoError) {
                // Error handling
            }
            break;

        default:
            break;
        }
}

void Audio::audioOnStop()
{
    if (audioOutput != nullptr)
        {
            audioOutput->stop();
            destinationFile->close();
            delete audioOutput;
            audioOutput = nullptr;
        }
}

void Audio::readAudioFile(QString fileName)
{
    QFile *file = new QFile(fileName);
    destinationFile = file;
}

//void Audio::getAudioDuration(const qint64 &Position)
//{
//}
