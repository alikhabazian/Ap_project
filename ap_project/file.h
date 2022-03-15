#ifndef FILE_H
#define FILE_H


#include "Date_Time.h"
#include <iostream>
#include "Building.h"

class File
{
protected:
    Building * my_building;
//    B_kind building_kind;
    float commission;
    float final_cost;
public:
    File( Building * _my_building);
    Building* Building_s(){
        return my_building;
    }
     float Final_cost();
     virtual void fuck(){}
//    B_kind Building_kind();
   ~File();

};
class Rent:public File {
protected:
    float mortgage_cost;
    float rent_cost;
    Date* period;
public:
    Rent(Building * _my_building, Date* _period);
    void fuck(){}
    float Mortgage_cost();
    float Rent_cost();
    float Final_cost();
};
class Sale:public File {
protected:
    QString detail;
public:
    Sale( Building * _my_building, QString _detail);
    void fuck(){}
    QString Detail();
    float Final_cost();
};



#endif // FILE_H
