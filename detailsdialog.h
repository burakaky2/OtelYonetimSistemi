#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QDialog>
#include "dialogrooms.h"
namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsDialog(QWidget *parent = nullptr);
    ~DetailsDialog();

private slots:
    void on_pushButton_okey_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DetailsDialog *ui;
    DialogRooms * pDialog;
};

#endif // DETAILSDIALOG_H
