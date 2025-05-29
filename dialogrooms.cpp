#include "dialogrooms.h"
#include "ui_dialogrooms.h"
#include "hotel.h"
#include "detailsdialog.h"
#include "dialogcheckout.h"
DialogRooms::DialogRooms(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRooms)
{
    ui->setupUi(this);
    //Butonların Rengini ayarlama
    colorRoomButtons(101,ui->pushbutton101);
    colorRoomButtons(102,ui->pushbutton102);
    colorRoomButtons(103,ui->pushbutton103);
    colorRoomButtons(201,ui->pushbutton201);
    colorRoomButtons(202,ui->pushbutton202);
}
void DialogRooms::colorRoomButtons(int roomno,QPushButton *button){
    Hotel * hotel=Hotel::getinstance();
    Room * room= hotel->findroom(roomno);
    if(room->odadolumu()){
        //Dolu ise kırmızıya boya
        button->setStyleSheet("QPushButton{background-color:red;color:white;font-weight:bold;border-radius:10 px;font-size:18 px}"
                                         "QPushButton::hover{background-color: darkred;} ");
    }
    else{
        //Boş ise yeşile boya
        button->setStyleSheet("QPushButton{background-color:green;color:white;font-weight:bold;border-radius:10 px;font-size:18 px}"
                                         "QPushButton::hover{background-color: #00414A;} ");
    }
}
void DialogRooms::processButtonsClicks(int roomno,QPushButton* button){
    setChosenroom(roomno);
    Hotel * hotel=Hotel::getinstance();
    Room * room= hotel->findroom(chosenroom);
    if(getIsCheckinPressed()){//check in ile gelirse
        if(!room->odadolumu()){
            DetailsDialog * detailsDialog=new DetailsDialog(this);
            auto ret=detailsDialog->exec();
            if(ret==QDialog::Accepted){
                qDebug()<<"Ok Tıklandı!";
                room->checkin(getNamecustomer().toStdString());
                colorRoomButtons(roomno,button); }
            else{
            qDebug()<<"Cancel Tıklandı!";
        }
            detailsDialog->deleteLater();
        }

    }

    else{ //kullanıcı checkout ile gelirse.
        if(room->odadolumu()){
            Dialogcheckout * dialogcheckout= new Dialogcheckout(this);
            auto ret=dialogcheckout->exec();
            if(ret==QDialog::Accepted){
                qDebug()<<"Check out Tıklandı!";
                room->checkout(dialogcheckout->getTotaldays());
                colorRoomButtons(roomno,button); }

        else{
            qDebug()<<"Cancel Tıklandı!";
        }
            dialogcheckout->deleteLater();
       }
    }
    }


bool DialogRooms::getIsCheckinPressed() const
{
    return isCheckinPressed;
}

void DialogRooms::setIsCheckinPressed(bool newIsCheckinPressed)
{
    isCheckinPressed = newIsCheckinPressed;
}

DialogRooms::~DialogRooms()
{
    delete ui;
}

void DialogRooms::on_pushButton_okey_clicked()
{
    accept();
}


void DialogRooms::on_pushButton_cancel_clicked()
{
    reject();
}




QString DialogRooms::getNamecustomer() const
{
    return namecustomer;
}

void DialogRooms::setNamecustomer(const QString &newNamecustomer)
{
    namecustomer = newNamecustomer;
}

int DialogRooms::getChosenroom() const
{
    return chosenroom;
}

void DialogRooms::setChosenroom(int newChosenroom)
{
    chosenroom = newChosenroom;
}
//Odaların slotları:

void DialogRooms::on_pushbutton101_clicked()
{
    processButtonsClicks(101,ui->pushbutton101);
}
void DialogRooms::on_pushbutton102_clicked()
{
    processButtonsClicks(102,ui->pushbutton102);
}


void DialogRooms::on_pushbutton103_clicked()
{
    processButtonsClicks(103,ui->pushbutton103);

}


void DialogRooms::on_pushbutton201_clicked()
{
    processButtonsClicks(201,ui->pushbutton201);

}


void DialogRooms::on_pushbutton202_clicked()
{
    processButtonsClicks(202,ui->pushbutton202);

}

