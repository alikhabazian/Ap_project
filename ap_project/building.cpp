#include "building.h"
#include "image.h"
Building::Building(){}
Building::Building(float _base_price, float _hole_area, QString add, Image* _image_address) {
    base_price = _base_price;
    hole_area = _hole_area;
    address = add;
    picture=_image_address;

}


float Building::Price() {
    return price;
}

float Building::Base_price()
{
    return base_price;
}

float Building::Hole_area()
{
    return hole_area;
}

QString Building::Address()
{
    return address;
}

Image *Building::Picture()
{
    return picture;
}
Building::~ Building(){};

//////////////////house
House::House(int _floor_number, int _houseID, int _rooms, float _built_area, class::Image* _image,int _house_condition) {
    floor_number = _floor_number;
    houseID = _houseID;
    rooms = _rooms;
    built_area = _built_area;
    image = _image;
    house_ccondition=_house_condition;
}

void House::set_price(float _price)
{
    price=_price;
}



int House::HouseID()
{
    return houseID;
}

int House::Rooms()
{
    return rooms;
}

float House::Price()
{
    return price;
}

int House::Floor_number()
{
    return floor_number;
}

float House::Built_area()
{
    return built_area;
}

int House::House_condition()
{
    return house_ccondition;
}

Image* House::Image()
{
    return image;
}
/////////////////apartment
Apartment::Apartment(float _base_price, float _hole_area, QString add, Image* _image_address, bool ele, int _floors,QVector<House*>hous) :Building(_base_price,_hole_area,add, _image_address){
    elevator = ele;
    floors = _floors;
    houses=hous;
    count_price();
    count_house();

}

float Apartment::count_price()
{
    price=base_price*hole_area*0.8;
    return (base_price*hole_area*0.8);

}

void Apartment::count_house()
{
    for(int i=0;i<houses.size();i++){
        houses[i]->set_price(base_price * houses[i]->Built_area());
        houses[i]->set_price(houses[i]->Floor_number()*0.05*houses[i]->Price()+houses[i]->Price());
        if(houses[i]->Rooms()>1){
           houses[i]->set_price(houses[i]->Price()+ (houses[i]->Rooms()-1)*0.08*houses[i]->Price());
        }
        if(Elevator()){
            houses[i]->set_price(houses[i]->Price() + houses[i]->Price()*0.02);
        }
    }
}

bool Apartment::Elevator()
{
    return elevator;
}

int Apartment::Floors()
{
    return floors;
}

QVector<House*>& Apartment::Houses()
{

    return houses;
}

float Villa::Built_area()
{
    return built_area;
}

int Villa::Rooms()
{
    return rooms;
}

void Northern_villa::count_price()
{
    price = base_price * built_area + base_price * front_yard_area * 0.30 + base_price * back_yard_area * 0.15;
}

float Northern_villa::Front_yard_area()
{
    return front_yard_area;
}

float Northern_villa::Back_yard_area()
{
    return back_yard_area;
}

void Southern_villa::set_price()
{
    price= base_price * built_area + base_price *yard_area * 0.30 + base_price * parking_area * 0.15;
}

float Southern_villa::Yard_area()
{
    return yard_area;
}

float Southern_villa::Parking_area()
{
    return parking_area;
}
