#include "detailedwindow.h"
#include "QPushButton"
#include "QGridLayout"
#include "QSpacerItem"
#include <sstream>
#include <QFont>
#include <QTextEdit>
#include <QAbstractProxyModel>


DetailedWindow::DetailedWindow(Anime* selectedAnime, QWidget *parent)
    : QMainWindow{parent}, _selectedAnime(selectedAnime)
{


    QVBoxLayout* mainLayout = new QVBoxLayout;
    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(mainLayout);

    QHBoxLayout* threeColumnLayout = new QHBoxLayout;
    mainLayout->addLayout(threeColumnLayout);

    QVBoxLayout* leftColumnLayout = new QVBoxLayout;
    threeColumnLayout->addLayout(leftColumnLayout);

    QVBoxLayout* rightColumnLayout = new QVBoxLayout;
    rightColumnLayout->setSpacing(0);
    threeColumnLayout->addLayout(rightColumnLayout);

    _nameLabel->setReadOnly(true);
    _nameLabel->setStyleSheet("border: 0; background-color: transparent;");
    _nameLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _nameLabel->setMaximumHeight(50);
    leftColumnLayout->addWidget(_nameLabel);

    _genresLabel->setReadOnly(true);
    _genresLabel->setStyleSheet("border: 0; background-color: transparent;");

    _genresLabel->setFixedHeight(40);


    leftColumnLayout->addWidget(_genresLabel);

    _descriptionLabel->setReadOnly(true);
    _descriptionLabel->setStyleSheet("border: 0; background-color: transparent;");
    _descriptionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _descriptionLabel->setMinimumWidth(150);
    _descriptionLabel->setMinimumHeight(300);
    leftColumnLayout->addWidget(_descriptionLabel);

    _scoreLabel->setReadOnly(true);
    _scoreLabel->setStyleSheet("border: 0; background-color: transparent;");
    _scoreLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _scoreLabel->setMaximumHeight(25);
    rightColumnLayout->addWidget(_scoreLabel);

    _typeLabel->setReadOnly(true);
    _typeLabel->setStyleSheet("border: 0; background-color: transparent;");
    _typeLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _typeLabel->setMaximumHeight(25);
    rightColumnLayout->addWidget(_typeLabel);

    _episodesLabel->setReadOnly(true);
    _episodesLabel->setStyleSheet("border: 0; background-color: transparent;");
    _episodesLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _episodesLabel->setMaximumHeight(25);
    rightColumnLayout->addWidget(_episodesLabel);

    _ariedLabel->setReadOnly(true);
    _ariedLabel->setStyleSheet("border: 0; background-color: transparent;");
    _ariedLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _ariedLabel->setMaximumHeight(30);
    rightColumnLayout->addWidget(_ariedLabel);

    _studiosLabel->setReadOnly(true);
    _studiosLabel->setStyleSheet("border: 0; background-color: transparent;");
    _studiosLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _studiosLabel->setMaximumHeight(30);
    rightColumnLayout->addWidget(_studiosLabel);

    _licensorsLabel->setReadOnly(true);
    _licensorsLabel->setStyleSheet("border: 0; background-color: transparent;");
    _licensorsLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _licensorsLabel->setMaximumHeight(40);
    rightColumnLayout->addWidget(_licensorsLabel);

    _sourceLabel->setReadOnly(true);
    _sourceLabel->setStyleSheet("border: 0; background-color: transparent;");
    _sourceLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _sourceLabel->setMaximumHeight(30);
    rightColumnLayout->addWidget(_sourceLabel);

    _durationLabel->setReadOnly(true);
    _durationLabel->setStyleSheet("border: 0; background-color: transparent;");
    _durationLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _durationLabel->setMaximumHeight(25);
    rightColumnLayout->addWidget(_durationLabel);

    _ratingLabel->setReadOnly(true);
    _ratingLabel->setStyleSheet("border: 0; background-color: transparent;");
    _ratingLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _ratingLabel->setMaximumHeight(25);
    rightColumnLayout->addWidget(_ratingLabel);

    _producersLabel->setReadOnly(true);
    _producersLabel->setStyleSheet("border: 0; background-color: transparent;");
    _producersLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _producersLabel->setMaximumHeight(60);
    rightColumnLayout->addWidget(_producersLabel);


    threeColumnLayout->setStretch(0,1);


    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addSpacerItem(spacer);


    goBackButton = new QPushButton("Go Back");
    mainLayout->addWidget(goBackButton, 0, Qt::AlignTop | Qt::AlignRight);
    connect(goBackButton, &QPushButton::clicked, this, &DetailedWindow::switchToMainWindow);

}




void DetailedWindow::setAnime(Anime* selected)
{
    _selectedAnime = selected;

    QFont fontName;
    fontName.setBold(true);
    fontName.setPointSize(20);

    QFont secondfont;
    secondfont.setBold(true);

    _nameLabel->setText("<html><b><big>" + _selectedAnime->getName() + "</big></b></html>");

    _descriptionLabel->setText(_selectedAnime->getDescription());


    _genresLabel->setText("<html><b></h6> Genres: </h6></b></html>" + _selectedAnime->getStringGenres());
    _genresLabel->setReadOnly(true);

    _scoreLabel->setText("<html><b></h6> Score: </h6></b></html>" + _selectedAnime->getScore());
    _episodesLabel->setText("<html><b></h6> Episodes: </h6></b></html>" + _selectedAnime->getEpisodes());
    _typeLabel->setText("<html><b></h6> Types: </h6></b></html>" + _selectedAnime->getType());
    _ariedLabel->setText("<html><b></h6> Aried: </h6></b></html>" + _selectedAnime->getAried());
    _producersLabel->setText("<html><b></h6> Producers: </h6></b></html>" + _selectedAnime->getProducers());
    _licensorsLabel->setText("<html><b></h6> Licensors: </h6></b></html>" + _selectedAnime->getLicensors());
    _studiosLabel->setText("<html><b></h6> Studios: </h6></b></html>" + _selectedAnime->getStudios());
    _sourceLabel->setText("<html><b></h6> Source: </h6></b></html>" + _selectedAnime->getSource());
    _durationLabel->setText("<html><b></h6> Duration: </h6></b></html>" + _selectedAnime->getDuration());
    _ratingLabel->setText("<html><b></h6> Rating: </h6></b></html>" + _selectedAnime->getRating());
}


