#include "sale1.h"
#include "ui_sale.h"

sale::sale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sale)
{
    ui->setupUi(this);
}

sale::~sale()
{
    delete ui;
}

void sale::on_buy_pb_clicked()
{
    Sale* t=new Sale(b,ui->textEdit_di->toPlainText());
    (*v).push_back(t);
}
