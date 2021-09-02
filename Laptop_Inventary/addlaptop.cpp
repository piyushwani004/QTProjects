#include "addlaptop.h"
#include "ui_addlaptop.h"

AddLaptop::AddLaptop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLaptop)
{
    ui->setupUi(this);
}

AddLaptop::~AddLaptop()
{
    delete ui;
}


void AddLaptop::on_btnReset_clicked()
{
    resetAllElements();
}

void AddLaptop::on_btnAdd_clicked()
{
    qDebug()<<"in AddLaptop:: on_btnAdd_clicked()";

    QString sSerialNo  = ui->txtSerialNo->text();
    QString sMake      = ui->txtMake->text();
    QString sColor     = ui->txtColor->text();
    QString sDOE       = ui->txtDOE->text();

    QString sMfgYear   = ui->txtMfgYear->text();
    QString sRamSize   = ui->txtRAMsize->text();
    QString sProcessor = ui->txtProcessor->text();

    QString sSize     = ui->cmbScreensize->currentText();
    QString sStatus   = ui->cmbStatus->currentText();
    QString sBag      = ui->cmbBag->currentText();
    QString sAdaptor  = ui->cmbAdaptor->currentText();
    QString sWarrenty = ui->cmbInWarrenty->currentText();

    QSqlQuery query( MyDB::getInstance()->getDBInstance());

    //first check if SerialNo already exist
    query.prepare("select count(Id) from cppbuzz_laptop_inventory where SerialNo = '" + sSerialNo + "'");
    int flag = -1;
    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        //flag = 1;
    }
    else
    {
        qDebug() << "read was successful "<< query.lastQuery();
        query.next();
        flag = query.value(0).toInt();
        if(flag>0)
        {
        qDebug() <<" Serial No already exist";
        ui->lblInfo->setText("Serial No Alread Exist");
        }
    }

    if(flag <= 0)
    {
        query.clear();
        query.prepare("insert into cppbuzz_laptop_inventory (SerialNo, Make, DOE, MfcYear, RAM, Processor, ScreenSize, Color, InWarrenty, HasAdaptor, HasBag, Status) values ('"
                      + sSerialNo + "','"+ sMake + "','" + sDOE + "','" + sMfgYear + "','" + sRamSize + "','" + sProcessor + "','" + sSize + "','" + sColor + "','" + sWarrenty + "','" + sAdaptor + "','" + sBag + "','" + sStatus + "')");

       if(!query.exec())
       {
           qDebug() << query.lastError().text() << query.lastQuery();

       }
        else
       {
           qDebug() << "read was successful "<< query.lastQuery();
            resetAllElements();
           ui->lblInfo->setText("Laptop Added Successfully!");
           //changin default style of seats those are available
       }
   }
}

void AddLaptop::resetAllElements()
{
    qDebug() << "in AddLaptop:: resetAllElements()";
    ui->txtDOE->clear();
    ui->txtMake->clear();
    ui->txtColor->clear();
    ui->txtProcessor->clear();
    ui->txtRAMsize->clear();
    ui->txtSerialNo->clear();
    ui->txtMfgYear->clear();
    ui->cmbBag->setCurrentIndex(0);
    ui->cmbInWarrenty->setCurrentIndex(0);
    ui->cmbScreensize->setCurrentIndex(0);
    ui->cmbAdaptor->setCurrentIndex(0);
    ui->cmbStatus->setCurrentIndex(0);

}
