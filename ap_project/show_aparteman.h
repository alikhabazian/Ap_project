#ifndef SHOW_APARTEMAN_H
#define SHOW_APARTEMAN_H

#include <QDialog>
#include"building.h"
#include <QVector>
#include <QDebug>
#include<QGroupBox>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>
#include<QGroupBox>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDebug>
#include<QTime>
#include<QPixmap>
#include<QFont>
#include<QCheckBox>
#include"show_house.h"
namespace Ui {
class show_aparteman;
}

class show_aparteman : public QDialog
{
    Q_OBJECT
    Building*list_build;
    QVector<House*>* list_house;

    QGroupBox* n_villa_gp;
    QLineEdit* base_price_le;
    QLineEdit* hole_area_le;
    QLineEdit* address_le;
    QLineEdit* built_area_notrh;
    QLineEdit* rooms_north;
    QGroupBox* apartment_gp;
    QGroupBox* s_villa_gp;

    QLineEdit* front_area_north;
    QLineEdit* back_area_north;
    QGroupBox* n_villa_gp_;
    QGroupBox* s_villa_gp_;
    QLineEdit* floors_ap;
    QCheckBox* have_elevator;




    QLabel* image;




public:
    explicit show_aparteman(QWidget *parent = nullptr);
    ~show_aparteman();
public slots:
    void get_list(Building* tmp){
        qDebug()<<"dads";
        list_build=tmp;
        qDebug()<<"dads1";
        base_price_le->setText(QString::number( list_build->Base_price()));
        qDebug()<<"dads12";
        hole_area_le ->setText(QString::number( list_build->Hole_area()));
        qDebug()<<"dads13";
        address_le->setText(list_build->Address());
        qDebug()<<"dads14";
        image->setPixmap(list_build->Picture()->Image_address());
        qDebug()<<"4";

        Northern_villa *g=dynamic_cast<Northern_villa *>( list_build);
        if(g){
            n_villa_gp->setEnabled(true);
            s_villa_gp->setEnabled(false);
            apartment_gp->setEnabled(false);
            built_area_notrh->setText(QString::number(g->Built_area()));
            rooms_north->setText(QString::number(g->Rooms()));
            front_area_north->setText(QString::number(g->Front_yard_area()));
            back_area_north->setText(QString::number(g->Back_yard_area()));


        }
        else{
        class Apartment* ggg;
        ggg=dynamic_cast<class Apartment* >( list_build);
        Southern_villa* gg=dynamic_cast<Southern_villa* >(list_build);
        if(gg){
            n_villa_gp->setEnabled(false);
            s_villa_gp->setEnabled(true);
            apartment_gp->setEnabled(false);
            built_area_notrh->setText(QString::number(gg->Built_area()));
            rooms_north->setText(QString::number(gg->Rooms()));
            front_area_north->setText(QString::number(gg->Yard_area()));
            back_area_north->setText(QString::number(gg->Parking_area()));
        }
        else{

            n_villa_gp->setEnabled(false);
            s_villa_gp->setEnabled(false);
            apartment_gp->setEnabled(true);
            floors_ap->setText(QString::number(ggg->Floors()));
            have_elevator->setTristate(ggg->Elevator());
            qDebug()<<"salam";
            list_house= &(ggg->Houses());


        }
        }
    }

private slots:
    void on_add_house_pb_3_clicked();
signals:
    void send(QVector<House*>*);

private:
    Ui::show_aparteman *ui;
};

#endif // SHOW_APARTEMAN_H
