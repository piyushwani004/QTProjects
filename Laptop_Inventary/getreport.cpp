#include "getreport.h"
#include "ui_getreport.h"

GetReport::GetReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetReport)
{
    ui->setupUi(this);
    init();
}

GetReport::~GetReport()
{
    delete ui;
}

void GetReport::readDatafromDB()
{
    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select seat_number from cppbuzz_airo_seats where available='Y'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "read was successful "<< query.lastQuery();
    //db.close();

    //changin default style of seats those are available
    while(query.next())
    {
       QString seat = query.value(0).toString();
       QString lblname = "lbl" + seat;
    }
}

void GetReport::init()
{
    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select SerialNo, Make, DOE, MfcYear, RAM, Processor, ScreenSize, Color, InWarrenty, HasAdaptor, HasBag, Status from cppbuzz_laptop_inventory");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "== success query fetch()";

    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();
}
