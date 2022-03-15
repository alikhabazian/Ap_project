#ifndef SHOW_HOUSE_H
#define SHOW_HOUSE_H

#include <QDialog>
#include<QVector>
#include"building.h"
#include <QPushButton>
#include <QLineEdit>
#include<QLabel>
#include"QComboBox"
#include<QPixmap>
#include<QtDebug>
namespace Ui {
class show_house;
}

class show_house : public QDialog
{
    Q_OBJECT
    QVector<House*>* list;
    QPushButton* next;
    QPushButton* pre;
    QLineEdit* floor;
    QLineEdit* Builde;
    QLineEdit* room;
    QComboBox* combo;
    QLabel* label;

    int i=0;


public:
    explicit show_house(QWidget *parent = nullptr);
    ~show_house();
public slots:
    void get(QVector<House*>* tmp){
        qDebug()<<"11";
        qDebug()<<tmp->size();
        list=tmp;
        pre->setDisabled(true);
        if(list->size()<=1){
            qDebug()<<"22";
            next->setEnabled(false);
        }
        if(tmp){
            qDebug()<<"23";
        floor->setText(QString::number((*list)[0]->Floor_number()));
        room->setText(QString::number((*list)[0]->Rooms()));
        Builde->setText(QString::number((*list)[0]->Built_area()));

        combo->setCurrentIndex((*list)[0]->House_condition());

        QPixmap* s=new QPixmap((*list)[0]->Image()->Image_address());

        label->setPixmap(*s);
        }
    }
private slots:
    void on_next_pb_clicked();

    void on_previous_pb_clicked();

    void on_edit_pb_clicked();

private:
    Ui::show_house *ui;
};

#endif // SHOW_HOUSE_H
