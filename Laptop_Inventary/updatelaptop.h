#ifndef UPDATELAPTOP_H
#define UPDATELAPTOP_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mydb.h"

namespace Ui {
class UpdateLaptop;
}

class UpdateLaptop : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLaptop(QWidget *parent = nullptr);
    ~UpdateLaptop();

private slots:
    void on_btnFind_clicked();

    void on_pushButton_clicked();

private:
    Ui::UpdateLaptop *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // UPDATELAPTOP_H
