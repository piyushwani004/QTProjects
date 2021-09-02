#ifndef FINDLAPTOP_H
#define FINDLAPTOP_H

#include <QDialog>
#include <QDebug>
#include "mydb.h"
#include <QSqlQuery>

namespace Ui {
class FindLaptop;
}

class FindLaptop : public QDialog
{
    Q_OBJECT

public:
    explicit FindLaptop(QWidget *parent = nullptr);
    ~FindLaptop();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindLaptop *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // FINDLAPTOP_H
