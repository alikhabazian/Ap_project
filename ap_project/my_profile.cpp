#include "my_profile.h"
#include "ui_my_profile.h"
#include<QMovie>
//using namespace std;
//#include<QtMultimedia/QAudio>
//#include <QtMultimedia>

#include<QTimer>
#include<QLabel>
#include<QVector>
#include<building.h>
#include"pop.h"
#include"house.h"
#include"show_aparteman.h"
#include<windows.h>
#include<string>
#include<sale1.h>

#include<QFileDialog>
#include"rent.h"


QVector<Building *>* search_by_base_price_and_hole_area(QVector<Building *> buildings,float _price,float y){
    QVector<Building *>* temp=new QVector<Building *>;
    for(int i=0;i<buildings.size();i++){
        if(buildings[i]->Base_price()<=_price){
            if(buildings[i]->Hole_area()>=y){
                temp->push_back(buildings[i]);
            }
        }
    }
    return temp;
}

QVector<Building *>* search_by_street(QVector<Building *> buildings,QString to_search){
    QVector<Building *> *temp= new QVector<Building*>;
    for(int i=0;i<buildings.size();i++){
//        buildings[i]->Address().contains(to_search);
        int found = buildings[i]->Address().toStdString().find(to_search.toStdString());
        if (found!=std::string::npos){
            (*temp).push_back(buildings[i]);
        }
    }
    return temp;
}
QVector<Building *>* sort_by_price(QVector<Building *> buildings){
    QVector<Building *>* temp = new QVector<Building*>;
    float min,tmp=-1;
    for(int i=0;i<buildings.size();i++){
        min=10000000;
        for(int j=0;j<buildings.size();j++){
            if(buildings[j]->Price()<min && buildings[j]->Price()>tmp){
                min=buildings[j]->Price();
            }
        }
        tmp=min;
        for(int k=0;k<buildings.size();k++){
            if(buildings[k]->Price()==min){
                (*temp).push_back(buildings[k]);
            }
        }
    }
    return temp;
}
QVector<class Apartment*>* search_by_N(QVector<Building*> buildings,int N){
    class Apartment * temp;
    QVector<class Apartment*>* t=new QVector<class Apartment *>;
    for(int i=0;i<buildings.size();i++){
        temp=dynamic_cast<class Apartment*>(buildings[i]);
        if(temp){
            if(temp->Houses().size()>N){
                (*t).push_back(temp);
            }
        }
    }
    return t;

}
QVector<class Apartment*>* search_by_least_hole_area(QVector<Building*> buildings,float y){
    class Apartment * temp;
    QVector<class Apartment*>* t=new QVector<class Apartment *>;
    for(int i=0;i<buildings.size();i++){
        temp=dynamic_cast<class Apartment*>(buildings[i]);
        if(temp){
            for(int j=0;j<temp->Houses().size();j++){
                if(temp->Houses()[j]->Built_area()>=y){
                    (*t).push_back(temp);
                    break;
                }
            }
        }
    }
    return t;
}

QVector<class Apartment*>* search_by_least_room(QVector<Building*> buildings,int r){
    class Apartment * temp;
    QVector<class Apartment*>* t=new QVector<class Apartment *>;
    for(int i=0;i<buildings.size();i++){
        temp=dynamic_cast<class Apartment*>(buildings[i]);
        if(temp){
            for(int j=0;j<temp->Houses().size();j++){
                if(temp->Houses()[j]->Rooms()>=r){
                    (*t).push_back(temp);
                    break;
                }
            }
        }
    }
    return t;
}


my_profile::my_profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_profile)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"Profile setting");
    ui->tabWidget->setTabText(1,"Inset building");
    ui->tabWidget->setTabText(2,"List building");
    ui->tabWidget->setTabText(3,"List File");
    ui->tabWidget->setTabText(4,"Search");
    list_file=new QVector<File*>;

//    QMovie* ss=new QMovie("C:/Users/Ali/Desktop/tenor.gif");
//ui->move->setMovie(ss);
//ui->move->setScaledContents(true);
//ss->start();
    ui->TIME->setText(QTime::currentTime().toString(" hh : mm : ss"));
    QTimer* ff;
    ff=new QTimer(this);
    connect(ff,SIGNAL(timeout()),this,SLOT(tie()));
    ff->start(1000);
d=ui->TIME;
ui->DATE->setText(QDate::currentDate().toString("yyyy/ MM/ dd :"));

