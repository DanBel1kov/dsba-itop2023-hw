#include "addanimewindow.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QFont>
#include <QPushButton>
#include <QRandomGenerator>
#include <QString>
#include <QMessageBox>

AddAnimeWindow::AddAnimeWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QFont font;
    font.setBold(true);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    centralWidget->setLayout(mainLayout); // Set the layout on the central widget
    setCentralWidget(centralWidget);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    mainLayout->addLayout(leftLayout);

    QTextEdit *nameBlock = new QTextEdit("Input name and description of new anime");
    nameBlock->setFont(font);
    nameBlock->setReadOnly(true);
    nameBlock->setAlignment(Qt::AlignCenter);
    nameBlock->setStyleSheet("border: 0; background-color: transparent;");
    leftLayout->addWidget(nameBlock);
    nameBlock->setMaximumHeight(30);


    _nameEdit->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(_nameEdit);


    _desriptionEdit->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(_desriptionEdit);

    QLabel *genresLabel = new QLabel("Genres:");
    genresLabel->setFont(font);
    QHBoxLayout *genresLayout = new QHBoxLayout;
    genresLayout->addWidget(genresLabel);
    genresLayout->addWidget(_genresEdit);
    leftLayout->addLayout(genresLayout);



    QVBoxLayout *rightLayout = new QVBoxLayout;
    mainLayout->addLayout(rightLayout);

    QLabel *scoreLabel = new QLabel("Score:");
    scoreLabel->setFont(font);
    QHBoxLayout *scoreLayout = new QHBoxLayout;
    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(_scoreEdit);
    rightLayout->addLayout(scoreLayout);

    QLabel *typesLabel = new QLabel("Types:");
    typesLabel->setFont(font);
    QHBoxLayout *typesLayout = new QHBoxLayout;
    typesLayout->addWidget(typesLabel);
    typesLayout->addWidget(_typesEdit);
    rightLayout->addLayout(typesLayout);

    QLabel *episodesLabel = new QLabel("Episodes:");
    episodesLabel->setFont(font);
    QHBoxLayout *episodeLayout = new QHBoxLayout;
    episodeLayout->addWidget(episodesLabel);
    episodeLayout->addWidget(_episodesEdit);
    rightLayout->addLayout(episodeLayout);

    QLabel *ariedLabel = new QLabel("Aried:");
    ariedLabel->setFont(font);
    QHBoxLayout *ariedLayout = new QHBoxLayout;
    ariedLayout->addWidget(ariedLabel);
    ariedLayout->addWidget(_ariedEdit);
    rightLayout->addLayout(ariedLayout);

    QLabel *studiosLabel = new QLabel("Studios:");
    studiosLabel->setFont(font);
    QHBoxLayout *studiosLayout = new QHBoxLayout;
    studiosLayout->addWidget(studiosLabel);
    studiosLayout->addWidget(_studiosEdit);
    rightLayout->addLayout(studiosLayout);

    QLabel *licensorsLabel = new QLabel("Licensors:");
    licensorsLabel->setFont(font);
    QHBoxLayout *licensorsLayout = new QHBoxLayout;
    licensorsLayout->addWidget(licensorsLabel);
    licensorsLayout->addWidget(_licensorsEdit);
    rightLayout->addLayout(licensorsLayout);

    QLabel *sourceLabel = new QLabel("Source:");
    sourceLabel->setFont(font);
    QHBoxLayout *sourceLayout = new QHBoxLayout;
    sourceLayout->addWidget(sourceLabel);
    sourceLayout->addWidget(_sourceEdit);
    rightLayout->addLayout(sourceLayout);

    QLabel *durationLabel = new QLabel("Duration:");
    durationLabel->setFont(font);
    QHBoxLayout *durationLayout = new QHBoxLayout;
    durationLayout->addWidget(durationLabel);
    durationLayout->addWidget(_durationEdit);
    rightLayout->addLayout(durationLayout);

    QLabel *ratingLabel = new QLabel("Rating:");
    ratingLabel->setFont(font);
    QHBoxLayout *ratingLayout = new QHBoxLayout;
    ratingLayout->addWidget(ratingLabel);
    ratingLayout->addWidget(_ratingEdit);
    rightLayout->addLayout(ratingLayout);

    QLabel *producersLabel = new QLabel("Producers:");
    producersLabel->setFont(font);
    QHBoxLayout *producersLayout = new QHBoxLayout;
    producersLayout->addWidget(producersLabel);
    producersLayout->addWidget(_producersEdit);
    rightLayout->addLayout(producersLayout);

    QPushButton *cancelButton = new QPushButton("Cancel");
    rightLayout->addWidget(cancelButton);
    connect(cancelButton, &QPushButton::clicked, this, &AddAnimeWindow::goBack);
    QPushButton *addButton = new QPushButton("Add");
    rightLayout->addWidget(addButton);
    connect(addButton, &QPushButton::clicked, this, &AddAnimeWindow::checkOnValidity);

}

