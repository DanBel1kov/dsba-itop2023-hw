#ifndef CUSTOMPROXYMODEL_H
#define CUSTOMPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "anime.h"

class CustomProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT


public:
    explicit CustomProxyModel(QObject* parent = nullptr);
    void addParameter(const QString& par);
    void deleteParameter(const QString& par);
    QStringList getParameters() const;

    QString getGenre() const;
    void setGenre(const QString& genre);
    void setSearchWord(const QString& word);

signals:
    void addParameterSignal();

public slots:
    void setFilterChanges();

protected:
    bool lessThan(const QModelIndex& left, const QModelIndex& right) const override;
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

private:
    QStringList _parameters;
    QString _genre = "All Genres";
    QString _searchWord = "";
};


#endif // CUSTOMPROXYMODEL_H
