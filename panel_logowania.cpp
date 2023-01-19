#include "okno_logowania.h"
#include "ui_okno_logowania.h"

Okno_logowania::Okno_logowania(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Okno_logowania)
{
    ui->setupUi(this);
}

Okno_logowania::~Okno_logowania()
{
    delete ui;
}
