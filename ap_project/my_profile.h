#ifndef MY_PROFILE_H
#define MY_PROFILE_H

#include <QDialog>
#include<QTime>
#include<QDebug>
#include<QLabel>
#include<QDate>
#include<QLineEdit>
#include<QDateEdit>

#include<QMovie>

#include"user.h"
#include"manager_normal_user.h"

namespace Ui {
class my_profile;
}

class my_profile : public QDialog
{
    Q_OBJECT
    QLabel* d;
    User* this_User;
    QLineEdit* user;
    QLineEdit* pass;
    QLineEdit*  first;
    QLineEdit* last;
    QLabel* profile;
    QDateEdit* date;
    QLabel* gif;

    QString filename;

    QString picture;

    QVector<Building*>* list_bulding;
    QVector<House*> list_house;
    QVector<File*>* list_file;

    int which=0;
    QVector<Building*>* array[4];
    QVector<class Apartment*>* array1[3];


public:
    explicit my_profile(QWidget *parent = nullptr);
    ~my_profile();


private:
    Ui::my_profile *ui;
public slots:
    void tie(){




         d ->setText(QTime::currentTime().toString(" hh : mm : ss"));
//         qDebug()<<d;


    }
    void get_user(User* tmp){
        this_User=tmp;
        user->setText(tmp->Username())   ;
        pass->setText(tmp->Password())   ;
        first->setText(tmp->Firstname())   ;
        last->setText(tmp->Lastname())   ;
        QPixmap a(tmp->Profile()->Image_address());
        profile->setPixmap(a);
        QDate s(tmp->Birthday()->Year(),tmp->Birthday()->Month(),tmp->Birthday()->Day());
        date->setDate(s);

        QMovie* ss;
        Manager* poli=dynamic_cast<Manager*>(tmp);
        if(!poli){
            ss=new QMovie("C:/Users/Ali/Desktop/giphy.gif");
        }
        else{
            ss=new QMovie("C:/Users/Ali/Desktop/tenor.gif");
        }
        gif->setMovie(ss);
        gif->setScaledContents(true);
        ss->start();







    }
    void fill2(){

    }

    signals:
    void fill();
    void set_pop(QString);
    void send_house(QVector<House*>&);
    void send_list(Building*);
    void send_b(Building*);
    void send_list_file(QVector<File*>*);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_building_mode_currentIndexChanged(int index);
    void on_add_picture_clicked();
    void on_Insert_clicked();
    void get_list(QVector<Building*>& tmp){
        list_bulding=&tmp;
    }
    void on_tabWidget_currentChanged(int index);
    void on_add_house_pb_clicked();
    void on_pushButton_clicked();

    void on_search_baseprice_holearea_clicked();
    void on_search_street_clicked();
    void on_search_sort_clicked();
    void on_search_all_clicked();
    void on_search_N_house_clicked();
    void on_search_hole_area_clicked();
    void on_search_rooms_clicked();
    void on_rent_clicked();
    void on_sale_clicked();
};

#endif // MY_PROFILE_H
