#include "dashboard.h"
#include "ui_dashboard.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    loadDevices();
    refreshTable();

    setAttribute(Qt::WA_DeleteOnClose);

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

void Dashboard::refreshTable()
{
    ui->deviceTable->clearContents();

    ui->deviceTable->setRowCount(devices.size());

    for(int i = 0; i < devices.size(); i++)
    {
        ui->deviceTable->setItem(
            i,
            0,
            new QTableWidgetItem(devices[i].id)
        );

        ui->deviceTable->setItem(
            i,
            1,
            new QTableWidgetItem(devices[i].name)
        );

        ui->deviceTable->setItem(
            i,
            2,
            new QTableWidgetItem(devices[i].status)
        );
        ui->deviceTable->setItem(
            i,
            3,
            new QTableWidgetItem(devices[i].videoUrl)
        );
    }
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
    QString videoUrl =QInputDialog::getText(
        this,
        "添加设备",
        "请输入视频文件路径：",
        QLineEdit::Normal,
        "",
        &ok
    );

    if(!ok || name.isEmpty())
    {
        return;
    }

    Device device;

    device.id = id;
    device.name = name;
    device.status = "在线";
    device.videoUrl = videoUrl;

    devices.push_back(device);

    refreshTable();
    saveDevices();
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

    devices.removeAt(row);
    saveDevices();

    refreshTable();

}
void Dashboard::saveDevices()
{
    QJsonArray array;

    for(const Device& device : devices)
    {
        QJsonObject obj;

        obj["id"] = device.id;
        obj["name"] = device.name;
        obj["status"] = device.status;
        obj["videoUrl"] = device.videoUrl;

        array.append(obj);
    }

    QJsonDocument doc(array);

    QFile file("devices.json");

    if(file.open(QIODevice::WriteOnly)){

        file.write(doc.toJson());

        file.close();
    }
}
void Dashboard::loadDevices()
{
    QFile file("devices.json");

    if(!file.exists())
    {
        return;
    }
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QByteArray data = file.readAll();

    file.close();

    QJsonDocument doc =
        QJsonDocument::fromJson(data);
    QJsonArray array = doc.array();

    devices.clear();

    for(auto value : array)
    {
        QJsonObject obj = value.toObject();

        Device device;

        device.id = obj["id"].toString();
        device.name = obj["name"].toString();
        device.status = obj["status"].toString();
        device.videoUrl =obj["videoUrl"].toString();

        devices.push_back(device);
    }


}

