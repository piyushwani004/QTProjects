#include "findlaptop.h"
#include "ui_findlaptop.h"

FindLaptop::FindLaptop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindLaptop)
{
    ui->setupUi(this);
    hideAllElements();
}

FindLaptop::~FindLaptop()
{
    delete ui;
}

void FindLaptop::on_btnFind_clicked()
{
    qDebug() << "in FindLaptop::on_btnFind_clickec()";
    hideAllElements();
    QString sSerialNo = ui->txtSerialNoFind->text();

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select SerialNo, Make, DOE, MfcYear, RAM, Processor, ScreenSize, Color, InWarrenty, HasAdaptor, HasBag, Status from cppbuzz_laptop_inventory where SerialNo='" + sSerialNo + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "read was successful "<< query.lastQuery();
    //db.close();


    char flag = -1;
    //changin default style of seats those are available
    while(query.next())
    {  flag = 1;
       ui->txtSerialNo->setText(query.value(0).toString());
       ui->txtMake->setText(query.value(1).toString());
       ui->txtDOE->setText(query.value(2).toString());
       ui->txtMfgYear->setText(query.value(3).toString());
       ui->txtRAMsize->setText(query.value(4).toString());
       ui->txtProcessor->setText(query.value(5).toString());
       ui->txtScreenSize->setText(query.value(6).toString());
       ui->txtColor->setText(query.value(7).toString());
       ui->txtInWarrenty->setText(query.value(8).toString());
       ui->txtAdaptor->setText(query.value(9).toString());
       ui->txtBag->setText(query.value(10).toString());
       ui->txtStatus->setText(query.value(11).toString());

       //QString lblname = "lbl" + seat;
    }
    if(flag == 1)
        showAllElements();

    if(flag == -1)
         ui->lblInfo->show();
}

void FindLaptop:: showAllElements()
{
    ui->txtDOE->show();  ui->lblDOE->show();
    ui->txtMake->show(); ui->lblMake->show();
    ui->txtColor->show(); ui->lblColor->show();
    ui->txtProcessor->show(); ui->lblProcessor->show();
    ui->txtRAMsize->show(); ui->lblRamSize->show();
    ui->txtSerialNo->show(); ui->lblSerialNo->show();
    ui->txtMfgYear->show(); ui->lblMfgYear->show();
    ui->txtBag->show(); ui->lblBag->show();
    ui->txtInWarrenty->show(); ui->lblInWarrenty->show();
    ui->txtScreenSize->show(); ui->lblScreensize->show();
    ui->txtAdaptor->show(); ui->lblAdaptor->show();
    ui->txtStatus->show(); ui->lblStatus->show();
}

void FindLaptop::hideAllElements()
{   ui->lblInfo->hide();
    ui->txtDOE->hide(); ui->lblDOE->hide();
    ui->txtMake->hide(); ui->lblMake->hide();
    ui->txtColor->hide(); ui->lblColor->hide();
    ui->txtProcessor->hide(); ui->lblProcessor->hide();
    ui->txtRAMsize->hide(); ui->lblRamSize->hide();
    ui->txtSerialNo->hide(); ui->lblSerialNo->hide();
    ui->txtMfgYear->hide(); ui->lblMfgYear->hide();
    ui->txtBag->hide(); ui->lblBag->hide();
    ui->txtInWarrenty->hide(); ui->lblInWarrenty->hide();
    ui->txtScreenSize->hide(); ui->lblScreensize->hide();
    ui->txtAdaptor->hide(); ui->lblAdaptor->hide();
    ui->txtStatus->hide(); ui->lblStatus->hide();
}
