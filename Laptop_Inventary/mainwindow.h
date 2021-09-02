#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "addlaptop.h"
#include "findlaptop.h"
#include "getreport.h"
#include "updatelaptop.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnUpdate_clicked();
    void on_btnFind_clicked();

    void on_btnAdd_2_clicked();

private:
    Ui::MainWindow *ui;
    void init();

    AddLaptop    * ptrAddLaptop;
    FindLaptop   * ptrFindLaptop;
    GetReport    * ptrGetReport;
    UpdateLaptop * ptrUpdateLaptop;

    int getOutOfOrderLaptopCount();
    int getAvailableLaptopCount();
    int getInUseLaptopCount();

};
#endif // MAINWINDOW_H
