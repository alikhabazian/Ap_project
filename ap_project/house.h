#ifndef HOUSE_H
#define HOUSE_H

#include <QDialog>
#include<building.h>

namespace Ui {
class house;
}

class house : public QDialog
{
    QVector<House*>* tyu;
    QString tmp;
    Q_OBJECT

public:
    explicit house(QWidget *parent = nullptr);
    ~house();
   public slots:
    void get_house(QVector<House*>& tmp){

        tyu=&tmp;
    }

private slots:
    void on_add_pb_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::house *ui;
};

#endif // HOUSE_H
