#ifndef PASSWORDINPUTWINDOW_H
#define PASSWORDINPUTWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

class PasswordInputWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PasswordInputWindow(QWidget *parent = nullptr);
private:
    QLineEdit* passwordLineEdit;

public slots:
    void onSubmitButtonClicked();

signals:
    void passwordVerified();


};

#endif // PASSWORDINPUTWINDOW_H
