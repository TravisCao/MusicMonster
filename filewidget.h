#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>

class FileWidget : public QWidget
{
    Q_OBJECT
public:

    explicit FileWidget(QWidget *parent = nullptr);
    void modelInit(QTableView *table);



signals:

public slots:

protected:
    QStandardItemModel *fileModel;

    struct fileItem
    {
        QStandardItem *fileName;
        QStandardItem *duration;
        QStandardItem *sampleRate;
        QStandardItem *channels;
        QStandardItem *bitDepth;
    };

public:
    friend class MainWindow;
    void addItem(struct fileItem item);
    void removeItem(int row);
    void searchItem();

};

#endif // FILEWIDGET_H
