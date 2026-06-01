#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

signals:
    void backToLogin();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::Dashboard *ui;
    void initTable();
};

#endif // DASHBOARD_H
