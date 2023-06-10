#ifndef COMPARATOR_H
#define COMPARATOR_H

#endif // COMPARATOR_H
#include "anime.h"
#include <iostream>

struct Comparator
{
    const QStringList parametrs;

    Comparator(const QStringList& parametrs) : parametrs(parametrs) {}


    bool operator()(const Anime* first, const Anime* second) const
    {
        for (const QString& par: parametrs)
        {

            if (par == "Name")
            {
                if (first->getName() < second->getName())
                    return true;
                else if (first->getName() > second->getName())
                    return false;
            }
            if (par == "Heighest Score")
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
        return true;
    }
};
