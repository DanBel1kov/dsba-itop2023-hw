#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractItemModel>

class MainModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit MainModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QList<QStringList> _exData;
    QList<QStringList> _tableData;
    QStringList _headers;
    QStringList _tableHeaders = {"Name", "Sypnopsis"};

private:
};

#endif // EXAMPLEMODEL_H

