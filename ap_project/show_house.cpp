#include "show_house.h"
#include "ui_show_house.h"

show_house::show_house(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_house)
{
    ui->setupUi(this);
    next=ui->next_pb;
    pre=ui->previous_pb;
    floor=ui->floor_number_le;
    Builde=ui->built_area_le;
    room=ui->rooms_le;
    combo=ui->comboBox;
    ui->comboBox->addItem("commersial");
    ui->comboBox->addItem("EDARI");
    ui->comboBox->addItem("normal");
    label=ui->label_3;

}

show_house::~show_house()
{
    delete ui;
}

void show_house::on_next_pb_clicked()
{
    i++;
    floor->setText(QString::number((*list)[i]->Floor_number()));
    room->setText(QString::number((*list)[i]->Rooms()));
    Builde->setText(QString::number((*list)[i]->Built_area()));

    combo->setCurrentIndex((*list)[i]->House_condition());

    QPixmap* s=new QPixmap((*list)[i]->Image()->Image_address());

    label->setPixmap(*s);
    pre->setDisabled(false);
    if(i==list->size()){
        next->setDisabled(true);
    }

}

void show_house::on_previous_pb_clicked()
{
    i--;
    floor->setText(QString::number((*list)[i]->Floor_number()));
    room->setText(QString::number((*list)[i]->Rooms()));
    Builde->setText(QString::number((*list)[i]->Built_area()));

    combo->setCurrentIndex((*list)[i]->House_condition());

    QPixmap* s=new QPixmap((*list)[i]->Image()->Image_address());
    label->setPixmap(*s);
    next->setDisabled(false);
    if(i==0){
        pre->setDisabled(true);
    }


}

void show_house::on_edit_pb_clicked()
{
    QVector<House*>::iterator h=&(*list)[i];
  list->erase(h);
    House * n=new House(floor->text().toInt(),floor->text().toInt(),room->text().toInt(),Builde->text().toFloat(),(*list)[i]->Image(),combo->currentIndex());
}
