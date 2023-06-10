#ifndef ANIME_H
#define ANIME_H

#include <QString>
#include <QStringList>
#include <QObject>


class Anime: public QObject
{
    Q_OBJECT
public:

    Anime();

    Anime(const QString& name, const QString& score, const QString& episodes, const QString& ranked, const QString& popularity, const QString& members, const QString& favorites, const QString& watching, const QString& completed,
          const QString& on_hold, const QString& dropped, const QString& planToWatch, const QString& description, const QStringList& genres,
          const QString& type, const QString& aried, const QString& producers, const QString& licensors, const QString& studios, const QString& source, const QString& duration, const QString& rating);

    QString getName() const;
    QString getScore() const;
    QString getEpisodes() const;
    QString getRanked() const;
    QString getPopularity() const;
    QString getMembers() const;
    QString getFavorites() const;
    QString getWatching() const;
    QString getCompleted() const;
    QString getOn_hold() const;
    QString getPlanToWatch() const;
    QString getdropped() const;
    QString getDescription() const;
    QStringList getParametrs() const;
    QStringList getGenres() const;
    QString getStringGenres() const;
    QString getType() const;
    QString getAried() const;
    QString getProducers() const;
    QString getLicensors() const;
    QString getStudios() const;
    QString getSource() const;
    QString getDuration() const;
    QString getRating() const;


    void setName(const QString& input);
    void setScore(const QString& input);
    void setEpisodes(const QString& input);
    void setRanked(const QString& input);
    void setPopularity(const QString& input);
    void setMembers(const QString& input);
    void setFavorites(const QString& input);
    void setWatching(const QString& input);
    void setCompleted(const QString& input);
    void setOn_hold(const QString& input);
    void setPlanToWatch(const QString& input);
    void setDropped(const QString& input);
    void setDescription(const QString& input);
    void setParameters(const QString& input);
    void setStringListGenres(const QStringList& input);
    void setType(const QString& input);
    void setAried(const QString& input);
    void setProducers(const QString& input);
    void setLicensors(const QString& input);
    void setStudios(const QString& input);
    void setSource(const QString& input);
    void setDuration(const QString& input);
    void setRating(const QString& input);





    bool hasGenre(const QString& genre) const;



private:
    QString _name;
    QString _score;
    QString _episodes;
    QString _ranked;
    QString _popularity;
    QString _members;
    QString _favorites;
    QString _watching;
    QString _completed;
    QString _on_hold;
    QString _dropped;
    QString _description;
    QString _planToWatch;
    QStringList _genres;
    QString _type;
    QString _aried;
    QString _producers;
    QString _licensors;
    QString _studios;
    QString _source;
    QString _duration;
    QString _rating;

};

#endif // ANIME_H
