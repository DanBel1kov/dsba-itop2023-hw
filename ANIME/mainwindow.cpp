#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "tableview.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QListWidget"
#include "QCheckBox"
#include "QGridLayout"
#include "QPushButton"
#include "comparator.h"
#include <algorithm>
#include "QListView"
#include "QStringListModel"
#include "ReadOnlyDelegate.h"
#include "QComboBox"
#include <QLineEdit>
#include <QStandardItemModel>
#include "passwordinputwindow.h"
#include <QThread>
#include <QMessageBox>
#include <QAbstractListModel>
#include "animemodel.h"
#include <QSortFilterProxyModel>
#include "customproxymodel.h"
#include "aboutwindow.h"

bool startsWith(const Anime* anim, const QString& text)
{
    QString name = anim->getName();
    if (text.size() > name.size())
        return false;

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] != name[i])
            return false;
    }
    return true;

}

MainWindow::MainWindow(const QList<Anime*> &listofAnime, const QStringList& allGenres, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), listofAnime(listofAnime), _parametrs({}), _allGenres(allGenres)
{
    ui->setupUi(this);
    sortedList = listofAnime;

    QWidget *centralWidget = new QWidget(this);
    QGridLayout *mainLayout = new QGridLayout(centralWidget);
    listView = new QListView(centralWidget);
    //model = new QStringListModel(this);

    genreComboBox = new QComboBox(centralWidget);
    genreComboBox->setStyleSheet("QComboBox { combobox-popup: 0; } QAbstractItemView { max-height: 250px; }");

    for (const QString& genre: _allGenres)
        genreComboBox->addItem(genre);

    //genreComboBox->setFixedWidth(100);
    genreComboBox->setMaximumWidth(200);

    genreComboBox->setCurrentIndex(0);
    mainLayout->addWidget(genreComboBox, 1, 1);


    QPushButton *aboutButton = new QPushButton("About", this);
    aboutButton->setMaximumWidth(50);
    //QWidget *aboutPlace = new QWidget(this);
    //mainLayout->addWidget(goBackButton, 0, Qt::AlignTop | Qt::AlignRight);
    mainLayout->addWidget(aboutButton, 0, 1, Qt::AlignTop | Qt::AlignRight);
    connect(aboutButton, &QPushButton::clicked, this, &MainWindow::onAboutButtonClicked);



    QHBoxLayout *adminLayout = new QHBoxLayout(this);


    addNewButton = new QPushButton("Add New", this);
    addNewButton->setVisible(false);
    connect(addNewButton, &QPushButton::clicked, this, &MainWindow::switchToAddWindow);
    loginButton = new QPushButton("Log in", this);

    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);

    addNewButton->setMaximumWidth(100);
    loginButton->setMaximumWidth(100);
    adminLayout->addWidget(loginButton, 0, Qt::AlignTop | Qt::AlignLeading);
    adminLayout->addWidget(addNewButton, 1, Qt::AlignTop | Qt::AlignLeft);

    mainLayout->addLayout(adminLayout, 0, 0);



    mainLayout->addWidget(searchEdit, 1, 0);
    connect(searchEdit, &QLineEdit::textChanged, this, &MainWindow::handleSearchTextChanged);


