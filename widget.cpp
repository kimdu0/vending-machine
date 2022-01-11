#include <iostream>
#include <QMessageBox>
#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget(){
    delete ui;
}

void Widget::changeMoney(int coin){
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl() {
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbChange->setEnabled(money > 0);
}

void Widget::on_pbCoin500_clicked() {
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked(){
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked(){
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked(){
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked(){
    changeMoney(-200);

}

void Widget::on_pbTea_clicked(){
    changeMoney(-150);

}


void Widget::on_pbMilk_clicked(){
    changeMoney(-100);

}

void Widget::on_pbChange_clicked()
{
    int coin500 = 0;
    coin500 = money / 500;
    money = money % 500;

    int coin100 = 0;
    coin100 = money / 100;
    money = money % 100;

    int coin50 = 0;
    coin50 = money / 50;
    money = money % 50;

    int coin10 = 0;
    coin10 = money / 10;
    money = money % 10;


    QString message;
    message = "500원:\t" + QString::number(coin500) + "\n";
    message += "100원:\t" + QString::number(coin100) + "\n";
    message += "50원:\t" + QString::number(coin50) + "\n";
    message += "10원:\t" + QString::number(coin10);

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("잔돈이 반환됩니다. ");
    msgBox.setInformativeText(message);
    msgBox.exec();

    ui->lcdNumber->display(money);
    setControl();
}