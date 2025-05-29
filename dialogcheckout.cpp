#include "dialogcheckout.h"
#include "ui_dialogcheckout.h"
#include "dialogrooms.h"
#include "hotel.h"
#include"room.h"
Dialogcheckout::Dialogcheckout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogcheckout)
{
    ui->setupUi(this);
    DialogRooms * parentdialog=dynamic_cast<DialogRooms*>(parent);
    pDialog=parentdialog;
    int roomno=parentdialog->getChosenroom();
    QString str=QString::number(roomno);
    //Qstring strname=
    Hotel * hotel=Hotel::getinstance();
    Room * room= hotel->findroom(roomno);
    QString customerName = QString::fromStdString(room->getMisafirAdi());
    ui->lineEdit_Customer->setText(customerName);
    ui->label_Odanum->setText(str);

}

Dialogcheckout::~Dialogcheckout()
{
    delete ui;
}

int Dialogcheckout::getTotaldays() const
{
    return totaldays;
}

void Dialogcheckout::setTotaldays(int newTotaldays)
{
    totaldays = newTotaldays;
}

void Dialogcheckout::on_pushButtonHesapla_clicked()
{
   // ui->lineEdit_Gun->text()
   bool ok;
   int days=ui->lineEdit_Gun->text().toInt(&ok);
   if(ok){
       int roomno=pDialog->getChosenroom();
       Hotel * hotel=Hotel::getinstance();
       Room * room= hotel->findroom(roomno);
       int total=(days*room->getgünlükücret())+room->getExtra();
       ui->lineEditUcret->setText(QString::number(total));
   }
   else{

   }
}


void Dialogcheckout::on_pushButton_Checkout_clicked()
{
    bool ok;
    int days=ui->lineEdit_Gun->text().toInt(&ok);
    if(ok){
        setTotaldays(days);
        accept();
    }
    else{
        //kullanıcı Okey tıkladı ama gün sayısı boş.
        reject();
    }
}


void Dialogcheckout::on_pushButton_Cancel_clicked()
{
    reject();
}