//    QPushButton *goToSecondButton = new QPushButton("Go to Second Window", this);
//    //connect(goToSecondButton, &QPushButton::clicked, this, &MainWindow::switchToSecondWindow);
//    mainLayout->addWidget(goToSecondButton, 1,0);




    QStringList animeNames;
    for(const Anime* animeshechka : listofAnime)
    {
        animeNames << animeshechka->getName();
    }

    listView->setMinimumWidth(430);
    model = new AnimeModel(listofAnime, this);
    //listView->setModel(model);
    //model->setStringList(animeNames);
    listView->setModel(model);
    listView->setItemDelegate(new ReadOnlyDelegate(listView));

    proxyModel = new CustomProxyModel(this);
    proxyModel->setSourceModel(model);
    listView->setModel(proxyModel);

    //proxyModel->sort(0);


    connect(listView, &QListView::clicked, this, &MainWindow::switchToSecondWindow);
    mainLayout->addWidget(listView, 2, 0);

    //QWidget *checkBoxBidget = new QWidget(this);
    QVBoxLayout *checkBoxLayout = new QVBoxLayout(centralWidget);
    mainLayout->addLayout(checkBoxLayout, 2 ,1);

    QCheckBox *nameCheckBox = new QCheckBox("Sort by Name");
    QCheckBox *highestScoreCheckBox = new QCheckBox("Sort by Highest Score");
    QCheckBox *lowestScoreCheckBox = new QCheckBox("Sort by Lowest Score");
    QCheckBox *episodesCheckBox = new QCheckBox("Sort by Episodes");
    QCheckBox *rankedCheckBox = new QCheckBox("Sort by Rank");
    QCheckBox *popularityCheckBox = new QCheckBox("Sort by Popularity");
    QCheckBox *membersCheckBox = new QCheckBox("Sort by Members");
    QCheckBox *favoritesCheckBox = new QCheckBox("Sort by Favorites");
    QCheckBox *watchingCheckBox = new QCheckBox("Sort by Watching");
    QCheckBox *completedCheckBox = new QCheckBox("Sort by Completed");
    QCheckBox *on_holdCheckBox = new QCheckBox("Sort by On-Hold");
    QCheckBox *droppedCheckBox = new QCheckBox("Sort by Dropped");
    QCheckBox *planToWatchCheckBox = new QCheckBox("Sort by Plan to Watch");
    QPushButton *sortButton = new QPushButton("Sort");



    // Connect checkbox signals to sorting slots
    connect(nameCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByName);
    connect(highestScoreCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByHighestScore);
    connect(lowestScoreCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByLowestScore);
    connect(episodesCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByEpisodes);
    connect(rankedCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByRank);
    connect(popularityCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByPopularity);
    connect(membersCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByMembers);
    connect(favoritesCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByFavorites);
    connect(watchingCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByWatching);
    connect(completedCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByCompleted);
    connect(on_holdCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByOn_hold);
    connect(droppedCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByDropped);
    connect(planToWatchCheckBox, &QCheckBox::stateChanged, this, &MainWindow::sortAnimeByPlanToWatch);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::sortList);
    connect(genreComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::chooseGenre);
    connect(sortButton, &QPushButton::clicked, proxyModel, &CustomProxyModel::setFilterChanges);


    // Add checkboxes to layout or widget
    //QVBoxLayout *layout = new QVBoxLayout;
    checkBoxLayout->addWidget(nameCheckBox);
    checkBoxLayout->addWidget(highestScoreCheckBox);
    checkBoxLayout->addWidget(lowestScoreCheckBox);
    checkBoxLayout->addWidget(episodesCheckBox);
    checkBoxLayout->addWidget(rankedCheckBox);
    checkBoxLayout->addWidget(popularityCheckBox);
    checkBoxLayout->addWidget(membersCheckBox);
    checkBoxLayout->addWidget(favoritesCheckBox);
    checkBoxLayout->addWidget(watchingCheckBox);
    checkBoxLayout->addWidget(completedCheckBox);
    checkBoxLayout->addWidget(on_holdCheckBox);
    checkBoxLayout->addWidget(droppedCheckBox);
    checkBoxLayout->addWidget(planToWatchCheckBox);
    checkBoxLayout->addWidget(sortButton);

     setCentralWidget(centralWidget);
}

void MainWindow::switchToSecondWindow(const QModelIndex &index)
{
     //int ind = (index.row());
     //_selectedAnime = sortedList.at(ind);
     //QVariant data = model->getAnime(index);
     QModelIndex ind = proxyModel->mapToSource(index);
     _selectedAnime = model->getAnime(ind);
     emit openDetailedWindow();
}

void MainWindow::switchToAddWindow()
{
     emit openAddWindow();

}


void MainWindow::setNewAnime(Anime* anime)
{
     model->appendRow(anime);
     listView->update();
     listofAnime.append(anime);
     proxyModel->invalidate();
}

void MainWindow::onLoginButtonClicked()
{
     PasswordInputWindow* passwordWindow = new PasswordInputWindow(this);
     connect(passwordWindow, &PasswordInputWindow::passwordVerified, this, &MainWindow::onPasswordVerified);
     passwordWindow->show();
}

void MainWindow::onAboutButtonClicked()
{
     AboutWindow* aboutWindow = new AboutWindow(this);
     aboutWindow->show();
}

void MainWindow::onPasswordVerified()
{
     addNewButton->setVisible(true);
     _isAdmin = true;
     loginButton->setText("Log out");
     disconnect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
     connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLogoutButtonClicked);
}

void MainWindow::onLogoutButtonClicked()
{
     addNewButton->setVisible(false);
     _isAdmin = false;
     loginButton->setText("Log in");
     disconnect(loginButton, &QPushButton::clicked, this, &MainWindow::onLogoutButtonClicked);
     connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
}

void MainWindow::handleSearchTextChanged(const QString& searchText)
{
    proxyModel->setSearchWord(searchText);
    proxyModel->invalidate();

}




