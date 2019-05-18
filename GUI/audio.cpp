#include "audio.h"

#include <QAudioInput>
#include <QAudioEncoderSettings>
#include <QAudioRecorder>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QFile>
#include <QTimer>
#include <QAudio>
#include <QtDebug>
#include <QUrl>
#include <QFileInfo>
#include <QUrl>
#include <QAudioDeviceInfo>
#include <QMediaPlayer>
#include <QTime>
#include <QSlider>
#include <QLCDNumber>
#include <QDebug>

// open a new file
Audio::Audio(QWidget *parent): QWidget(parent)
{
    player = new QMediaPlayer(this);
    playList = new QMediaPlaylist;
    timer = new QTimer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &Audio::updateDisplay);
}

// open an existed file
Audio::Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent) : QWidget(parent)
{

    destinationFile->setFileName(fileName);
    destinationFile->open(QIODevice::ReadWrite);

    timer = new QTimer(this);

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

    player = new QMediaPlayer(this);
    playList->addMedia(QUrl::fromLocalFile(fileName));
    playList->setCurrentIndex(0);
    player->setPlaylist(playList);

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionUpdate(qint64)));

}

int Audio::getSampleRate()
{
    return format->sampleRate();
}

int Audio::getChannelCount()
{
    return format->channelCount();
}

void Audio::playAndPause(int index)
{
    qDebug() << "playReceived";
//     if the music index is the current index
//     play or pause the music
    qDebug() << "list empty?" << playList->isEmpty();
    qDebug() << "list currentIndex : " << playList->currentIndex();
//    player->play();
//    timer->start(1);
    if (index == playList->currentIndex()) {
        if (player->state() == QMediaPlayer::PlayingState) {
            player->pause();
            timer->stop();
        }
        else {
            player->play();
            timer->start(1);
        }
    }
    else {
        playList->setCurrentIndex(index);
        if (player->state() == QMediaPlayer::PlayingState) {
            player->pause();
            timer->stop();
        }
        else { // if the music is not playing now
            player->setPosition(0); // play the music from the beginning
            player->play();
            timer->start(1);
//            connect();
        }
    }

}

void Audio::addToPlayList(QString fileName)
{
    playList->addMedia(QUrl::fromLocalFile(fileName));
    playList->setCurrentIndex(0);
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    player->setPlaylist(playList);
    qDebug() << playList->isEmpty();
    qDebug() << playList->mediaCount();
}

QString Audio::getAudioDuration()
{
    int move = static_cast<int>(player->duration());
    QTime duration(0, (move / 60000) % 60, (move / 1000) % 60);
    timeString = duration.toString("mm:ss");
    return timeString;
}

void Audio::musicRecycle(bool flag)
{

    if (flag == 0) playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    if (flag == 1) playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

}

void Audio::musicSpeedUp()
{
    player->setPlaybackRate(1.2);
}

void Audio::musicRecoverSpeed()
{
   player->setPlaybackRate(1);
}

void Audio::musicSlowDown()
{
    player->setPlaybackRate(0.8);
}

void Audio::musicStop()
{
    qDebug() << "stop";
    player->setPosition(0);
    player->stop();
}

void Audio::volumeControl(int volume)
{
    player->setVolume(volume);
}


void Audio::record(bool flag)
{

    if (flag == true) {
        recorder = new QAudioRecorder;

        QAudioEncoderSettings audioSettings;
        audioSettings.setCodec("audio/amr");
        audioSettings.setQuality(QMultimedia::HighQuality);

        recorder->setEncodingSettings(audioSettings);

        recorder->setOutputLocation(QUrl::fromLocalFile("record.amr"));
        recorder->record();
        qDebug() << "recording begin";
    }
    else {
        recorder->stop();
        qDebug() << "recording end";
    }

}

void Audio::stop_record()
{
    recorder->stop();

    qDebug() << "stop recording";
}

void Audio::sliderChange(int position)
{
    player->setPosition(position * 1000);
    int move = position * 1000;
    QTime timeNow(0, (move / 60000) & 60, (move / 1000) % 60);

    emit positionChange(player->position());
}

void Audio::updateTimeNow(qint64 position)
{
    int move = static_cast<int>(position * 1000);
    QTime display(0, (move / 60000) % 60, (move / 1000) % 60, position % 1000);
    timeString = display.toString("mm:ss:zzz");
    //    number->display(timeString);
}

void Audio::removeMusic(int index)
{
    playList->removeMedia(index);
}

void Audio::updateDisplay()
{
    emit positionChange(player->position());
}
