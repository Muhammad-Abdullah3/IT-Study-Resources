#include "widget.h"
#include "homepage.h"
#include <QApplication>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Doc-Spot");
    resize(1920,1080);

    QLabel *email_label = new QLabel(this);
    email_label->setText("Email");
    email_label->setGeometry(500,200,100,20);
    email_label->setFont(QFont("Times",16));

    QLineEdit *email_text_box = new QLineEdit(this);
    email_text_box->setGeometry(610,200,300,30);
    email_text_box->setFont(QFont("Times",11));

    QLabel *password_label = new QLabel(this);
    password_label->setText("Password");
    password_label->setGeometry(500,260,100,20);
    password_label->setFont(QFont("Times",16));

    QLineEdit *password_text_box = new QLineEdit(this);
    password_text_box->setGeometry(610,260,300,30);
    password_text_box->setFont(QFont("Times",11));
    password_text_box->setEchoMode(QLineEdit::EchoMode::Password);

    QPushButton *login_button = new QPushButton(this);
    login_button->setText("Login");
    login_button->setGeometry(580,360,150,30);
    login_button->setFont(QFont("Times",16));
    login_button->setIcon(QIcon(":/images/login.png"));
    login_button->setIconSize(QSize(16,16));
    //connect(login_button,SIGNAL(clicked()),this, SLOT(loginn()));

}




