/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QTableWidget *deviceTable;
    QPushButton *addButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(400, 300);
        deviceTable = new QTableWidget(Dashboard);
        if (deviceTable->columnCount() < 3)
            deviceTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        deviceTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        deviceTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        deviceTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        deviceTable->setObjectName("deviceTable");
        deviceTable->setGeometry(QRect(50, 40, 301, 201));
        deviceTable->setColumnCount(3);
        addButton = new QPushButton(Dashboard);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(290, 250, 100, 32));
        deleteButton = new QPushButton(Dashboard);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(170, 250, 100, 32));

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = deviceTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dashboard", "\350\256\276\345\244\207ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = deviceTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dashboard", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = deviceTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dashboard", "\350\256\276\345\244\207\347\212\266\346\200\201", nullptr));
        addButton->setText(QCoreApplication::translate("Dashboard", "\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        deleteButton->setText(QCoreApplication::translate("Dashboard", "\345\210\240\351\231\244\350\256\276\345\244\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
