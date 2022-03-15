#include "show_aparteman.h"
#include "ui_show_aparteman.h"
#include "image.h"

show_aparteman::show_aparteman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_aparteman)
{
    ui->setupUi(this);
    n_villa_gp=ui->n_villa_gp_2;
    base_price_le=ui->base_price_le_3;
    hole_area_le=ui->hole_area_le_3;
    address_le=ui->address_le_3;
    apartment_gp=ui->apartment_gp_2;
    image=ui->image_35;
    s_villa_gp=ui->s_villa_gp_2;
    built_area_notrh=ui->built_area_notrh_3;
    rooms_north=ui->rooms_north_3;
    front_area_north=ui->front_area_north_3;
    back_area_north=ui->back_area_north_3;
    floors_ap = ui->floors_ap_3;
    have_elevator = ui->have_elevator_3;


//    ui->building_mode_3->setCurrentIndex()
//    ui->hole_area_le_3->setText(list_build->Hole_area());
}

show_aparteman::~show_aparteman()
{
    delete ui;
}

void show_aparteman::on_add_house_pb_3_clicked()
{
    show_house * h=new show_house;
    connect(this,SIGNAL(send(QVector<House*>*)),h,SLOT(get(QVector<House*>*)));
    emit send(list_house);

    h->exec();

}