user=ui->lineEdit_user;
pass=ui->lineEdit_user_;
first=ui->lineEdit_first_name;
last=ui->lineEdit_first_name_2;
profile=ui->label_3;
profile->setScaledContents(true);
date=ui->dateEdit;
gif=ui->move;
ui->building_mode->addItem("Northern villa");
ui->building_mode->addItem("Sothern villa");
ui->building_mode->addItem("Apartment");


}

my_profile::~my_profile()
{
    delete ui;
}

void my_profile::on_pushButton_2_clicked()
{
    Date* t=new Date(date->date().day(),date->date().month(),date->date().year());
    Image* id=new Image(filename);
   this_User->edit_user(first->text(),last->text(),t,true,user->text(),pass->text(),true,id);
}

void my_profile::on_pushButton_4_clicked()
{

    filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png *.xpm *.jpg)"));
   QPixmap s(filename);

   ui->label_3->setPixmap(s);
    ui->label_3->setScaledContents(true);

   qDebug()<<filename;
}

void my_profile::on_building_mode_currentIndexChanged(int index)
{
    if(index==0){
        ui->n_villa_gp->setEnabled(true);
        ui->s_villa_gp->setEnabled(false);
        ui->apartment_gp->setEnabled(false);
    }
    if(index==1){
        ui->n_villa_gp->setEnabled(false);
        ui->s_villa_gp->setEnabled(true);
        ui->apartment_gp->setEnabled(false);
    }
    if(index==2){
        ui->n_villa_gp->setEnabled(false);
        ui->s_villa_gp->setEnabled(false);
        ui->apartment_gp->setEnabled(true);
    }
}

void my_profile::on_add_picture_clicked()
{
    picture = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png *.xpm *.jpg)"));





}

void my_profile::on_Insert_clicked()
{
    if(ui->base_price_le->text()!="" && ui->hole_area_le->text()!="" && ui->address_le->text()!=""){
    if((ui->built_area_notrh->text()!="" && ui->rooms_north->text()!="" && ui->front_area_north->text()!="" && ui->back_area_north->text()!=""&&ui->building_mode->currentIndex()==0)){
        Image* g=new Image(picture);
//        Northern_villa* sss=new Northern_villa(1,1,"1",g,1,1,1,1);
                Northern_villa* ss=new  Northern_villa(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),g,ui->built_area_notrh->text().toFloat(),ui->rooms_north->text().toInt(),ui->front_area_north->text().toFloat(),ui->back_area_north->text().toFloat());
                pop* w=new pop();
                connect(this,SIGNAL(set_pop(QString)),w,SLOT(get_string(QString)));
                emit set_pop("New Northern villa added");
                qDebug()<<list_bulding->size();
                qDebug()<<"d";
                list_bulding->push_back(ss);

                w->exec();
    }
    if(ui->built_area_south->text()!="" && ui->rooms_south->text()!="" && ui->yard_area_south->text()!="" && ui->parking_area_south->text()!=""&&ui->building_mode->currentIndex()==1){
        Image* gg=new Image(picture);
            Southern_villa* dd=new Southern_villa(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),gg,ui->built_area_south->text().toFloat(),ui->rooms_south->text().toInt(),ui->yard_area_south->text().toFloat(),ui->parking_area_south->text().toFloat());
            pop* ww=new pop();
            connect(this,SIGNAL(set_pop(QString)),ww,SLOT(get_string(QString)));
            emit set_pop("New Southern villa added");
            qDebug()<<list_bulding->size();
            qDebug()<<"d";
            list_bulding->push_back(dd);

            ww->exec();
    }
    if(ui->floors_ap->text()!="")
    {
          Image* ggg=new Image(picture);
            qDebug()<<"floot";
          class::Apartment* re=new class::Apartment(ui->base_price_le->text().toFloat(),ui->hole_area_le->text().toFloat(),ui->address_le->text(),ggg,ui->have_elevator->isTristate(),ui->floors_ap->text().toInt(),list_house);
            qDebug()<<"floot";
          pop* ww=new pop();
          connect(this,SIGNAL(set_pop(QString)),ww,SLOT(get_string(QString)));
          emit set_pop("New Apartment added");
          qDebug()<<list_bulding->size();
          qDebug()<<"d";
          list_bulding->push_back(re);

          ww->exec();

    }
    }
}

