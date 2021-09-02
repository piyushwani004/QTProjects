#ifndef GETREPORT_H
#define GETREPORT_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include "mydb.h"
#include <QSqlQueryModel>

namespace Ui {
class GetReport;
}

class GetReport : public QDialog
{
    Q_OBJECT

public:
    explicit GetReport(QWidget *parent = nullptr);
    ~GetReport();
     void init();

private:
    Ui::GetReport *ui;
    void readDatafromDB();

};

#endif // GETREPORT_H
