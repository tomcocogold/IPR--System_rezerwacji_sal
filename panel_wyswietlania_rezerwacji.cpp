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
    emit zaktualizuj_panel_technika();
    emit wroc();
}

void Panel_wyswietlania_rezerwacji::zaktualizuj_panel_wyswietlania_rezerwacji()
{
    //czyścimy wcześniej wprowadzone dane
    ui->wybierz_sale_2->clear();


    QSqlQuery q;
    q.prepare("SELECT numer_sali_rezerwowalnej FROM sala_rezerwowalna;");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
    ui->wybierz_sale_2->addItem("");
    while(q.next()){
        //qInfo() << q.value(0).toString();
        ui->wybierz_sale_2->addItem(q.value(0).toString());
    }
    q.clear();

    ui->miesiac_tydzien->addItem("Miesiąc");
    ui->miesiac_tydzien->addItem("Tydzień");


}


void Panel_wyswietlania_rezerwacji::on_kalendarz_clicked(const QDate &date)
{

}

