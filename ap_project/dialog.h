#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDialog>
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
#include<QDateTime>
#include<QIcon>
#include<QStyle>
#include<QTimeZone>
#include<QTimer>
#include<windows.h>

#include<reg.h>
#include<my_profile.h>

#include"user.h"
#include"building.h"
#include<QVector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    QLabel* namekarbari;
    QLabel* password;
    QLabel* image;
    QLabel* time;

    QHBoxLayout* hb2;

    QHBoxLayout* center;
    QHBoxLayout* btn;

    QPushButton* ok;
    QPushButton* reg1;
    QPushButton* cancel;

    QVBoxLayout* tu;

    QLineEdit* Us;
    QLineEdit* pa;

    QTimer* f;



    QVector<User*> list_user;
    QVector<Building*> list_Building;
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void tie(){

        time->setText(QTime::currentTime().toString(" hh : mm : ss"));

    }
    void regi(){
//        reg* register1=new reg();
        class::reg* register1=new class::reg;
        qDebug()<<"Hi1";
//        Date* f=new Date(1,1,1900);
//        Image* g=new Image("C:/Users/Ali/Desktop/download.jfif");
//        User* d=new User("ali","khabazian",f,true,"u","s",true,g);
//        list_user.push_back(d);
        connect(this,SIGNAL(send_reg(QVector<User*>&)),register1,SLOT(get_list(QVector<User*>&)));
//        connect(this,SIGNAL(send_dialog(QDialog*)),register1,SLOT(get_dialog(QDialog*)));

        emit send_reg(list_user);
//        emit send_dialog(this);
        qDebug()<<this;
        register1->exec();

    }
    void okay(){
        qDebug()<<"haha";
        QVector<User*>::iterator d=list_user.begin();
        qDebug()<<"haha2";
        qDebug()<<list_user.size();
        qDebug()<<"haha3";
        while(d!=list_user.end()){
            qDebug()<<"while";
            if((*d)->get_username()==Us->text()&&(*d)->get_password()==pa->text()){
                qDebug()<<"if";
                class my_profile* o=new my_profile;
                connect(this,SIGNAL(send_user(User*)),o,SLOT(get_user(User*)));
                emit send_user(*d);
                connect(this,SIGNAL(send_building(QVector<Building*>&)),o,SLOT(get_list(QVector<Building*>&)));
                emit send_building(list_Building);





                o->exec();
                close();

            }
            d++;
        }

    }
    void get_back(QVector<User*> t){
        qDebug()<<"salam3";
        list_user=t;
    }
signals:
    void per();
    void send_reg(QVector<User*>&);
//    void send_dialog(QDialog*);
    void send_user(User*);
    void send_building(QVector<Building*>&);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
