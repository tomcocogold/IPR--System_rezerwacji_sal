#include "okno_dialogowe.h"
#include "ui_okno_dialogowe.h"

okno_dialogowe::okno_dialogowe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::okno_dialogowe)
{
    ui->setupUi(this);
}

okno_dialogowe::~okno_dialogowe()
{
    delete ui;
}
