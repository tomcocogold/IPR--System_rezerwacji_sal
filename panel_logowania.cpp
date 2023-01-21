#include "panel_logowania.h"
#include "ui_panel_logowania.h"

Panel_logowania::Panel_logowania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_logowania)
{
    ui->setupUi(this);
}

Panel_logowania::~Panel_logowania()
{
    delete ui;
}

void Panel_logowania::on_pushButton_clicked()
{
    emit zaloguj();
}

