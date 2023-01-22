#include "panel_wyswietlania_rezerwacji.h"
#include "ui_panel_wyswietlania_rezerwacji.h"
#include "mainwindow.h"

Panel_wyswietlania_rezerwacji::Panel_wyswietlania_rezerwacji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_wyswietlania_rezerwacji)
{
    ui->setupUi(this);
}

Panel_wyswietlania_rezerwacji::~Panel_wyswietlania_rezerwacji()
{
    delete ui;
}

void Panel_wyswietlania_rezerwacji::on_wroc_clicked()
{
    emit zaktualizuj_dane();
    emit wroc();
}

