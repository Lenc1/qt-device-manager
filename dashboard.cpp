#include "dashboard.h"
#include "ui_dashboard.h"
#include <QInputDialog>
#include <QMessageBox>

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    initTable();
}

Dashboard::~Dashboard()
{
    qDebug() << "Dashboard destroyed";

    delete ui;
}

void Dashboard::closeEvent(QCloseEvent *event)
{
    emit backToLogin();

    QWidget::closeEvent(event);
}

void Dashboard::initTable(){
    ui->deviceTable->setRowCount(3);
    ui->deviceTable->setItem(
        0,0,
        new QTableWidgetItem("1001")
    );
    ui->deviceTable->setItem(
        0,1,
        new QTableWidgetItem("传感器A")
    );
    ui->deviceTable->setItem(
        0,2,
        new QTableWidgetItem("在线")
    );
    ui->deviceTable->setItem(
        1,0,
        new QTableWidgetItem("1002")
    );
    ui->deviceTable->setItem(
        1,1,
        new QTableWidgetItem("摄像头B")
    );
    ui->deviceTable->setItem(
        1,2,
        new QTableWidgetItem("离线")
    );
    ui->deviceTable->setItem(
        2,0,
        new QTableWidgetItem("1003")
    );
    ui->deviceTable->setItem(
        2,1,
        new QTableWidgetItem("PLC-C")
    );
    ui->deviceTable->setItem(
        2,2,
        new QTableWidgetItem("在线")
    );
}
void Dashboard::on_addButton_clicked()
{
    bool ok;
    QString id = QInputDialog::getText(
        this,
        "添加设备",
        "请输入设备ID：",
        QLineEdit::Normal,
        "",
        &ok
    );

    if(!ok || id.isEmpty()){
        return;
    }

    QString name = QInputDialog::getText(
        this,
        "添加设备",
        "请输入设备名称：",
        QLineEdit::Normal,
        "",
        &ok
    );

    if(!ok || name.isEmpty())
    {
        return;
    }

    int row = ui->deviceTable->rowCount();

    ui->deviceTable->insertRow(row);

    ui->deviceTable->setItem(
        row, 0,
        new QTableWidgetItem(id)
    );

    ui->deviceTable->setItem(
        row, 1,
        new QTableWidgetItem(name)
    );

    ui->deviceTable->setItem(
        row, 2,
        new QTableWidgetItem("在线")
    );
}


void Dashboard::on_deleteButton_clicked()
{
    int row = ui->deviceTable->currentRow();

    if(row < 0)
    {
        QMessageBox::warning(
            this,
            "提示",
            "请先选择一条设备记录"
            );

        return;
    }

    ui->deviceTable->removeRow(row);

}

