#ifndef ADDANIMEWINDOW_H
#define ADDANIMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include "anime.h"
#include <QTextEdit>

class AddAnimeWindow: public QMainWindow
{
    Q_OBJECT
public:
    AddAnimeWindow(QWidget *parent = nullptr);
    void goBack() const;
    void addAnimeToMdodel() const;
signals:
    void goToTheMainWindow() const;
    void dataPassed(Anime* anime) const;

public slots:
    void checkOnValidity();



private:
    QLineEdit* _nameEdit = new QLineEdit;
    QLineEdit* _genresEdit = new QLineEdit;
    QTextEdit* _desriptionEdit = new QTextEdit;
    QLineEdit* _scoreEdit = new QLineEdit;
    QLineEdit* _typesEdit = new QLineEdit;
    QLineEdit* _episodesEdit = new QLineEdit;
    QLineEdit* _ariedEdit = new QLineEdit;
    QLineEdit* _studiosEdit = new QLineEdit;
    QLineEdit* _licensorsEdit = new QLineEdit;
    QLineEdit* _sourceEdit = new QLineEdit;
    QLineEdit* _durationEdit = new QLineEdit;
    QLineEdit* _ratingEdit = new QLineEdit;
    QLineEdit* _producersEdit = new QLineEdit;

};





#endif // ADDANIMEWINDOW_H
