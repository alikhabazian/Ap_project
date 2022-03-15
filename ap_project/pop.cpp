#include "pop.h"
#include "ui_pop.h"

pop::pop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pop)
{
    ui->setupUi(this);
    what=ui->label;
}

pop::~pop()
{
    delete ui;
}
