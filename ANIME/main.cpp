#include "mainwindow.h"
#include "anime.h"
#include "addanimewindow.h"

#include <QApplication>
#include <QString>
#include <QFile>
#include <sstream>
#include <QStringList>
#include <QSet>
#include <QStackedWidget>
#include "WindowController.h"




QList<Anime*> readData(QStringList& allGenres)
{
    //QFile inputFile("/Users/danielbelikov/Desktop/ANIME/anime.csv");
    QFile inputFile("/Users/danielbelikov/Desktop/ANIME/anime2.csv");

    QFile synopsisFile("/Users/danielbelikov/Desktop/ANIME/anime_with_synopsis.csv");
    QList<Anime*> alist;
    inputFile.open(QFile::ReadOnly | QFile::Text);
    synopsisFile.open(QFile::ReadOnly | QFile::Text);

    QTextStream inputStream(&inputFile);
    QTextStream synopsisStream(&synopsisFile);

    QString firstline = inputStream.readLine();
    QString first2line = synopsisStream.readLine();



    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QString> tableLine;
        QList<QString> dataRow;
        bool second = true;
        size_t lineNumber = 0;
        for (QString& item : line.split("\t")) {
            if (lineNumber == 1)
            {
                tableLine.append(item);
            }
            ++lineNumber;
            dataRow.append(item);
        }


        QString line2 = synopsisStream.readLine();
        std::string linestd = line2.toStdString();
        std::stringstream ss(linestd);


        for (size_t i = 0; i < 4; ++i)
        {
            if (i == 3)
            {
                std::string buf;
                getline(ss,buf,'"');
                getline(ss,buf,'"');
                getline(ss,buf,',');
                getline(ss,buf,'"');
            }
            else
            {
                std::string buf;
                getline(ss,buf,',');
            }

        }
        std::string syn;
        getline(ss, syn);


        dataRow.append(QString::fromStdString(syn));

        QStringList genres;


        for (const QString& genre: dataRow.at(3).split(", "))
        {
            if (std::find(allGenres.begin(), allGenres.end(), genre) == allGenres.end())
                allGenres.append(genre);
            genres.append(genre);

        }


        Anime *anim = new Anime(dataRow.at(1), dataRow.at(2), dataRow.at(7), dataRow.at(16), dataRow.at(17), dataRow.at(18),
                                dataRow.at(19), dataRow.at(20), dataRow.at(21), dataRow.at(22), dataRow.at(23), dataRow.at(24), dataRow.at(35), genres,
                                dataRow.at(6), dataRow.at(8), dataRow.at(10), dataRow.at(11), dataRow.at(12), dataRow.at(13), dataRow.at(14), dataRow.at(15));

        alist.append(anim);



        tableLine.append(QString::fromStdString(syn));

    }


    inputFile.close();
    synopsisFile.close();

    return alist;



}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList allGenres = {"All Genres"};
    QList<Anime*> listOfAnime = readData(allGenres);
    MainWindow w(listOfAnime, allGenres);
    Anime* selectedAnime = listOfAnime.at(0);

    QStackedWidget stackedWidget;
    WindowController windowController(&stackedWidget, listOfAnime, allGenres,selectedAnime);

    stackedWidget.addWidget(windowController.getMainWindow());
    stackedWidget.addWidget(windowController.getDetailedWindow());
    stackedWidget.addWidget(windowController.getaddAnimeWindow());
    stackedWidget.setCurrentWidget(windowController.getMainWindow());
    stackedWidget.setFixedSize(700, 500);
    stackedWidget.show();
    //w.show();
    return a.exec();
}
