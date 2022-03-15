#ifndef MANAGER_NORMAL_USER_H
#define MANAGER_NORMAL_USER_H

#include"user.h"
#include"Building.h"
#include"File.h"
#include<QVector>


class Manager:public User
{
protected:
    QVector<Building *> buildings;
    float commission;
     QVector<File* > files;
public:
      ~Manager();
    Manager(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile,QVector<Building *> _buildings,  QVector<File* > _files) :User(_firstname,_lastname,_birthday,_active,_username,_password,_online,_profile){
        buildings = _buildings;
        files = _files;
    }
    QVector<Building *> Buildings();
     QVector<File* > Files();
};

class Normal_user :public User {
protected:
    QVector<File *>* files;
public:
    virtual ~Normal_user();
    Normal_user(QString _firstname, QString _lastname, Date* _birthday, bool _active, QString _username, QString _password, bool _online, Image* _profile, QVector<File *>& _files) :User(_firstname, _lastname, _birthday, _active, _username, _password, _online, _profile) {
        files = &_files;
    }
    QVector<File *>* Files();
    QString get_username();
};



#endif // MANAGER_NORMAL_USER_H
