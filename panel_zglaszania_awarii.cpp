#include "panel_zglaszania_awarii.h"
#include "ui_panel_zglaszania_awarii.h"
#include "mainwindow.h"

Panel_zglaszania_awarii::Panel_zglaszania_awarii(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_zglaszania_awarii)
{
    ui->setupUi(this);
}

Panel_zglaszania_awarii::~Panel_zglaszania_awarii()
{
    delete ui;
}

void Panel_zglaszania_awarii::on_wroc_clicked()
{
    emit zaktualizuj_dane();
    emit wroc();
}


void Panel_zglaszania_awarii::on_zglos_awarie_clicked()
{
    emit przejdz_do_okna_dialogowego();
}

