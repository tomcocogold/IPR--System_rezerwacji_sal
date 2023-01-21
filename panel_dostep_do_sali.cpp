#include "panel_dostep_do_sali.h"
#include "ui_panel_dostep_do_sali.h"

Panel_dostep_do_sali::Panel_dostep_do_sali(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_dostep_do_sali)
{
    ui->setupUi(this);
}

Panel_dostep_do_sali::~Panel_dostep_do_sali()
{
    delete ui;
}

void Panel_dostep_do_sali::on_wroc_clicked()
{
    emit wroc();
}


void Panel_dostep_do_sali::on_zglos_prosbe_clicked()
{
    emit przejdz_do_okna_dialogowego();
}

