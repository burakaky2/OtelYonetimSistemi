#ifndef DIALOGCHECKOUT_H
#define DIALOGCHECKOUT_H
#include"dialogrooms.h"
#include <QDialog>

namespace Ui {
class Dialogcheckout;
}

class Dialogcheckout : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcheckout(QWidget *parent = nullptr);
    ~Dialogcheckout();

    int getTotaldays() const;
    void setTotaldays(int newTotaldays);

private slots:
    void on_pushButtonHesapla_clicked();

    void on_pushButton_Checkout_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::Dialogcheckout *ui;
    int totaldays;
    DialogRooms * pDialog;

};

#endif // DIALOGCHECKOUT_H
