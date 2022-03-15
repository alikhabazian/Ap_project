#include "rent.h"
#include "ui_rent.h"
#include"date_time.h"
#include<file.h>
#include<QDebug>

rent::rent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rent)
{
    ui->setupUi(this);
}

rent::~rent()
{
    delete ui;
}

void rent::on_rent_pb_clicked()
{
    Date* g=new Date(ui->day_le->text().toInt(),ui->month_le->text().toInt(),ui->year_le->text().toInt());
    class Rent*v=new class::Rent(u,g);
    qDebug()<<"pa";
    (*list_file).push_back(v);
    close();

}
