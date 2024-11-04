/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *login_button;
    QPushButton *create_account_button;
    QLabel *create_account_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *email_label;
    QLabel *password_label;
    QVBoxLayout *verticalLayout;
    QLineEdit *email_inpu;
    QLineEdit *email_input;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(519, 351);
        Form->setMaximumSize(QSize(519, 351));
        login_button = new QPushButton(Form);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(160, 140, 81, 21));
        create_account_button = new QPushButton(Form);
        create_account_button->setObjectName("create_account_button");
        create_account_button->setGeometry(QRect(160, 190, 81, 18));
        create_account_label = new QLabel(Form);
        create_account_label->setObjectName("create_account_label");
        create_account_label->setGeometry(QRect(40, 190, 101, 16));
        horizontalLayoutWidget = new QWidget(Form);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(80, 40, 251, 71));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        email_label = new QLabel(horizontalLayoutWidget);
        email_label->setObjectName("email_label");

        verticalLayout_3->addWidget(email_label);

        password_label = new QLabel(horizontalLayoutWidget);
        password_label->setObjectName("password_label");

        verticalLayout_3->addWidget(password_label);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        email_inpu = new QLineEdit(horizontalLayoutWidget);
        email_inpu->setObjectName("email_inpu");

        verticalLayout->addWidget(email_inpu);

        email_input = new QLineEdit(horizontalLayoutWidget);
        email_input->setObjectName("email_input");

        verticalLayout->addWidget(email_input);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        login_button->setText(QCoreApplication::translate("Form", "Login", nullptr));
        create_account_button->setText(QCoreApplication::translate("Form", "Create Account", nullptr));
        create_account_label->setText(QCoreApplication::translate("Form", "Don't have an Account", nullptr));
        email_label->setText(QCoreApplication::translate("Form", "Email", nullptr));
        password_label->setText(QCoreApplication::translate("Form", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
