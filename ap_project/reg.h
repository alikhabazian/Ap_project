#ifndef REG_H
#define REG_H

#include <QDialog>
#include<QFileDialog>

#include"user.h"
#include<QVector>
//#include<QComboBox>

namespace Ui {
class reg;
}

class reg : public QDialog
{
    Q_OBJECT
    QVector<User*>* list_in_reg;
    QString fileName;
//    QDialog* f;




public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_kind_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();
    void get_list(QVector<User*>& tmp){
        list_in_reg=&tmp;
    }
//    void get_dialog(QDialog* tmp){
//        f=tmp;
//    }
signals:
//    void send_back(QVector<User*>);

private:
    Ui::reg *ui;
};

#endif // REG_H
