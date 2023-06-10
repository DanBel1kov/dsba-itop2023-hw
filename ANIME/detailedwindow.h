#ifndef DETAILEDWINDOW_H
#define DETAILEDWINDOW_H

#include <QMainWindow>
#include "anime.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

class DetailedWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DetailedWindow( Anime* selectedAnime, QWidget *parent = nullptr);
    void switchToMainWindow()
    {
        emit openMainWindow();
    }
    void setAnime(Anime* selected);



signals:
    void openMainWindow();



public slots:



private:
    Anime* _selectedAnime;
    QPushButton *goBackButton;
    QTextEdit* _nameLabel = new QTextEdit;
    QTextEdit* _descriptionLabel = new QTextEdit;
    QTextEdit* _scoreLabel = new QTextEdit;
    QTextEdit* _dataLabel = new QTextEdit;
    QTextEdit* _genresLabel = new QTextEdit;
    QTextEdit* _typeLabel = new QTextEdit;
    QTextEdit* _episodesLabel = new QTextEdit;
    QTextEdit* _ariedLabel = new QTextEdit;
    QTextEdit* _premieredLabel = new QTextEdit;
    QTextEdit* _producersLabel = new QTextEdit;
    QTextEdit* _licensorsLabel = new QTextEdit;
    QTextEdit* _studiosLabel = new QTextEdit;
    QTextEdit* _durationLabel = new QTextEdit;
    QTextEdit* _ratingLabel = new QTextEdit;
    QTextEdit* _sourceLabel = new QTextEdit;


};


#endif // DETAILEDWINDOW_H
