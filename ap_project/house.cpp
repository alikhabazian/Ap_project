#include "house.h"
#include "ui_house.h"
#include<QFileDialog>
#include<QDebug>

house::house(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::house)
{
    ui->setupUi(this);
    ui->comboBox->addItem("commersial");
    ui->comboBox->addItem("EDARI");
    ui->comboBox->addItem("normal");

}

house::~house()
{
    delete ui;
}

void house::on_add_pb_clicked()
{
    if(ui->floor_number_le->text()!="" && ui->rooms_le->text()!="" && ui->built_area_le->text()!=""){
        Image * hq=new Image(tmp);
        House* u=new House(ui->floor_number_le->text().toInt(),ui->floor_number_le->text().toInt(),ui->rooms_le->text().toInt(),ui->built_area_le->text().toFloat(),hq,ui->comboBox->currentIndex());
        tyu->push_back(u);
        qDebug()<<"add";
        close();
    }
}

void house::on_pushButton_clicked()
{

    tmp= QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home",
                                                   tr("Images (*.png *.xpm *.jpg)"));


   }



void house::on_comboBox_currentIndexChanged(int index)
{

}
