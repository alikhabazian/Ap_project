#ifndef BUILDING_H
#define BUILDING_H


#include "image.h"
#include <QVector>
//using namespace std;
class Building
{
protected:
    float base_price;
    float hole_area;
    QString address;
    float price;
    Image* picture;
public:
    Building();
    virtual ~ Building();
    Building(float _base_price, float _hole_area, QString add, Image* _image_address);
//    virtual void calculate_value();
    float Price();
    float Base_price();
    float Hole_area();
    QString Address();
    Image* Picture();
};

class Villa :public Building {
protected:
    float built_area;
    int rooms;//number of rooms
public:
    Villa(float _base_price, float _hole_area, QString add, Image* _image_address,float _built_area,int _rooms):Building(_base_price, _hole_area, add,_image_address){
        built_area=_built_area;
        rooms=_rooms;
    }
    float Built_area();
    int Rooms();
};

class Northern_villa :public Villa {
protected:
    float front_yard_area;
    float back_yard_area;
public:
    Northern_villa(float _base_price, float _hole_area, QString add, Image* _image_address,float _built_area,int _rooms,float _front_yard_area,float _back_yard_area):Villa(_base_price,_hole_area, add,_image_address,_built_area,_rooms){
        front_yard_area=_front_yard_area;
        back_yard_area=_back_yard_area;
        count_price();
    }
    void count_price();
    float Front_yard_area();
    float Back_yard_area();
};

class Southern_villa :public Villa {
protected:
    float yard_area;
    float parking_area;
public:
    Southern_villa(float _base_price, float _hole_area, QString add, Image* _image_address,float _built_area,int _rooms,float _yard_area,float _parking_area):Villa(_base_price,_hole_area, add,_image_address,_built_area,_rooms){
        yard_area=_yard_area;
        parking_area=_parking_area;
        set_price();
    }
    void set_price();
    float Yard_area();
    float Parking_area();
};
class House {
protected:
    int floor_number;
    int houseID;
    int rooms;
    int house_ccondition;
    float price;
    float built_area;
    Image *image;
public:
    House(){}
    House(int floor_number, int _houseID, int _rooms, float _built_area, Image* _image,int _house_condition);
    void set_price(float _price);
    int HouseID();
    int Rooms();
    float Price();
    int Floor_number();
    float Built_area();
    int House_condition();
    Image* Image();
};
class Apartment :public Building {
protected:
    bool elevator;
    int floors;
    QVector<House*> houses;
public:
    Apartment(float _base_price, float _hole_area, QString add, Image* _image_address,bool ele, int _floors,QVector<House*> hous);
    float count_price();
    void count_house();
    bool Elevator();
    int Floors();
    QVector<House*>& Houses();

};


#endif // BUILDING_H
