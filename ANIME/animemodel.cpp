#include "animemodel.h"
#include "anime.h"
#include <QAbstractListModel>

AnimeModel::AnimeModel(const QList<Anime*>& animeList, QObject* parent)
    : QAbstractListModel(parent), _animeList(animeList)
{

}

QModelIndex AnimeModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return createIndex(row, column);
}

int AnimeModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return _animeList.size();
}

QVariant AnimeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        if (index.row() >= 0 && index.row() < _animeList.size())
        {
            Anime* anime = _animeList.at(index.row());
            return anime->getName();
        }
    }

    return QVariant();
}

void AnimeModel::appendRow(Anime* anime)
{
    _animeList.append(anime);
}

Anime* AnimeModel::getAnime(const QModelIndex index)
{
    return _animeList.at(index.row());
}

AnimeModel::~AnimeModel()
{
    clearData();
}

void AnimeModel::clearData()
{
    for (Anime* anime: _animeList)
        delete(anime);
    _animeList.clear();
}
