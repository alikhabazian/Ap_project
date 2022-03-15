#ifndef DATE_TIME_H
#define DATE_TIME_H


class Date {
protected:
    int year;
    int month;
    int day;
public:
    Date(int = 1, int = 1, int = 1900);
    void set_year(int yr);
    void set_month(int mn);
    void set_day(int dy);
    void set_date(int yr, int mn,int dy);
    int Day();
    int Month();
    int Year();
};
class Time {
protected:
    int hour;
    int min;
    int sec;
public:
    Time(int _hour, int _min, int _sec);
    void set_hour(int h);
    void set_min(int mn);
    void set_sec(int sc);
    void set_time(int h, int mn, int sc);
    int Hour();
    int Min();
    int Sec();
};
class Date_Time:public Date, public Time
{
public:
    Date_Time(int yr,int mn, int dy,int h,int m,int s);
    ~Date_Time(){}
};

#endif // DATE_TIME_H
