#include "panel_technika.h"
#include "ui_panel_technika.h"
#include "mainwindow.h"

QString id_awarii_do_naprawy;
QString id_przegladu_do_naprawy;
QString okno_dialogowe;

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


void Panel_technika::zaktualizuj_dane()
{
    ui->potwierdz_naprawe_awarii->setDisabled(true);//dopóki nie zaznaczymy jakiejś awarii to nie da się wcisnąć przycisku
    ui->potwierdz_przeglad->setDisabled(true);//to samo robimy z przyciskiem od przegladów
    //Wyświetlenie awarii do naprawy
    QSqlQuery q1;
    q1.prepare("SELECT id_awarii,numer_sali,rodzaj_awarii,opis_awarii,stan_awarii FROM awaria WHERE stan_awarii='do naprawy'");
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
    q2.prepare("SELECT id_przegladu,numer_sali,stan_przegladu FROM przeglad WHERE stan_przegladu = 'do wykonania'");
    if(!q2.exec()){qDebug() << "Error: " << q2.lastError().text();};
    QSqlQueryModel * m2 = new QSqlQueryModel();
    m2->setQuery(q2);
    ui->tableView_przeglady->setModel(m2);
    while(q2.next()){
        //qInfo() << q.value(0).toString();
    }
    q2.clear();
}

void Panel_technika::on_tableView_awarie_clicked(const QModelIndex &index)
{
    ui->potwierdz_naprawe_awarii->setEnabled(true);
    qInfo() << "Klikniete -> rzad: " << index.row() << "kolumna: " << index.column() << "wartosc: " << index.model()->index(index.row(),index.column()).data().toString();
    qInfo() << "Id wybranej awarii: " << index.model()->index(index.row(),0).data().toString();
    id_awarii_do_naprawy = index.model()->index(index.row(),0).data().toString();
    okno_dialogowe="awaria";
}

void Panel_technika::on_potwierdz_naprawe_awarii_clicked()
{
     emit przejdz_do_okna_dialogowego();
}

void Panel_technika::on_tableView_przeglady_clicked(const QModelIndex &index)
{
    ui->potwierdz_przeglad->setEnabled(true);
    qInfo() << "Klikniete -> rzad: " << index.row() << "kolumna: " << index.column() << "wartosc: " << index.model()->index(index.row(),index.column()).data().toString();
    qInfo() << "Id wybranego przegladu: " << index.model()->index(index.row(),0).data().toString();
    id_przegladu_do_naprawy = index.model()->index(index.row(),0).data().toString();
    okno_dialogowe="przeglad";
}

