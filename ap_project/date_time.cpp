#include "date_time.h"

Date::Date(int mn, int dy, int yr)
{
    month = mn;
    day = dy;
    year = yr;
}
void Date::set_year(int yr) {
    year = yr;
}
void Date::set_month(int mn) {
    month = mn;
}
void Date::set_day(int dy) {
    day = dy;
}
void Date::set_date(int yr, int mn, int dy) {
    year = yr;
    month = mn;
    day = dy;
}
int Date::Day() {
    return day;
}
int Date::Month() {
    return month;
}
int Date::Year() {
    return year;
}


////////////////class Time:
Time::Time(int _hour, int _min, int _sec) {
    hour = _hour;
    min = _min;
    sec = _sec;
}
void Time::set_hour(int h) {
    hour = h;
}
void Time::set_min(int mn) {
    min = mn;
}
void Time::set_sec(int sc) {
    sec = sc;
}
void Time::set_time(int h, int mn, int sc) {
    hour = h;
    min = mn;
    sec = sc;
}
Date_Time::Date_Time(int yr, int mn, int dy, int h, int m, int s) :Date(mn,dy,yr),Time(h,m,s){}
int Time::Hour() {
    return hour;
}
int Time::Min() {
    return min;
}
int Time::Sec() {
    return sec;
}
