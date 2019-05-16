#include "filewidget.h"
#include "readwav.h"

#include <string>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QList>
#include <QFileInfo>

FileWidget::FileWidget(QWidget *parent) : QWidget(parent)
{

}


void FileWidget::modelInit(QTableView *table)
{
    fileModel = new QStandardItemModel(0, 5);
    fileModel->setHorizontalHeaderLabels(QStringList() << "Name:" << "Duration" << "Sample Rates" << "Channels" << "Bit Depth");

    table->setModel(fileModel);

    for (int i = 0; i < 10; ++i) {
        table->setRowHeight(i,10);
    }

    table->setShowGrid(false);

}

void FileWidget::addItem(QString fileName)
{
    std::string filenameString = fileName.toStdString();
    WavInFile *wavfile = new WavInFile(filenameString.data());

//      QMediaPlayer *player = new QMediaPlayer();
//      player->setMedia(QUrl::fromLocalFile(fileName));
//      player->setVolume(50);
//      player->play();

    QFileInfo info = QFileInfo(fileName);
    QString name = info.fileName();
    QString sampleRate = uintToQString(wavfile->getSampleRate());
    QString channel = uintToQString(wavfile->getChannels());
    QString bitBepth = uintToQString(wavfile->getBitsPerSample());
    QString duration = QString::fromStdString(wavfile->getLengthInMS());

    struct fileItem item;

    item.fileName = new QStandardItem(name);
    item.bitDepth = new QStandardItem(bitBepth);
    item.channels = new QStandardItem(channel);
    item.duration = new QStandardItem(duration);
    item.sampleRate = new QStandardItem(sampleRate);

    item.fileName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item.bitDepth->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item.channels->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item.duration->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item.sampleRate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QList<QStandardItem *> itemList;
    itemList.append(item.fileName);
    itemList.append(item.duration);
    itemList.append(item.sampleRate);
    itemList.append(item.channels);
    itemList.append(item.bitDepth);
    fileModel->appendRow(itemList);

}

void FileWidget::removeItem(int row)
{
    fileModel->removeRow(row);
}

void FileWidget::searchItem()
{

}

QString FileWidget::uintToQString(uint number)
{

   std::string string = to_string(number);
   QString qString = QString(QString::fromLocal8Bit(string.c_str()));

   return qString;
}

