#include "dialogextra.h"
#include "ui_dialogextra.h"
#include <QDebug>
#include "hotel.h"
#include <QMessageBox>

DialogExtra::DialogExtra(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogExtra) {
    ui->setupUi(this);

    // Yemek fiyatlarını tanımlıyoruz
    yemekFiyatlari["pushButton_Hamburger"] = 25;
    yemekFiyatlari["pushButton_cay"] = 8;
    yemekFiyatlari["pushButton_cips"] = 15;
    yemekFiyatlari["pushButton_dondurma"] = 18;
    yemekFiyatlari["pushButton_fanta"] = 10;
    yemekFiyatlari["pushButton_gofret"] = 12;
    yemekFiyatlari["pushButton_kahve"] = 15;
    yemekFiyatlari["pushButton_kebab"] = 40;
    yemekFiyatlari["pushButton_kola"] = 10;
    yemekFiyatlari["pushButton_kraker"] = 8;
    yemekFiyatlari["pushButton_mant"] = 35;
    yemekFiyatlari["pushButton_pizza"] = 30;

    // Butonları dinamik olarak bağlama
    for (const auto& key : yemekFiyatlari.keys()) {
        QPushButton* button = findChild<QPushButton*>(key);
        if (button) {
            connect(button, &QPushButton::clicked, this, &DialogExtra::onExtraButtonClicked);
        }
    }

    // Hesapla butonuna tıklanınca işlemi tamamla
    connect(ui->pushButtonHesapla, &QPushButton::clicked, this, &DialogExtra::onPushButtonHesaplaClicked);
}

DialogExtra::~DialogExtra() {
    delete ui;
}

// Butona tıklanınca fiyat ekleme fonksiyonu
void DialogExtra::onExtraButtonClicked() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton) {
        QString buttonName = senderButton->objectName();
        if (yemekFiyatlari.contains(buttonName)) {
            totalPrice += yemekFiyatlari[buttonName];
            qDebug() << "Tıklanan: " << buttonName << " | Güncellenmiş Toplam: " << totalPrice;
        }
    }
}

// Kullanıcı oda numarasını girdikten sonra fiyatı ilgili odaya ekleme
void DialogExtra::onPushButtonHesaplaClicked() {
    QString roomNumberStr = ui->lineEdit->text();  // Kullanıcının girdiği oda numarasını al
    int roomNumber = roomNumberStr.toInt();  // Stringi int'e çevir

    if (roomNumberStr.isEmpty()) {
        qDebug() << "HATA: Oda numarası girilmedi!";
        return;
    }

    Hotel* hotelInstance = Hotel::getinstance();
    Room* room = hotelInstance->findroom(roomNumber);

    if (room != nullptr) {
        if(room->odadolumu()){
            room->add(totalPrice);
            qDebug() << "Oda " << roomNumber << " için ekstra fiyat eklendi: " << totalPrice;
            ui->label_fiyat->setText(QString::number(room->getExtra()));
        }
        else{
            QMessageBox::critical(nullptr,"Hata"," Girdiğiniz Oda Boş!");
            qDebug() << "HATA: Oda Boş!";
        }
    }
    else {
        qDebug() << " Girdiğiniz Oda bulunamadı!";
        QMessageBox::critical(nullptr,"Hata","Girdiğiniz Oda bulunamadı!");


    }
}

void DialogExtra::on_pushButton_clicked()
{
    accept();
}

