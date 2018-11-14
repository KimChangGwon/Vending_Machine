#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QString>
#include <cstdio>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    money_(0)
{
    ui->setupUi(this);
    setControler();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setControler(){
    ui->lcdNumber->display(money_);
    ui->pbCoffe->setEnabled(money_>=100);
    ui->pbTea->setEnabled(money_>=150);
    ui->pbCola->setEnabled(money_>=200);
}

void Widget::on_PB500_2_clicked()
{
    money_ +=500;
    setControler();
}

void Widget::on_PB100_clicked()
{
    money_ +=100;
    setControler();
}

void Widget::on_PB50_clicked()
{
    money_ +=50;
    setControler();
}

void Widget::on_PB10_clicked()
{
    money_ +=10;
    setControler();
}

void Widget::on_pbCoffe_clicked()
{
    money_-=100;
    setControler();
}

void Widget::on_pbTea_clicked()
{
    money_-=150;
    setControler();
}

void Widget::on_pbCola_clicked()
{
    money_-=200;
    setControler();
}

void Widget::on_pbReset_clicked()
{
    if(money_ >0){
        int s00 = 0, l00 = 0, s0 = 0, l0 = 0;
        QString strings;
        char coins[4][100];

        s00 = money_ / 500;
        money_ -= s00 * 500;
        l00 = money_ / 100;
        money_ -= l00 * 100;
        s0 = money_ / 50;
        money_ -= s0 * 50;
        l0 = money_ / 10;
        money_ -= l0 * 10;

        sprintf(coins[0], "%d", s00);
        sprintf(coins[1], "%d", l00);
        sprintf(coins[2], "%d", s0);
        sprintf(coins[3], "%d", l0);

        strings.append("500won : ");
        strings.append(coins[0]);
        strings.append("\n100won : ");
        strings.append(coins[1]);
        strings.append("\n50won : ");
        strings.append(coins[2]);
        strings.append("\n10won : ");
        strings.append(coins[3]);
        strings.append("\n");


        setControler();
        QLabel * lb = new QLabel();

        lb->setText(strings);

        lb->show();

    }
}
