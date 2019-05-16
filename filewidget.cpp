#include "filewidget.h"


#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QList>

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

void FileWidget::addItem(struct fileItem item)
{

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
