#include "audio.h"

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QFile>
#include <QTimer>
#include <QAudio>
#include <QtDebug>
#include <QAudioDeviceInfo>


Audio::Audio(QWidget *parent) : QWidget(parent)
{
        destinationFile->setFileName("/tmp/test.raw");
        destinationFile->open( QIODevice::WriteOnly | QIODevice::Truncate );

        QAudioFormat format;
        // Set up the desired format, for example:
        format.setSampleRate(8000);
        format.setChannelCount(1);
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

void Audio::audioOnPlay()
{
    destinationFile->open(QIODevice::ReadOnly);

    // 设置播放音频格式;
    format->setSampleRate(48000);
    format->setChannelCount(1);
    format->setSampleSize(8);
    format->setCodec("audio/pcm");
    // wav文件即按照这个字节存储顺序保存数据;
    format->setByteOrder(QAudioFormat::LittleEndian);
    format->setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    //qDebug() << info.supportedCodecs();
    if (!info.isFormatSupported(*format))
    {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return;
    }

    audioOutput = new QAudioOutput(*format);
//    connect(audioOutput, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
    audioOutput->start();
    timer->start();
}

void Audio::handleStateChanged(QAudio::State state)
{
    switch (state) {
        case QAudio::IdleState:
            // Finished playing (no more data)
            qDebug() << "elapsedUSecs:" << audioOutput->elapsedUSecs();
//            qDebug() << "time : " << timer->;  // record time now
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
