#include "filewidget.h"
#include "readwav.h"
#include "audio.h"

#include <string>
#include <QWidget>
#include <QTableView>
#include <QTime>
#include <QStandardItemModel>
#include <QList>
#include <QFileInfo>
#include <QDebug>
#include <QItemSelectionModel>
#include <QMediaPlayer>
#include <QUrl>
#include <QCoreApplication>
#include <QEventLoop>


FileWidget::FileWidget(QWidget *parent) : QWidget(parent)
{
    fileModel = new QStandardItemModel(0, 5);
    fileModel->setHorizontalHeaderLabels(QStringList() << "Name:" << "Duration" << "Sample Rates" << "Channels" << "Bit Depth");

}


void FileWidget::modelInit(QTableView *table)
{

   table->setModel(fileModel);
   selectionModel = table->selectionModel();

    for (int i = 0; i < 10; ++i) {
        table->setRowHeight(i,10);
    }

    table->setShowGrid(false);

    connectionInit();

}

void FileWidget::addItem(QString fileName)
{
    std::string filenameString = fileName.toStdString();
    WavInFile *wavfile = new WavInFile(filenameString.data());

    MMbuffer<float> *buffer = &(wavfile->buffer);

    QFileInfo info = QFileInfo(fileName);
    QString name = info.fileName();
    QString sampleRate = uintToQString(wavfile->getSampleRate());
    QString channel = uintToQString(wavfile->getChannels());
    QString bitBepth = uintToQString(wavfile->getBitsPerSample());

    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(fileName));

    // waiting for 200ms for loading duration of the file
    // while continuing processing other events
    QTime _Timer = QTime::currentTime().addMSecs(300);
       while( QTime::currentTime() < _Timer )
           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    int durationInt = static_cast<int>(player->duration());
    QTime time(0, (durationInt / 60000) % 60, (durationInt / 1000) % 60);
    QString duration = time.toString("hh:mm:ss");

    int fontSize = fontMetrics().width(name);

    if (fontSize >= 150) {
        name = fontMetrics().elidedText(name, Qt::ElideMiddle, 150);
    }
    qDebug() << name;

    struct fileItem item;

    item.fileName = new QStandardItem(name);
    item.bitDepth = new QStandardItem(bitBepth);
    item.channels = new QStandardItem(channel);
    item.duration = new QStandardItem(duration);
    item.sampleRate = new QStandardItem(sampleRate);
    item.bufferList.append(buffer);
    item.bufferIndex = 0;

    fileList.append(item);

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

void FileWidget::connectionInit()
{
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &FileWidget::debug);
}

QString FileWidget::uintToQString(uint number)
{

   std::string string = to_string(number);
   QString qString = QString(QString::fromLocal8Bit(string.c_str()));

   return qString;
}

QList<int> FileWidget::getSelectedRows()
{
    QList<int> rows;
    qDebug() << selectionModel->currentIndex();
    qDebug() << selectionModel->selectedIndexes().size() / 5;
    for (int i = 0; i < selectionModel->selectedIndexes().size() / 5 ; ++i) {
        rows.append(selectionModel->selectedIndexes().at(i).row());
    }
    qDebug() << "Select rows: " << rows;
    return rows;
}

void FileWidget::debug(const QItemSelection &selected)
{
    qDebug() << selected.indexes().first().row();
}