void my_profile::on_tabWidget_currentChanged(int index)
{
    if(index==2){
        ui->list_buildig->clear();
        int i=0;
//        ui->list_buildig->append("Number    kind        Adress  Price");


        QVector<Building*>::iterator j=list_bulding->begin();
//        qDebug()<<(*j)->Address();
        while(j!=list_bulding->end()){
            i++;
            QString d=QString::number(i);
            d+="\t";
            {
                Northern_villa* to=dynamic_cast<Northern_villa*>(*j);
                if(to){
                    d+="Northen villa";
                }
                else{
                    Southern_villa* yo=dynamic_cast<Southern_villa*>(*j);
                    if(yo){
                        d+="Southern villa";
                    }
                    else{
                        d+="apartment";
                    }
                }
            }
            d+="\t\t";
            d+=(*j)->Address();
            d+="\t";
            d+=QString::number(static_cast<double>((*j)->Price()));
            ui->list_buildig->append(d);

            j++;
        }


    }
    if(index==3){
        qDebug()<<"sa";
        if(list_file->empty()){
            return;
        }

        QVector<File*>::iterator x=list_file->begin();
        int i=0;
        while(x!=list_file->end()){
            i++;
            QString d=QString::number(i);
            d+="\t";
            {
                class Rent * to=dynamic_cast<class Rent *>(*x);
                if(to){
                    d+="Rent";
                }
                else{
                    class Sale * yo=dynamic_cast<class Sale *>(*x);
                    if(yo){
                        d+="Southern villa";
                    }
                    else{
                        d+="apartment";
                    }
                }
            }
            d+="\t\t";
            d+=(*x)->Building_s()->Address();
            d+="\t";
            d+=QString::number(static_cast<double>((*x)->Building_s()->Price()));
            ui->te_file->append(d);


            x++;
        }
    }
}


void my_profile::on_add_house_pb_clicked()
{
    house * hh=new house;

    connect(this,SIGNAL(send_house(QVector<House*>&)),hh,SLOT(get_house(QVector<House*>&)));
    emit send_house(list_house);
//    Sleep(10000);
    hh->exec();

}

void my_profile::on_pushButton_clicked()
{
     qDebug()<<"123456";
     qDebug()<<list_bulding->size();
     qDebug()<<ui->spinBox->text().toInt();

    if(ui->spinBox->text().toInt()<=list_bulding->size()&&ui->spinBox->text().toInt()>0){
        qDebug()<<"10";
        show_aparteman * ju=new show_aparteman();
         qDebug()<<"1234567";
        connect(this,SIGNAL(send_list(Building*)),ju,SLOT(get_list(Building*)));
         qDebug()<<"12345678";
        QVector<Building*>::iterator jj=list_bulding->begin();
        qDebug()<<"12345";
        int i=1;
        while(ui->spinBox->value()!=i){
            qDebug()<<"1234";
            jj++;
            i++;
        }
        if(jj!=list_bulding->end()){
            qDebug()<<"gog";
        emit send_list((*jj));

        ju->exec();
        }


//        emit send_list(list_bulding);




    }
}

void my_profile::on_search_baseprice_holearea_clicked()
{
    ui->search_te->clear();
    QVector<Building*>* s=search_by_base_price_and_hole_area(*list_bulding,ui->price_lower_le->text().toFloat(),ui->hole_area_le->text().toFloat());
    array[0]=s;
    qDebug()<<(*s).size();
    QVector<Building*>::iterator l=(*s).begin();
    int y=0;
    while(l!=(*s).end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {
            Northern_villa* to=dynamic_cast<Northern_villa*>(*l);
            if(to){
                d+="Northen villa";
            }
            else{
                Southern_villa* yo=dynamic_cast<Southern_villa*>(*l);
                if(yo){
                    d+="Southern villa";
                }
                else{
                    d+="apartment";
                }
            }
        }
        d+="\t\t";
        d+=(*l)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*l)->Price()));
        ui->search_te->append(d);
        l++;
    }
    which=0;

}

void my_profile::on_search_street_clicked()
{
    ui->search_te->clear();
    QVector<Building*>* d=search_by_street(*list_bulding,ui->to_search_street_le->text());
    array[1]=d;
    QVector<Building*>::iterator l=(*d).begin();
    int y=0;
    while(l!=(*d).end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {
            Northern_villa* to=dynamic_cast<Northern_villa*>(*l);
            if(to){
                d+="Northen villa";
            }
            else{
                Southern_villa* yo=dynamic_cast<Southern_villa*>(*l);
                if(yo){
                    d+="Southern villa";
                }
                else{
                    d+="apartment";
                }
            }
        }
        d+="\t\t";
        d+=(*l)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*l)->Price()));
        ui->search_te->append(d);
        l++;
    }
    which=1;

}

