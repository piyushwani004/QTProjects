#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ResultBtn_clicked()
{

    QString Name = ui->NameEditTxt->toPlainText();
    QString RollNo = ui->RollNoEditTxt->toPlainText();



}

