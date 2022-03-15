#include "Manager_Normal_user.h"

//Manager::Manager(QString _firstname, QString _lastname, Date _birthday, bool _active, QString _username, QString _password, bool _online, Image _profile,QVector<Building *> _buildings,  QVector<File* > _files) :User(_firstname,_lastname,_birthday,_active,_username,_password,_online,_profile){
//	buildings = _buildings;
//	files = _files;
//}

QVector<Building *> Manager::Buildings() {
    return buildings;
}
QVector<File* > Manager::Files() {
    return files;
}





/////////////////////////////Normal_user
//Normal_user::Normal_user(QString _firstname, QString _lastname, Date _birthday, bool _active, QString _username, QString _password, bool _online, Image _profile, QVector<File *> _files) :User(_firstname, _lastname, _birthday, _active, _username, _password, _online, _profile) {
//	files = _files;
//}
Normal_user::~Normal_user()
{

}

QVector<File *>* Normal_user::Files() {
    return files;
}


QString Normal_user::get_username()
{
    return username;
}
