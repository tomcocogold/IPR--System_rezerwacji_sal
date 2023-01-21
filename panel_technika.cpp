#include "panel_technika.h"
#include "ui_panel_technika.h"

Panel_technika::Panel_technika(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_technika)
{
    ui->setupUi(this);
}

Panel_technika::~Panel_technika()
{
    delete ui;
}




void Panel_technika::on_potwierdz_przeglad_clicked()
{
    emit przejdz_do_panelu_potwierdzania_przegladu();
}


void Panel_technika::on_wyswietl_rezerwacje_clicked()
{
    emit przejdz_do_panelu_wyswietlania_rezerwacji();
}


void Panel_technika::on_popros_o_dostep_clicked()
{
    emit przejdz_do_panelu_dostepu_do_sali();
}


void Panel_technika::on_zglos_awarie_clicked()
{
    emit przejdz_do_panelu_zglaszania_awarii();
}


void Panel_technika::on_wyloguj_clicked()
{
    emit wroc();
}


void Panel_technika::on_potwierdz_naprawe_awarii_clicked()
{
    emit przejdz_do_okna_dialogowego();
}

