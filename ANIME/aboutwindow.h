#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTextEdit>
#include <QWidget>
#include <QLinearGradient>
#include <QFont>
#include <QFontMetrics>

class AboutWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AboutWindow(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent*) override;
private:
    QTextEdit* textEdit;


};

#endif // ABOUTWINDOW_H
