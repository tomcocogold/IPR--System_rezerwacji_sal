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
