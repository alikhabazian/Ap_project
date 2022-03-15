#include "File.h"

File::File( Building * _my_building) {

    my_building = _my_building;
}
float File::Final_cost() {
    return final_cost;
}
//B_kind File::Building_kind() {
//    return building_kind;
//}
File::~File(){};
///////////////Rent:
Rent::Rent( Building* _my_building, Date* _period) :File( _my_building) {
    period = _period;
    Mortgage_cost();
    Rent_cost();
}

float Rent::Mortgage_cost() {
    mortgage_cost =(my_building-> Price())*((float)0.05);
    return mortgage_cost;
}

float Rent::Rent_cost() {
    rent_cost = my_building->Price()*((float)0.01);
    return rent_cost;
}

float Rent::Final_cost()
{
    final_cost = Rent_cost() * period->Year() + Mortgage_cost() + commission * Mortgage_cost();
    return final_cost;
}
///////////////
Sale::Sale( Building * _my_building, QString _detail) :File(_my_building) {
    detail = _detail;
}
QString Sale::Detail() {
    return detail;
}

float Sale::Final_cost()
{
    final_cost = my_building->Price() + commission * my_building->Price();
    return final_cost;
}
