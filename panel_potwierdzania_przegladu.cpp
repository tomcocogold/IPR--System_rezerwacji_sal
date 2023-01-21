#include "panel_potwierdzania_przegladu.h"
#include "ui_panel_potwierdzania_przegladu.h"

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
    emit wroc();
}


void Panel_potwierdzania_przegladu::on_potwierdz_przeglad_clicked()
{
    emit przejdz_do_okna_dialogowego();
}

