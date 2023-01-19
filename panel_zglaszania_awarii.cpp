#include "panel_zglaszania_awarii.h"
#include "ui_panel_zglaszania_awarii.h"

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
