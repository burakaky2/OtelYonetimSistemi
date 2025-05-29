#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogrooms.h"
#include "dialogextra.h"
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

void MainWindow::on_Checkin_clicked() //slot
{
    DialogRooms * roomsdialog = new DialogRooms(this);
    roomsdialog->setIsCheckinPressed(true);
    auto ret = roomsdialog->exec(); //oluşturduğumuz dialog nesnesini açar.

    if(ret==QDialog::Accepted){
        qDebug()<<"Ok Tıklandı!";
    }
    else{
        qDebug()<<"Cancel Tıklandı!";
    }
    roomsdialog->deleteLater();
}


void MainWindow::on_Checkout_clicked()
{
    DialogRooms * roomsdialog = new DialogRooms(this);
    roomsdialog->setIsCheckinPressed(false);
    auto ret = roomsdialog->exec(); //oluşturduğumuz dialog nesnesini açar.

    if(ret==QDialog::Accepted){
        qDebug()<<"Ok Tıklandı!";
    }
    else{
        qDebug()<<"Cancel Tıklandı!";
    }
    roomsdialog->deleteLater();
}


void MainWindow::on_Extra_clicked()
{
    DialogExtra *extraDialog = new DialogExtra(this);
    auto ret=extraDialog->exec();  // Pencereyi aç, kullanıcı işlem yapabilsin
    if(ret==QDialog::Accepted){
        qDebug()<<"Ok Tıklandı!";
    }
    else{
        qDebug()<<"Cancel Tıklandı!";
    }
    extraDialog->deleteLater();   // İşlem tamamlanınca pencereyi temizle
}

