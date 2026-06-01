/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loginButton;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *username;
    QLabel *password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(260, 160, 161, 51));
        usernameEdit = new QLineEdit(centralwidget);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(310, 70, 113, 21));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(310, 110, 113, 21));
        username = new QLabel(centralwidget);
        username->setObjectName("username");
        username->setGeometry(QRect(230, 70, 58, 16));
        password = new QLabel(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(230, 110, 58, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\351\231\206", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
