#include "panel_technika.h"
#include "ui_panel_technika.h"
#include "mainwindow.h"

Panel_technika::Panel_technika(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_technika)
{
    ui->setupUi(this);
    //Wyświetlenie awarii do naprawy
    QSqlQuery q1;
    q1.prepare("SELECT * FROM ipr.awaria");
    if(!q1.exec()){qDebug() << "Error: " << q1.lastError().text();};
    QSqlQueryModel * m1 = new QSqlQueryModel();
    m1->setQuery(q1);
    ui->tableView_awarie->setModel(m1);
    while(q1.next()){
        //qInfo() << q.value(0).toString();
    }
    q1.clear();

    //Wyświetlenie przeglądów technicznych do wykonania
    QSqlQuery q2;
    q2.prepare("SELECT * FROM ipr.przeglad");
    if(!q2.exec()){qDebug() << "Error: " << q2.lastError().text();};
    QSqlQueryModel * m2 = new QSqlQueryModel();
    m2->setQuery(q2);
    ui->tableView_przeglady->setModel(m2);
    while(q2.next()){
        //qInfo() << q.value(0).toString();
    }
    q2.clear();
}

Panel_technika::~Panel_technika()
{
    delete ui;
}


void Panel_technika::on_potwierdz_przeglad_clicked()
{
    emit przejdz_do_panelu_potwierdzania_przegladu();
}


void Panel_technika::on_wyswietl_rezerwacje_clicked()
{
    emit przejdz_do_panelu_wyswietlania_rezerwacji();
}


void Panel_technika::on_popros_o_dostep_clicked()
{
    emit przejdz_do_panelu_dostepu_do_sali();
}


void Panel_technika::on_zglos_awarie_clicked()
{
    emit przejdz_do_panelu_zglaszania_awarii();
}


void Panel_technika::on_wyloguj_clicked()
{
    emit wroc();
}


void Panel_technika::on_potwierdz_naprawe_awarii_clicked()
{
    emit przejdz_do_okna_dialogowego();
}

