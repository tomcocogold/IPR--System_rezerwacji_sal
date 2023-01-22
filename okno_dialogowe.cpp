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
    if(okno_dialogowe == "awaria")//potwierdzanie naprawenia zaznaczonej naprawy
    {

        QSqlQuery q;
        q.prepare("UPDATE awaria SET naprawiona=1 WHERE (idawaria = '"+ id_awarii_do_naprawy +"');");
        if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
        q.clear();

        emit wypelnij_panel_technika();

    }
    else if(okno_dialogowe == "przeglad")//potwierdzanie wykonania przeglądu technicznego
    {

    }
    else if(okno_dialogowe == "prosba_o_dostep")//wysłanie prośby o dostęp do sali
    {

    }
    else if(okno_dialogowe == "zglos_awarie")//zgłoszenie awarii
    {

    }

    emit powrot_z_okna_dialogowego();
}

