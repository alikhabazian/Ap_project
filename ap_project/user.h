#ifndef USER_H
#define USER_H


#include <iostream>
#include "Date_Time.h"
#include"Image.h"
#include <QMap>
//using namespace std;
class User
{
protected:
    QString firstname;
    QString lastname;
    Date* birthday;
    bool active;//true for faal false for ekhraj
    QString username;
    QString password;
    float cash=0;
    QMap<Date_Time,bool> enter_exit;//vorood & khorooj
    bool online;
    Image* profile;
public:
    User();
    User( const User &obj);
    User(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile);
    void edit_user(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile);
    void set_username(QString s);
    void set_pass(QString p);
    void set_online(bool x);
//    void set_profile(Image p);

    virtual QString get_username();
    QString get_password();
    QString Firstname();
    QString Lastname();
    Date* Birthday();
    QString Username();
    QString Password();
    float Cash();
    QMap<Date_Time, bool> Enter_exit();
    bool Online();
    Image* Profile();
};



#endif // USER_H
