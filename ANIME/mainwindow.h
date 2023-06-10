#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tableview.h"
#include "anime.h"
#include "QListWidget"
#include "QListView"
#include "QStringListModel"
#include "QLineEdit"
#include "QComboBox"
#include <QPushButton>
#include "animemodel.h"
#include "customproxymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QList<Anime*> &listOfAnime, const QStringList& allGenres, QWidget *parent = nullptr);
    void addParametrs(const QString& para);
    ~MainWindow();

    void switchToSecondWindow(const QModelIndex &index);


public slots:
    void sortAnimeByName(int state);
    void sortAnimeByHighestScore(int state);
    void sortAnimeByLowestScore(int state);
    void sortAnimeByEpisodes(int state);
    void sortAnimeByRank(int state);
    void sortAnimeByPopularity(int state);
    void sortAnimeByMembers(int state);
    void sortAnimeByFavorites(int state);
    void sortAnimeByWatching(int state);
    void sortAnimeByCompleted(int state);
    void sortAnimeByOn_hold(int state);
    void sortAnimeByDropped(int state);
    void sortAnimeByPlanToWatch(int state);
    void chooseGenre(int state);
    void sortList();
    void handleSearchTextChanged(const QString& searchText);
    Anime* getSelectedAnime();
    void switchToAddWindow();
    void setNewAnime(Anime* anime);

signals:
    void openDetailedWindow();
    void openAddWindow();

public slots:
    void onLoginButtonClicked();
    void onPasswordVerified();
    void onLogoutButtonClicked();
    void onAboutButtonClicked();



private:
    Ui::MainWindow *ui;
    QPushButton *loginButton;
    QPushButton *addNewButton;
    AnimeModel *model;
    CustomProxyModel *proxyModel;

    QList<Anime*> listofAnime;
    QStringList _allGenres;
    QList<Anime*> sortedList;
    QListView *listView;
    QStringList _parametrs;
    bool _sortButtonWasPushedLast = false;
    QString _genre = "All Genres";
    Anime* _selectedAnime;
    QLineEdit *searchEdit = new QLineEdit(this);
    QComboBox* genreComboBox;
    bool _isAdmin = false;
    Anime* _newAnime = nullptr;

};
#endif // MAINWINDOW_H
