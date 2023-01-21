#include "mainwindow.h"
#include "okno_dialogowe.h"
#include "ui_okno_dialogowe.h"

Okno_dialogowe::Okno_dialogowe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Okno_dialogowe)
{
    ui->setupUi(this);
}


Okno_dialogowe::~Okno_dialogowe()
{
    delete ui;
}

void Okno_dialogowe::on_dialogButtonBox_rejected()
{

}


void Okno_dialogowe::on_dialogButtonBox_accepted()
{
    emit powrot_z_okna_dialogowego();
}

