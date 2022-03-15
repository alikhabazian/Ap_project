#ifndef RENT_H
#define RENT_H

#include <QDialog>
#include"building.h"

namespace Ui {
class rent;
}

class rent : public QDialog
{
    Q_OBJECT
    Building* u;
    QVector<class File*>* list_file;


public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();
public slots:
    void get_b(Building* tmp){
        u=tmp;
    }
    void get_list_file(QVector<class File*>* temp){
        list_file=temp;
    }
private slots:
    void on_rent_pb_clicked();

private:
    Ui::rent *ui;
};

#endif // RENT_H
