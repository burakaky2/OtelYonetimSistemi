#ifndef DIALOGEXTRA_H
#define DIALOGEXTRA_H

#include <QDialog>
#include <QMap>
#include "hotel.h"

namespace Ui {
class DialogExtra;
}

class DialogExtra : public QDialog {
    Q_OBJECT

public:
    explicit DialogExtra(QWidget *parent = nullptr);
    ~DialogExtra();

private:
    Ui::DialogExtra *ui;
    QMap<QString, double> yemekFiyatlari;
    double totalPrice = 0.0;
    QString roomNumber;

private slots:
    void onExtraButtonClicked();
    void onPushButtonHesaplaClicked();
    void on_pushButton_clicked();
};

#endif // DIALOGEXTRA_H
