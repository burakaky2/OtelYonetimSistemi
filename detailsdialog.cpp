#include "detailsdialog.h"
#include "ui_detailsdialog.h"
#include"dialogrooms.h"

DetailsDialog::DetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DetailsDialog)
{
    ui->setupUi(this);
    DialogRooms * parentdialog=dynamic_cast<DialogRooms*>(parent);
    pDialog=parentdialog;
    int roomno=parentdialog->getChosenroom();
    QString str=QString::number(roomno);
    ui->label->setText(str);
}


DetailsDialog::~DetailsDialog()
{
    delete ui;
}


void DetailsDialog::on_pushButton_okey_clicked()
{
    QString name=ui->LineEdit->text();
    if(!name.isEmpty()){
        pDialog->setNamecustomer(name);
        accept();
    }
    else{
         //kullanıcı Okey tıkladı ama customer name boş olduğu için işlem yapılmaz.
        reject();
    }


}


void DetailsDialog::on_pushButton_cancel_clicked()
{
    reject();
}

