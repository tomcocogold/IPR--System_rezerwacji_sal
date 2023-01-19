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
