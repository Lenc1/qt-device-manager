#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dashboard = new Dashboard;
    connect(
        dashboard,
        &Dashboard::backToLogin,
        this,
        &MainWindow::show
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username=="admin" && password == "123456") {
        dashboard->show();
        this->hide();
    }
    else {
        QMessageBox::warning(
            this,
            "",
            "用户名或密码错误"
            );
    }
}