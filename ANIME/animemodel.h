#ifndef ANIMEMODEL_H
#define ANIMEMODEL_H

#include <QAbstractListModel>
#include "anime.h"
#include <QVariant>

class AnimeModel: public QAbstractListModel
{
    Q_OBJECT
public:

    void clearData();
    explicit AnimeModel(const QList<Anime*>& animeList, QObject* parent = nullptr);

    QModelIndex index(int row, int column = 0, const QModelIndex& parent = QModelIndex()) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    Anime* getAnime(const QModelIndex index);
    void appendRow(Anime* anime);

private:

    ~AnimeModel();

private:
    QList<Anime*> _animeList;

};

#endif // ANIMEMODEL_H