void my_profile::on_search_sort_clicked()
{
    ui->search_te->clear();
    QVector<Building*>* p=sort_by_price(*list_bulding);
    array[2]=p;
    int y=0;
    QVector<Building*>::iterator gg=p->begin();
    while(gg!=p->end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {
            Northern_villa* to=dynamic_cast<Northern_villa*>(*gg);
            if(to){
                d+="Northen villa";
            }
            else{
                Southern_villa* yo=dynamic_cast<Southern_villa*>(*gg);
                if(yo){
                    d+="Southern villa";
                }
                else{
                    d+="apartment";
                }
            }
        }
        d+="\t\t";
        d+=(*gg)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*gg)->Price()));
        ui->search_te->append(d);

        gg++;
    }
    which=2;


}

void my_profile::on_search_all_clicked()
{
    array[3]=list_bulding;
    int y=0;
    QVector<Building*>::iterator gg=list_bulding->begin();
    while(gg!=list_bulding->end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {
            Northern_villa* to=dynamic_cast<Northern_villa*>(*gg);
            if(to){
                d+="Northen villa";
            }
            else{
                Southern_villa* yo=dynamic_cast<Southern_villa*>(*gg);
                if(yo){
                    d+="Southern villa";
                }
                else{
                    d+="apartment";
                }
            }
        }
        d+="\t\t";
        d+=(*gg)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*gg)->Price()));
        ui->search_te->append(d);

        gg++;
    }
    which=3;



}

void my_profile::on_search_N_house_clicked()
{
    ui->search_te->clear();
    QVector<class Apartment*>* r=search_by_N(*list_bulding,ui->N_house_le->text().toInt());
     array1[0]=r;
    QVector<class Apartment*>::iterator h=r->begin();
    int y=0;
    while(h!=r->end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {

                    d+="apartment";

        }
        d+="\t\t";
        d+=(*h)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*h)->Price()));
        ui->search_te->append(d);



        h++;
    }
    which=4;

}

void my_profile::on_search_hole_area_clicked()
{
    ui->search_te->clear();
    QVector<class Apartment*>* t=search_by_least_hole_area(*list_bulding,ui->least_hoe_area_le->text().toFloat());
    array1[1]=t;
    QVector<class Apartment*>::iterator h=t->begin();
    int y=0;
    while(h!=t->end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {

                    d+="apartment";

        }
        d+="\t\t";
        d+=(*h)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*h)->Price()));
        ui->search_te->append(d);



        h++;
    }
    which=5;


}

void my_profile::on_search_rooms_clicked()
{
    ui->search_te->clear();
    QVector<class Apartment*>* t=search_by_least_room(*list_bulding,ui->least_rooms_le->text().toInt());
     array1[2]=t;
    QVector<class Apartment*>::iterator h=t->begin();
    int y=0;
    while(h!=t->end()){
        y++;
        QString d=QString::number(y);
        d+="\t";
        {

                    d+="apartment";

        }
        d+="\t\t";
        d+=(*h)->Address();
        d+="\t";
        d+=QString::number(static_cast<double>((*h)->Price()));
        ui->search_te->append(d);



        h++;
    }
    which=6;
}

void my_profile::on_rent_clicked()
{
    Building* b;
    if(ui->search_spinBox->value()>0){


    if(which>3){
        int y=which-3;

        b=(*(array1[y]))[ui->spinBox->value()];
    }
    else{
        b=(*(array[which]))[ui->spinBox->value()];
    }
    rent* v=new rent;
    connect(this,SIGNAL(send_b(Building*)),v,SLOT(get_b(Building*)));
    emit send_b(b);
    connect(this,SIGNAL(send_list_file(QVector<File*>*)),v,SLOT(get_list_file(QVector<File*>*)));

    emit send_list_file(list_file);
    v->exec();
    }

}

void my_profile::on_sale_clicked()
{
    Building* b;
    if(ui->search_spinBox->value()>0){


    if(which>3){
        int y=which-3;

        b=(*(array1[y]))[ui->spinBox->value()];
    }
    else{
        b=(*(array[which]))[ui->spinBox->value()];
    }

    class sale* c=new class sale;
    connect(this,SIGNAL(send_b(Building*)),c,SLOT(get_b(Building*)));
    emit send_b(b);
    connect(this,SIGNAL(send_list_file(QVector<File*>*)),c,SLOT(get_list(QVector<File*>* )));
    emit send_list_file(list_file);



    c->exec();
    }
}