//void MainWindow::setParametrs                  //TODO seems like it is easier to redo all sorting process
                                                 //all change in one function, but small fucntions change only the state of button (changed or not)



Anime* MainWindow::getSelectedAnime(){return _selectedAnime;}

void MainWindow::chooseGenre(int index)    // does not work if the button waas pushed last
{
     //QModelIndex ind = proxyModel->mapToSource(index);
     proxyModel->setGenre(genreComboBox->currentText());


//     _sortButtonWasPushedLast = false;    // something to do with it
//     _genre = _allGenres.at(index);
//     if (_genre == "All Genres")
//     {
//        sortedList = listofAnime;
//        return;
//     }
//     if (_parametrs.isEmpty())
//        sortedList = listofAnime;

//     for (Anime* curAnime: listofAnime) // sortedlist????
//     {
//        if (!curAnime->hasGenre(_genre))
//            sortedList.removeOne(curAnime);


//     }
}

void MainWindow::sortAnimeByName(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Name");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Name");
     }
}

void MainWindow::sortList()
{
     proxyModel->sort(-1);
     if (!proxyModel->getParameters().isEmpty())
        proxyModel->sort(0);
     proxyModel->invalidate();

//     if (_sortButtonWasPushedLast)
//        return;

//     _sortButtonWasPushedLast = true;
//     if (_parametrs.isEmpty() && _genre == "All Genres" && searchEdit->text().isEmpty())
//     {
//        QStringList animeNames;
//        sortedList = listofAnime;
//        for (const Anime* animeshechka : listofAnime) {
//            animeNames << animeshechka->getName();
//        }
//        //model->setStringList(animeNames);                    //ТУУУУУУТ
//        listView->update();
//     }


//     else
//     {
//        if (!_parametrs.isEmpty())
//        {
//            Comparator comparator(_parametrs);
//            std::sort(sortedList.begin(), sortedList.end(), comparator);

//        }
//        else if (_parametrs.isEmpty())
//        {
//            chooseGenre(genreComboBox->currentIndex());

//        }


//        //chooseGenre(genreComboBox->currentIndex());
//        QStringList animeNames;
//        for (const Anime* animeshechka : sortedList) {
//            animeNames << animeshechka->getName();
//        }
//        //model->setStringList(animeNames);                                 //ТУУУУУУУУТ
//        listView->update();

//        handleSearchTextChanged(searchEdit->text());
//     }
//     std::cout << "the list was sorted" << '\n';
//     //handleSearchTextChanged(searchEdit->text());
//     _sortButtonWasPushedLast = true;

//    //std::sort(listofAnime.begin(), listofAnime.end(), [const anime& first, const anime& second](){});
}

void MainWindow::sortAnimeByHighestScore(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Highest Score");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Highest Score");
     }
}

//     _sortButtonWasPushedLast = false;

//     if (state == Qt::Checked)
//     {
//        _parametrs.append("Heighest Score");
//        return;
//     }

//     else if (state == Qt::Unchecked)
//     {
//        for (size_t i = 0; i < _parametrs.size(); ++i)
//        {
//            if (_parametrs.at(i) == "Heighest Score")
//            {
//                _parametrs.removeAt(i);
//                return;
//            }
//        }
//     }
//}

void MainWindow::sortAnimeByLowestScore(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Lowest Score");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Lowest Score");
     }

}
void MainWindow::sortAnimeByEpisodes(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Episodes");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Episodes");
     }
}

void MainWindow::sortAnimeByRank(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Rank");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Rank");
     }
}

void MainWindow::sortAnimeByPopularity(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Popularity");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Popularity");
     }
}
void MainWindow::sortAnimeByMembers(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Members");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Members");
     }
}

void MainWindow::sortAnimeByFavorites(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Favorites");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Favorites");
     }
}

void MainWindow::sortAnimeByWatching(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Watching");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Watching");
     }
}
void MainWindow::sortAnimeByCompleted(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Completed");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Completed");
     }
}

void MainWindow::sortAnimeByOn_hold(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("On-hold");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("On-hold");
     }
}

void MainWindow::sortAnimeByDropped(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Dropped");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Dropped");
     }
}
void MainWindow::sortAnimeByPlanToWatch(int state)
{
     _sortButtonWasPushedLast = false;

     if (state == Qt::Checked)
     {
        proxyModel->addParameter("Plan to watch");
        return;
     }

     else if (state == Qt::Unchecked)
     {
        proxyModel->deleteParameter("Plan to watch");
     }
}

void MainWindow::addParametrs(const QString& para)
{
     _parametrs.append(para);
}



MainWindow::~MainWindow()
{
    delete ui;
}

