#ifndef DIALOGROOMS_H
#define DIALOGROOMS_H

#include <QDialog>

namespace Ui {
class DialogRooms;
}

class DialogRooms : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRooms(QWidget *parent = nullptr);
    ~DialogRooms();

    int getChosenroom() const;
    void setChosenroom(int newChosenroom);

    QString getNamecustomer() const;
    void setNamecustomer(const QString &newNamecustomer);

    bool getIsCheckinPressed() const;
    void setIsCheckinPressed(bool newIsCheckinPressed);

private slots:
    void on_pushButton_okey_clicked();
    void on_pushButton_cancel_clicked();
    void colorRoomButtons(int roomno,QPushButton* button);
    void on_pushbutton101_clicked();

    void on_pushbutton102_clicked();

    void on_pushbutton103_clicked();

    void on_pushbutton201_clicked();

    void on_pushbutton202_clicked();
    void processButtonsClicks(int roomno,QPushButton* button);


private:
    Ui::DialogRooms *ui;
    int chosenroom;
    QString namecustomer;
    bool isCheckinPressed;
};

#endif // DIALOGROOMS_H
