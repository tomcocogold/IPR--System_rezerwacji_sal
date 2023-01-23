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

    if(okno_dialogowe == "awaria")//potwierdzanie naprawenia zaznaczonej naprawy
    {
        emit zaktualizuj_panel_technika();
    }
    else if(okno_dialogowe == "przeglad")//potwierdzanie wykonania przeglądu technicznego
    {
        emit wyslij_przeglad_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_potwierdzania_przegladu();
    }
    else if(okno_dialogowe == "prosba_o_dostep")//wysłanie prośby o dostęp do sali
    {
        emit wyslij_prosbe_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_dostep_do_sali();
    }
    else if(okno_dialogowe == "zglos_awarie")//zgłoszenie awarii
    {
        emit wyslij_awarie_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_zglaszania_awarii();
    }

}


void Okno_dialogowe::on_dialogButtonBox_accepted()
{
    if(okno_dialogowe == "awaria")//potwierdzanie naprawenia zaznaczonej naprawy
    {

        QSqlQuery q;
        q.prepare("UPDATE awaria SET stan_awarii = 'naprawiona' WHERE (id_awarii = '"+ id_awarii_do_naprawy +"');");
        if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
        q.clear();

        q.prepare("INSERT INTO powiadomienie(uzytkownik_iduzytkownik,tekst) VALUES ('"+ id_uzytkownika_zalogowanego +"', 'Potwierdzenie naprawienia awarii przebiegło pomyślnie');");
        if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
            return;};
        q.clear();

        emit zaktualizuj_panel_technika();

    }
    else if(okno_dialogowe == "przeglad")//potwierdzanie wykonania przeglądu technicznego
    {
        emit wyslij_przeglad_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_potwierdzania_przegladu();
    }
    else if(okno_dialogowe == "prosba_o_dostep")//wysłanie prośby o dostęp do sali
    {
        emit wyslij_prosbe_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_dostep_do_sali();
    }
    else if(okno_dialogowe == "zglos_awarie")//zgłoszenie awarii
    {
        emit wyslij_awarie_do_bazy_danych();
        emit zaktualizuj_panel_technika();
        emit zaktualizuj_panel_zglaszania_awarii();
    }

    emit powrot_z_okna_dialogowego();
}

