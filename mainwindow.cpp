#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calculateRmax()
{
    double h1,h2,r;
    h1=ui->h1->value();
    h2=ui->h1->value();
    r=4.12*(qSqrt(h1)+qSqrt(h2));
    ui->r->setMaximum(r);
}

void MainWindow::calculate()
{
    double r,h1,h2,d1,d2,p1,f,F,p2,lambda;
    h1=ui->h1->value();
    h2=ui->h1->value();
    d1=ui->d1->value();
    d2=ui->d2->value();
    p1=ui->p1->value();
    f=ui->f->value();
    F=ui->F->value();
if(ui->checkBox->isChecked()){//расчет r - auto
 r=4.12*(qSqrt(h1)+qSqrt(h2));
 ui->r->setValue(r);
} else{
    r=ui->r->value();
}
//p2=6,33*qPow(10,3) *p1*d1*d2*qPow((3*qPow(10,8) /f),2) *qPow(F,2) /qPow(r,2);
lambda=3*qPow(10,8)/(f*qPow(10,3));
p2=6.33*qPow(10,3)*p1*d1*d2*qPow(lambda,2)*qPow(F,2)/qPow(r,2);
        ui->p2->setText(QString::number(p2*qPow(10,-9),f,3));
}

void MainWindow::on_checkBox_toggled(bool checked)
{
  ui->r->setEnabled(!checked);
  calculate();
}

void MainWindow::on_h1_valueChanged()
{
    calculateRmax();
    calculate();
}

void MainWindow::on_h2_valueChanged()
{
  calculateRmax();
  calculate();
}

void MainWindow::on_f_valueChanged()
{
    calculate();
}

void MainWindow::on_p1_valueChanged()
{
    calculate();
}

void MainWindow::on_d1_valueChanged()
{
    calculate();
}

void MainWindow::on_d2_valueChanged()
{
    calculate();
}

void MainWindow::on_r_valueChanged()
{
    if(!ui->checkBox->isChecked()){//r вводится вручную
        calculate();
    }
}

void MainWindow::on_F_valueChanged()
{
    calculate();
}
