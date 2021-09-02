#ifndef ADDLAPTOP_H
#define ADDLAPTOP_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mydb.h"

namespace Ui {
class AddLaptop;
}

class AddLaptop : public QDialog
{
    Q_OBJECT

public:
    explicit AddLaptop(QWidget *parent = nullptr);
    ~AddLaptop();

private slots:
    void on_btnReset_clicked();
    void on_btnAdd_clicked();
    void resetAllElements();
private:
    Ui::AddLaptop *ui;
};

#endif // ADDLAPTOP_H
