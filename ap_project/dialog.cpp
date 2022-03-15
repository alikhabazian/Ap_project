#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
//    list_user.resize(10);
    center=new QHBoxLayout();
    tu=new QVBoxLayout();
    namekarbari=new QLabel("Username:");
    namekarbari->setStyleSheet("color : blue");

    QFont b;
    b.setPointSize(25);
    b.setBold(true);
    namekarbari->setFont(b);
    password=new QLabel("Password:");
    password->setStyleSheet("color : blue");
    password->setFont(b);


//    QDateTime tt;
//    QTimeZone s();
//    tt.setTimeZone()
//    tt.currentDateTime();
//    QString ttt=tt.toString();
//    qDebug()<<ttt;

    f=new QTimer(this);
    connect(f,SIGNAL(timeout()),this,SLOT(tie()));
    f->start(1000);
    time=new QLabel(QTime::currentTime().toString(" hh : mm : ss"));
    ok=new QPushButton("ok");
    ok->setDefault(true);
    QIcon icon("C:/Users/Ali/Desktop/facebook-like-icon_1017-8081.jpg");
    ok->setIcon(icon);
    QFont cr;
    cr.setBold(true);
    time->setFont(cr);


    image=new QLabel();

    QPixmap a("C:/Users/Ali/Desktop/photo-1486406146926-c627a92ad1ab.jfif");
//    a=a.scaledToWidth(image->width());
    image->setPixmap(a);
    image->setFixedSize(500,400);
    image->setScaledContents(true);



    cancel=new QPushButton("cancel");

    QIcon icon1("C:/Users/Ali/Desktop/download.jfif");

    cancel->setIcon(icon1);

    reg1=new QPushButton("register");
    QIcon icon2("C:/Users/Ali/Desktop/1-38-512.png");
    reg1->setIcon(icon2);
    btn=new QHBoxLayout();

    Us=new QLineEdit();
    Us->setStyleSheet("background:#66ffff;color : red");
    pa=new QLineEdit();
    pa->setStyleSheet("background:#66ffff ;color : red");
    pa->setEchoMode(QLineEdit::Password);
setFixedSize(1000,400);

    center->addWidget(image);
    center->addLayout(tu);
    QFont j;
    j.setPixelSize(75);
    time->setFont(j);
//    time->setFixedWidth();
//    tu->setAlignment(Qt::AlignCenter);
//    pa->setFixedHeight(100);

//    Us->setFixedHeight(100);
//    password->
    password->setAlignment(Qt::AlignCenter);
    namekarbari->setAlignment(Qt::AlignCenter);
    time->setAlignment(Qt::AlignCenter);
    reg1->setFixedSize(150,100);
    cancel->setFixedSize(150,100);
    ok->setFixedSize(150,100);
//setStyleSheet("background : gray");
    tu->addWidget(time);

    tu->addWidget(namekarbari);
    tu->addWidget(Us);
    tu->addWidget(password);
    tu->addWidget(pa);
    tu->addLayout(btn);
    btn->addWidget(reg1);
    btn->addWidget(cancel);
    btn->addWidget(ok);

    connect(cancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(reg1,SIGNAL(clicked()),this,SLOT(regi()));
    connect(ok,SIGNAL(clicked()),this,SLOT(okay()));



//    namekarbari->setStyleSheet("QLabel {background :red;  color : blue; }");

//    namekarbari->setFont(b);
//    QPixmap a("C:/Users/Ali/Desktop/images.jpg");
//    namekarbari->setPixmap();
//     password;
//     image;
//     time;


    setLayout(center);
//    center->addWidget(namekarbari);

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
