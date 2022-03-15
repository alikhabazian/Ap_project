#ifndef POP_H
#define POP_H

#include <QDialog>
#include<QString>
#include<QLabel>

namespace Ui {
class pop;
}

class pop : public QDialog
{
    Q_OBJECT
    QLabel* what;


public:
    explicit pop(QWidget *parent = nullptr);
    ~pop();
public slots:
    void get_string(QString s){
        what->setText(s);
    }
private:
    Ui::pop *ui;
};

#endif // POP_H
