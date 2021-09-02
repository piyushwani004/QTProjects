#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400, 470);
    init();

    ptrAddLaptop = new AddLaptop(this);
    ptrFindLaptop = new FindLaptop(this);
    ptrGetReport = new GetReport(this);
    ptrUpdateLaptop = new UpdateLaptop(this);

}

void MainWindow::init()
{
    QBarSet *set0 = new QBarSet("In Use");
    QBarSet *set1 = new QBarSet("Available");
    QBarSet *set2 = new QBarSet("Out of Order");

    *set0 << getInUseLaptopCount();
    *set1 << getAvailableLaptopCount();
    *set2 << getOutOfOrderLaptopCount();

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Status of Inventory");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << " " ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->setGeometry(0,100,300,200);
    chartView->resize(200,150);
    //this->setCentralWidget(chartView);
    ui->verticalLayout->addWidget(chartView);

}
MainWindow::~MainWindow()
{
    delete ui;
    MyDB::ResetInstance(); //delete DB instance
    delete ptrAddLaptop; ptrAddLaptop = nullptr;
    delete ptrFindLaptop; ptrFindLaptop = nullptr;
    delete ptrGetReport; ptrFindLaptop = nullptr;
    delete ptrUpdateLaptop; ptrUpdateLaptop = nullptr;

}

void MainWindow::on_btnAdd_clicked()
{
    ptrAddLaptop->show();
}

void MainWindow::on_btnUpdate_clicked()
{
    ptrUpdateLaptop->show();
}

void MainWindow::on_btnFind_clicked()
{
    ptrFindLaptop->show();
}

void MainWindow::on_btnAdd_2_clicked()
{
    ptrGetReport->init();
    ptrGetReport->show();

}

int MainWindow::getOutOfOrderLaptopCount()
{
    qDebug() << " in MyDB::getOutOfOrderLaptopCount()";

    QSqlQuery query( MyDB::getInstance()->getDBInstance());

    //first check if SerialNo already exist
    query.prepare("select count(Id) from cppbuzz_laptop_inventory where Status = 'Out of Order'");
    int count = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "read was successful "<< query.lastQuery();
        query.next();

        count = query.value(0).toInt();
        qDebug()<< "Out of Order Count is : "<<count;
        return count;
    }
    return 0;
}

int MainWindow::getAvailableLaptopCount()
{
    qDebug() <<"in MyDB::getAvailableLaptopCount()";

    QSqlQuery query( MyDB::getInstance()->getDBInstance());

    //first check if SerialNo already exist
    query.prepare("select count(Id) from cppbuzz_laptop_inventory where Status = 'Available'");
    int count = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "read was successful "<< query.lastQuery();
        query.next();

        count = query.value(0).toInt();
        qDebug()<< "Out of Order Count is : "<<count;
        return count;
    }
    return 0;
}

int MainWindow::getInUseLaptopCount()
{
    qDebug() <<" in MyDB::getInUseLaptopCount()";

    QSqlQuery query( MyDB::getInstance()->getDBInstance());

    //first check if SerialNo already exist
    query.prepare("select count(Id) from cppbuzz_laptop_inventory where Status = 'In Use'");
    int count = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "read was successful "<< query.lastQuery();
        query.next();

        count = query.value(0).toInt();
        qDebug()<< "Out of Order Count is : "<<count;
        return count;
    }
    return 0;
}
