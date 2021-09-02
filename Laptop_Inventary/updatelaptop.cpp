#include "updatelaptop.h"
#include "ui_updatelaptop.h"

UpdateLaptop::UpdateLaptop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLaptop)
{
    ui->setupUi(this);
    hideAllElements();
}

UpdateLaptop::~UpdateLaptop()
{
    delete ui;
}

void UpdateLaptop::on_btnFind_clicked()
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
       qDebug() << "ScreenSize is : " << query.value(6).toString();
       ui->cmbScreensize->setCurrentIndex(ui->cmbScreensize->findText(query.value(6).toString()));
       ui->txtColor->setText(query.value(7).toString());
       ui->cmbInWarrenty->setCurrentIndex(ui->cmbInWarrenty->findText(query.value(8).toString()));
       ui->cmbAdaptor->setCurrentIndex(ui->cmbAdaptor->findText(query.value(9).toString()));
       ui->cmbBag->setCurrentIndex(ui->cmbBag->findText(query.value(10).toString()));
       ui->cmbStatus->setCurrentIndex(ui->cmbStatus->findText(query.value(11).toString()));

       //QString lblname = "lbl" + seat;
    }
    if(flag == 1)
    {
        showAllElements();
    }

    //if(flag == -1)
      //   ui->lblInfo->show();

}

void UpdateLaptop:: showAllElements()
{
    ui->txtDOE->show(); ui->lblDOE->show();
    ui->txtMake->show(); ui->lblMake->show();
    ui->txtColor->show(); ui->lblColor->show();
    ui->txtProcessor->show(); ui->lblProcessor->show();
    ui->txtRAMsize->show(); ui->lblRamSize->show();
    ui->lblSerialNo->show();
    ui->txtMfgYear->show(); ui->lblMfgYear->show();
    ui->cmbBag->show(); ui->lblBag->show();
    ui->cmbInWarrenty->show(); ui->lblInWarrenty->show();
    ui->cmbScreensize->show(); ui->lblScreensize->show();
    ui->cmbAdaptor->show(); ui->lblAdaptor->show();
    ui->cmbStatus->show(); ui->lblStatus->show();
     ui->pushButton->show();
}

void UpdateLaptop::hideAllElements()
{
    ui->txtDOE->hide(); ui->lblDOE->hide();
    ui->txtMake->hide(); ui->lblMake->hide();
    ui->txtColor->hide(); ui->lblColor->hide();
    ui->txtProcessor->hide(); ui->lblProcessor->hide();
    ui->txtRAMsize->hide(); ui->lblRamSize->hide();
    ui->txtSerialNo->hide(); ui->lblSerialNo->hide();
    ui->txtMfgYear->hide(); ui->lblMfgYear->hide();
    ui->cmbBag->hide(); ui->lblBag->hide();
    ui->cmbInWarrenty->hide(); ui->lblInWarrenty->hide();
    ui->cmbScreensize->hide(); ui->lblScreensize->hide();
    ui->cmbAdaptor->hide(); ui->lblAdaptor->hide();
    ui->cmbStatus->hide(); ui->lblStatus->hide();
    ui->pushButton->hide();
    ui->lblInfo->hide();
}

void UpdateLaptop::on_pushButton_clicked()
{

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
    query.clear();
   /* query.prepare("update cppbuzz_laptop_inventory (SerialNo, Make, DOE, MfcYear, RAM, Processor, ScreenSize, Color, InWarrenty, HasAdaptor, HasBag, Status) values ('"
                  + sSerialNo + "','"+ sMake + "','" + sDOE + "','" + sMfgYear + "','" + sRamSize + "','" + sProcessor + "','" + sSize + "','" + sColor + "','" + sWarrenty + "','" + sAdaptor + "','" + sBag + "','" + sStatus + "')");
    */

    query.prepare("update cppbuzz_laptop_inventory set Make = '" + sMake + "',DOE = '"+ sDOE + "',MfcYear = '" + sMfgYear + "',RAM ='" + sRamSize + "', Processor = '" + sProcessor + "',ScreenSize ='" + sSize + "',Color='" + sColor + "', InWarrenty='" + sWarrenty + "',HasAdaptor = '" + sAdaptor + "', HasBag = '" + sBag + "',Status='" + sStatus + "' where SerialNo = '" + sSerialNo + "'");

   if(!query.exec())
   {
       qDebug() << query.lastError().text() << query.lastQuery();
       ui->lblInfo->show();
   }
   else
   {
       qDebug() << "read was successful "<< query.lastQuery();
       hideAllElements();
       ui->lblInfo->setText("Record updated successfully!");
       ui->lblInfo->show();

   }
   //changin default style of seats those are available

}
