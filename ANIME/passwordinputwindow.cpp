#include "passwordinputwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QThread>
#include <QTextEdit>

PasswordInputWindow::PasswordInputWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QWidget *centralWindget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    setCentralWidget(centralWindget);
    centralWindget->setLayout(layout);

    QTextEdit *infoBlock = new QTextEdit("Input the admin password");
    infoBlock->setReadOnly(true);
    infoBlock->setAlignment(Qt::AlignCenter);
    infoBlock->setStyleSheet("border: 0; background-color: transparent;");
    //infoBlock->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    infoBlock->setMaximumHeight(30);
    layout->addWidget(infoBlock);
    passwordLineEdit = new QLineEdit;
    layout->addWidget(passwordLineEdit);
    //passwordLineEdit->setMaximumWidth(150);
    //passwordLineEdit->setAlignment(Qt::AlignCenter);


    QPushButton* submitButton = new QPushButton("Submit");
    layout->addWidget(submitButton);
    connect(submitButton, &QPushButton::clicked, this, &PasswordInputWindow::onSubmitButtonClicked);
}

void PasswordInputWindow::onSubmitButtonClicked()
{
    QString enteredPassword = passwordLineEdit->text();

    if (enteredPassword == "dsba") {
        //QThread::sleep(1);
        emit passwordVerified();
        close();
    }
    else {
        QMessageBox::warning(this, "Incorrect Password", "Please enter the correct password.");
    }
}
