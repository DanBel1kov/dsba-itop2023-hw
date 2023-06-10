#include "customproxymodel.h"
#include "anime.h" // Include your Anime class header
#include "mainwindow.h"

CustomProxyModel::CustomProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent)
{

}

void CustomProxyModel::addParameter(const QString& par)
{
    _parameters.append(par);
}

QStringList CustomProxyModel::getParameters() const
{
    return _parameters;
}



void CustomProxyModel::deleteParameter(const QString& par)
{
    for (size_t i = 0; i < _parameters.size(); ++i)
    {
        if (_parameters.at(i) == par)
        {

            _parameters.removeAt(i);
            return;
        }
    }
}

void CustomProxyModel::setGenre(const QString& genre)
{
    _genre = genre;
}

QString CustomProxyModel::getGenre() const
{
    return _genre;
}

void CustomProxyModel::setFilterChanges()
{
    emit layoutChanged();
}
bool CustomProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const {


    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    AnimeModel* model = qobject_cast<AnimeModel*>(sourceModel());

    Anime* anime = model->getAnime(index);

    if (!_searchWord.isEmpty() && !anime->getName().startsWith(_searchWord, Qt::CaseInsensitive)) {
        return false;
    }

    if (_genre == "All Genres")
        return true;


    if (anime && !anime->hasGenre(_genre)) {
        return false;
    }

    return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
}

void CustomProxyModel::setSearchWord(const QString& word)
{
    _searchWord = word;
}

bool CustomProxyModel::lessThan(const QModelIndex& left, const QModelIndex& right) const
{
    AnimeModel* model = qobject_cast<AnimeModel*>(sourceModel());

    Anime* first = model->getAnime(left);
    Anime* second = model->getAnime(right);

    for (const QString& par: _parameters)
    {

        if (par == "Name")
        {
            if (first->getName() < second->getName())
                return true;
            else if (first->getName() > second->getName())
                return false;
        }
        if (par == "Highest Score")
        {
            if (first->getScore() > second->getScore())
                return true;
            else if (first->getScore() < second->getScore())
                return false;
        }
        if (par == "Lowest Score")
        {
            if (first->getScore() < second->getScore())
                return true;
            else if (first->getScore() > second->getScore())
                return false;
        }
        if (par == "Episodes")
        {

            if (first->getEpisodes().isEmpty() || second->getEpisodes().isEmpty())
                return true;
            if (first->getEpisodes() > second->getEpisodes())
                return true;
            else if (first->getEpisodes() < second->getEpisodes())
                return false;
        }
        if (par == "Rank")
        {
            if (first->getRanked() > second->getRanked())
                return true;
            else if (first->getRanked() < second->getRanked())
                return false;
        }
        if (par == "Popularity")
        {
            if (first->getPopularity() > second->getPopularity())
                return true;
            else if (first->getPopularity() < second->getPopularity())
                return false;
        }
        if (par == "Members")
        {

            if (first->getMembers() > second->getMembers())
                return true;
            else if (first->getMembers() < second->getMembers())
                return false;
        }
        if (par == "Favorites")
        {
            if (first->getFavorites() > second->getFavorites())
                return true;
            else if (first->getFavorites() < second->getFavorites())
                return false;
        }
        if (par == "Watching")
        {
            if (first->getWatching() > second->getWatching())
                return true;
            else if (first->getWatching() < second->getWatching())
                return false;
        }
        if (par == "Completed")
        {
            if (first->getCompleted() > second->getCompleted())
                return true;
            else if (first->getCompleted() < second->getCompleted())
                return false;
        }
        if (par == "On-hold")
        {
            if (first->getOn_hold() > second->getOn_hold())
                return true;
            else if (first->getOn_hold() < second->getOn_hold())
                return false;
        }
        if (par == "Dropped")
        {

            if (first->getdropped() > second->getdropped())
                return true;
            else if (first->getdropped() < second->getdropped())
                return false;
        }
        if (par == "Plan to watch")
        {
            if (first->getPlanToWatch() > second->getPlanToWatch())
                return true;
            else if (first->getPlanToWatch() < second->getPlanToWatch())
                return false;
        }


    }

    return QSortFilterProxyModel::lessThan(left, right);
}