void AddAnimeWindow::checkOnValidity()
{
    if (_nameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_desriptionEdit->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_genresEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_scoreEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_typesEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_episodesEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_ariedEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_studiosEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_licensorsEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_sourceEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_durationEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_ratingEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Please fill in all the fields", "ok");
        return;
    }
    if (_producersEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Incorrect input", "Please fill in all the fields");
        return;
    }

    addAnimeToMdodel();

}

void AddAnimeWindow::addAnimeToMdodel() const
{
    Anime* newAnime = new Anime();
    newAnime->setName(_nameEdit->text());
    newAnime->setDescription(_desriptionEdit->toPlainText());
    QStringList genres = _genresEdit->text().split(' ');
    newAnime->setStringListGenres(genres);
    newAnime->setScore(_scoreEdit->text());
    newAnime->setType(_typesEdit->text());
    newAnime->setEpisodes(_episodesEdit->text());
    newAnime->setAried(_ariedEdit->text());
    newAnime->setStudios(_studiosEdit->text());
    newAnime->setLicensors(_licensorsEdit->text());
    newAnime->setSource(_sourceEdit->text());
    newAnime->setDuration(_durationEdit->text());
    newAnime->setRating(_ratingEdit->text());
    newAnime->setProducers(_producersEdit->text());

    int randomInt = QRandomGenerator::global()->bounded(10, 10000);
    QString randomString = QString::number(randomInt);
    newAnime->setRanked(randomString);

    randomInt = QRandomGenerator::global()->bounded(10, 5000);
    randomString = QString::number(randomInt);
    newAnime->setPopularity(randomString);

    randomInt = QRandomGenerator::global()->bounded(1000, 100000);
    randomString = QString::number(randomInt);
    newAnime->setMembers(randomString);

    randomInt = QRandomGenerator::global()->bounded(10, 100000);
    randomString = QString::number(randomInt);
    newAnime->setFavorites(randomString);

    randomInt = QRandomGenerator::global()->bounded(10, 150000);
    randomString = QString::number(randomInt);
    newAnime->setWatching(randomString);

    randomInt = QRandomGenerator::global()->bounded(1000, 1000000);
    randomString = QString::number(randomInt);
    newAnime->setCompleted(randomString);

    randomInt = QRandomGenerator::global()->bounded(100, 100000);
    randomString = QString::number(randomInt);
    newAnime->setOn_hold(randomString);

    randomInt = QRandomGenerator::global()->bounded(100, 500000);
    randomString = QString::number(randomInt);
    newAnime->setPlanToWatch(randomString);

    randomInt = QRandomGenerator::global()->bounded(100, 100000);
    randomString = QString::number(randomInt);
    newAnime->setDropped(randomString);


    _nameEdit->clear();
    _desriptionEdit->clear();
    _scoreEdit->clear();
    _genresEdit->clear();
    _typesEdit->clear();
    _episodesEdit->clear();
    _ariedEdit->clear();
    _studiosEdit->clear();
    _licensorsEdit->clear();
    _sourceEdit->clear();
    _durationEdit->clear();
    _ratingEdit->clear();
    _producersEdit->clear();


    emit dataPassed(newAnime);
    goBack();


}

void AddAnimeWindow::goBack() const
{
    emit goToTheMainWindow();
}
