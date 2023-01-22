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
    emit zaktualizuj_dane();
}


void Okno_dialogowe::on_dialogButtonBox_accepted()
{
    if(okno_dialogowe == "awaria")//potwierdzanie naprawenia zaznaczonej naprawy
    {

        QSqlQuery q;
        q.prepare("UPDATE awaria SET stan_awarii = 'naprawiona' WHERE (id_awarii = '"+ id_awarii_do_naprawy +"');");
        if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
        q.clear();

        emit zaktualizuj_dane();

    }
    else if(okno_dialogowe == "przeglad")//potwierdzanie wykonania przeglądu technicznego
    {

        emit zaktualizuj_dane();
    }
    else if(okno_dialogowe == "prosba_o_dostep")//wysłanie prośby o dostęp do sali
    {

        emit zaktualizuj_dane();
    }
    else if(okno_dialogowe == "zglos_awarie")//zgłoszenie awarii
    {

        emit zaktualizuj_dane();
    }

    emit powrot_z_okna_dialogowego();
}

