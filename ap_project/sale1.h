#ifndef SALE_H
#define SALE_H

#include <QDialog>
#include"building.h"
#include"file.h"

namespace Ui {
class sale;
}

class sale : public QDialog
{
    Building * b;
    QVector<File*>* v;
    Q_OBJECT

public:
    explicit sale(QWidget *parent = nullptr);
    ~sale();
public slots:
    void get_b(Building* tmp){
        b=tmp;
    }
    void get_list(QVector<File*>* t){
        v=t;
    }
private slots:
    void on_buy_pb_clicked();

private:
    Ui::sale *ui;
};

#endif // SALE_H
