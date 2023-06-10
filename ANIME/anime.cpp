#include "anime.h"

Anime::Anime(const QString& name, const QString& score, const QString& episodes, const QString& ranked, const QString& popularity, const QString& members, const QString& favorites, const QString& watching, const QString& completed,
             const QString& on_hold, const QString& dropped,const QString& planToWatch, const QString& description, const QStringList& genres,
             const QString& type, const QString& aried, const QString& producers, const QString& licensors, const QString& studios, const QString& source, const QString& duration, const QString& rating)
{
    _name = name;
    _score = score;
    _episodes = episodes;
    _popularity = popularity;
    _members = members;
    _ranked = ranked;
    _favorites = favorites;
    _watching = watching;
    _completed = completed;
    _on_hold = on_hold;
    _dropped = dropped;
    _description = description;
    _planToWatch = planToWatch;
    _genres = genres;
    _type = type;
    _aried = aried;
    _producers = producers;
    _licensors = licensors;
    _studios = studios;
    _source = source;
    _duration = duration;
    _rating = rating;
}

Anime::Anime()
{

}

QString Anime::getName() const { return _name; }
QString Anime::getScore() const { return _score; }
QString Anime::getEpisodes() const { return _episodes; }
QString Anime::getRanked() const {return _ranked; }
QString Anime::getPopularity() const { return _popularity; }
QString Anime::getFavorites() const { return _favorites; }
QString Anime::getMembers() const {return _members; }
QString Anime::getWatching() const { return _watching; }
QString Anime::getCompleted() const { return _completed; }
QString Anime::getOn_hold() const { return _on_hold; }
QString Anime::getdropped() const { return _dropped; }
QString Anime::getPlanToWatch() const {return _planToWatch; }
QString Anime::getDescription() const { return _description; }
QStringList Anime::getGenres() const {return _genres; }
QString Anime::getType() const {return _type;}
QString Anime::getAried() const {return _aried;}
QString Anime::getProducers() const {return _producers;}
QString Anime::getLicensors() const {return _licensors;}
QString Anime::getStudios() const {return _studios;}
QString Anime::getSource() const {return _source;}
QString Anime::getDuration() const {return _duration;}
QString Anime::getRating() const {return _rating;}
QString Anime::getStringGenres() const
{
    QString res = "";
    for (const QString& genre: _genres)
        res += " " + genre;
    return res;
}
bool Anime::hasGenre(const QString& genre) const
{
    return (std::find(_genres.begin(), _genres.end(), genre) != _genres.end());
}

void Anime::setName(const QString& input) {_name = input;}
void Anime::setScore(const QString& input) {_score = input;}
void Anime::setEpisodes(const QString& input) {_episodes = input;}
void Anime::setRanked(const QString& input) {_ranked = input;}
void Anime::setPopularity(const QString& input) {_popularity = input;}
void Anime::setMembers(const QString& input) {_members = input;}
void Anime::setFavorites(const QString& input) {_favorites = input;}
void Anime::setWatching(const QString& input) {_watching = input;}
void Anime::setCompleted(const QString& input) {_completed = input;}
void Anime::setOn_hold(const QString& input) {_on_hold = input;}
void Anime::setPlanToWatch(const QString& input) {_planToWatch = input;}
void Anime::setDropped(const QString& input) {_dropped = input;}
void Anime::setDescription(const QString& input) {_description = input;}
void Anime::setParameters(const QString& input) {}
void Anime::setStringListGenres(const QStringList& input) {_genres = input;}
void Anime::setType(const QString& input) {_type = input;}
void Anime::setAried(const QString& input) {_aried = input;}
void Anime::setProducers(const QString& input) {_producers = input;}
void Anime::setLicensors(const QString& input) {_licensors = input;}
void Anime::setStudios(const QString& input) {_studios = input;}
void Anime::setSource(const QString& input) {_source = input;}
void Anime::setDuration(const QString& input) {_duration = input;}
void Anime::setRating(const QString& input) {_rating = input;}






