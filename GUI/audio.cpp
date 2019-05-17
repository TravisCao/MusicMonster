#include "audio.h"

#include <QAudioInput>
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

// open a new file
Audio::Audio(int sampleRate, int channelCount, QWidget *parent)
{
    timer = new QTimer(this);

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

}

// open an existed file
Audio::Audio(int sampleRate, int channelCount, QString fileName, QWidget * parent) {

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
    // if the music index is the current index
    // play or pause the music
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
    //        connect();
        }
    }

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
    player->setPosition(0);
    player->stop();
}

void Audio::volumeControl(int volume)
{
    player->setVolume(volume);
}

void Audio::positionUpdate(qint64 position, QSlider *slider, QLCDNumber * number)
{
    slider->setMaximum(static_cast<int>((player->duration() / 1000)));
    slider->setValue(static_cast<int>(position / 1000));
    int move = static_cast<int>(position * 1000);
    QTime timeMoved(0, (move / 60000) % 60, (move / 1000) % 60);
    timeString = timeMoved.toString("mm:ss");
    updateTimeNow(number, position);
}

void Audio::record()
{

}

bool Audio::isPlayListEmpty()
{
    return true;
}

void Audio::sliderChange(int position, QLCDNumber * number)
{
    player->setPosition(position * 1000);
    int move = position * 1000;
    QTime timeNow(0, (move / 60000) & 60, (move / 1000) % 60);
    updateTimeNow(number, position);
}

void Audio::updateTimeNow(QLCDNumber *number, qint64 position)
{
    int move = static_cast<int>(position * 1000);
    QTime display(0, (move / 60000) % 60, (move / 1000) % 60, position % 1000);
    timeString = display.toString("mm:ss:zzz");
    number->display(timeString);
}
