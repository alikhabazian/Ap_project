#include "user.h"

User::User()
{

}

//User::User(const User &obj)
//{
//    firstname=obj.firstname;
//    lastname=obj.lastname;
//    birthday=obj.birthday;
//    active=obj.active;
//    username=obj.username;
//    password=obj.password;
//    online=obj.online;
//    profile=obj.profile;
//}

User::User(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile) {
    firstname=_firstname;
    lastname=_lastname;
    birthday=_birthday;
    active=_active;
    username=_username;
    password=_password;
    online=_online;
    profile=_profile;
}
void User::edit_user(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile){
    firstname=_firstname;
    lastname=_lastname;
    birthday=_birthday;
    active=_active;
    username=_username;
    password=_password;
    online=_online;
    profile=_profile;
}
void User::set_username(QString s) {
    username = s;
}
void User::set_pass(QString p) {
    password = p;
}
void User::set_online(bool x) {
    online = x;
}

QString User::get_username()
{
    return username;
}

QString User::get_password()
{
    return password;

}
//void User::set_profile(Image p) {
//    profile.set_image_address(p.Image_address());
//}
QString User::Firstname() {
    return firstname;
}
QString User::Lastname() {
    return lastname;
}
Date* User::Birthday() {
    return birthday;
}
QString User::Username() {
    return username;
}
QString User::Password() {
    return password;
}
float User::Cash() {
    return cash;
}
QMap<Date_Time, bool> User::Enter_exit() {
    return enter_exit;
}
bool User::Online(){
    return online;
}
Image* User::Profile() {
    return profile;
}
