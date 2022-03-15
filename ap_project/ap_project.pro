#-------------------------------------------------
#
# Project created by QtCreator 2019-07-05T21:50:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ap_project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        dialog.cpp \
    reg.cpp \
    pop.cpp \
    my_profile.cpp \
    user.cpp \
    image.cpp \
    date_time.cpp \
    manager_normal_user.cpp \
    file.cpp \
    building.cpp \
    house.cpp \
    show_aparteman.cpp \
    show_house.cpp \
    rent.cpp \
    sale1.cpp

HEADERS += \
        dialog.h \
    reg.h \
    pop.h \
    my_profile.h \
    user.h \
    image.h \
    date_time.h \
    manager_normal_user.h \
    file.h \
    building.h \
    house.h \
    show_aparteman.h \
    show_house.h \
    rent.h \
    sale1.h

FORMS += \
        dialog.ui \
    reg.ui \
    pop.ui \
    my_profile.ui \
    house.ui \
    show_aparteman.ui \
    show_house.ui \
    rent.ui \
    sale.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
