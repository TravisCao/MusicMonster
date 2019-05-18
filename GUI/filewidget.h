#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include "readwav.h"

#include <QWidget>
#include <QTableView>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QItemSelectionModel>
#include <QModelIndexList>

class FileWidget : public QWidget
{
    Q_OBJECT

public:

    explicit FileWidget(QWidget *parent = nullptr);

    void modelInit(QTableView *table);

    QString uintToQString(uint number);

    QList<int> getSelectedRows();

public slots:

    void debug(const QItemSelection &selected);


protected:
    struct fileItem
    {
        QStandardItem *fileName;
        QStandardItem *duration;
        QStandardItem *sampleRate;
        QStandardItem *channels;
        QStandardItem *bitDepth;
        QList<MMbuffer<float>*> bufferList;
        int bufferIndex;
    };

    QStandardItemModel *fileModel;

    QList<QString> openedFileNames;

    QItemSelectionModel *selectionModel;

    QList<fileItem> fileList;

private:

    friend class MainWindow;

    void addItem(QString fileName);

    void removeItem(int row);

    void searchItem();

    void connectionInit();

};

#endif // FILEWIDGET_H
