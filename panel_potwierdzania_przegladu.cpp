#include "panel_potwierdzania_przegladu.h"
#include "ui_panel_potwierdzania_przegladu.h"
#include "mainwindow.h"

Panel_potwierdzania_przegladu::Panel_potwierdzania_przegladu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_potwierdzania_przegladu)
{
    ui->setupUi(this);
}

Panel_potwierdzania_przegladu::~Panel_potwierdzania_przegladu()
{
    delete ui;
}

void Panel_potwierdzania_przegladu::on_wroc_clicked()
{
    emit zaktualizuj_panel_technika();
    emit wroc();
}


void Panel_potwierdzania_przegladu::on_potwierdz_przeglad_clicked()
{
    if( ui->sprawozdanie_tekst->toPlainText() == nullptr ||  ui->sprawozdanie_tekst->toPlainText() == "" )
    {
        return;//muszą być wypełnione wszystkie pola, żeby okno dialogowe się otworzyło
    }
    else
    {
        okno_dialogowe = "przeglad";
        emit przejdz_do_okna_dialogowego();
    }
}

void Panel_potwierdzania_przegladu::wyslij_przeglad_do_bazy_danych()
{
    QString sprawozdanie = ui->sprawozdanie_tekst->toPlainText();
    QSqlQuery q;
    q.prepare("UPDATE przeglad SET sprawozdanie = '"+ sprawozdanie +"',stan_przegladu = 'wykonany' WHERE (id_przegladu = '"+ id_przegladu_do_naprawy +"');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();

    q.prepare("INSERT INTO powiadomienie(uzytkownik_iduzytkownik,tekst) VALUES ('"+ id_uzytkownika_zalogowanego +"', 'Potwierdzenie wykonania przegladu technicznego przebiegło pomyślnie');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();
}

void Panel_potwierdzania_przegladu::zaktualizuj_panel_potwierdzania_przegladu()
{
    //czyścimy wcześniej wprowadzone dane
    ui->sprawozdanie_tekst->clear();

}
