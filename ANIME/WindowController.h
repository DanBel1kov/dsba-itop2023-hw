#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#endif // WINDOWCONTROLLER_H

#include "mainwindow.h"
#include "detailedwindow.h"
#include "QStackedWidget"
#include "addanimewindow.h"

class WindowController : public QObject
{
    Q_OBJECT

public:
    WindowController(QStackedWidget *stackedWidget, const QList<Anime*> &listOfAnime, const QStringList& allGenres, Anime* selectedAnime);

    MainWindow* getMainWindow(){return mainWindow;}
    DetailedWindow* getDetailedWindow(){return detailedWindow;}
    AddAnimeWindow* getaddAnimeWindow() {return addAnimeWindow;}


private slots:
    void switchToSecondWindow();

    void passToTheMainWindow(Anime* anime);
    void switchToMainWindow();

    void switchToAddWindow();

private:
    MainWindow *mainWindow;
    DetailedWindow *detailedWindow;
    AddAnimeWindow *addAnimeWindow;
    QStackedWidget *stackedWidget;
    Anime* _selectedAnime;

};

