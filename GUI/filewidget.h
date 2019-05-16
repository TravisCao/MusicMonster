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
    QString uintToQString(uint number);


signals:

private slots:

//    void infoUpdate();


protected:
    struct fileItem
    {
        QStandardItem *fileName;
        QStandardItem *duration;
        QStandardItem *sampleRate;
        QStandardItem *channels;
        QStandardItem *bitDepth;
    };

    QStandardItemModel *fileModel;

    QList<QString> openedFileNames;

private:
    friend class MainWindow;
    void addItem(QString fileName);
    void removeItem(int row);
    void searchItem();

};

#endif // FILEWIDGET_H
