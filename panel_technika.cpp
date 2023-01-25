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

void Panel_technika::on_wyswietl_rezerwacje_clicked()
{
    emit zaktualizuj_panel_wyswietlania_rezerwacji();
    emit przejdz_do_panelu_wyswietlania_rezerwacji();
}


void Panel_technika::on_popros_o_dostep_clicked()
{
    okno_dialogowe="prosba_o_dostep";
    emit przejdz_do_panelu_dostepu_do_sali();
    emit zaktualizuj_panel_dostep_do_sali();
}


void Panel_technika::on_zglos_awarie_clicked()
{
    okno_dialogowe="zglos_awarie";
    emit zaktualizuj_panel_zglaszania_awarii();
    emit przejdz_do_panelu_zglaszania_awarii();
}


void Panel_technika::on_wyloguj_clicked()
{
    id_uzytkownika_zalogowanego = nullptr;
    id_awarii_do_naprawy = nullptr;
    id_przegladu_do_naprawy = nullptr;
    okno_dialogowe = nullptr;

    emit wroc();
}


void Panel_technika::zaktualizuj_panel_technika()
{
    ui->potwierdz_naprawe_awarii->setDisabled(true);//dopóki nie zaznaczymy jakiejś awarii to nie da się wcisnąć przycisku
    ui->potwierdz_przeglad->setDisabled(true);//to samo robimy z przyciskiem od przegladów
    ui->lineEdit_szukanie_awarii->clear();
    ui->lineEdit_szukanie_przegladu->clear();

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

    //Wyświetlenie powiadomień
    QSqlQuery q3;
    q3.prepare("SELECT tekst FROM powiadomienie WHERE uzytkownik_iduzytkownik = '"+id_uzytkownika_zalogowanego+"'");
    if(!q3.exec()){qDebug() << "Error: " << q3.lastError().text();};
    QSqlQueryModel * m3 = new QSqlQueryModel();
    m3->setQuery(q3);
    ui->listView_powiadomienia->setModel(m3);
    while(q3.next()){
        //qInfo() << q.value(0).toString();
    }
    q3.clear();
}

void Panel_technika::on_tableView_awarie_clicked(const QModelIndex &index)
{
    ui->potwierdz_naprawe_awarii->setEnabled(true);
    qInfo() << "Klikniete -> rzad: " << index.row() << "kolumna: " << index.column() << "wartosc: " << index.model()->index(index.row(),index.column()).data().toString();
    qInfo() << "Id wybranej awarii: " << index.model()->index(index.row(),0).data().toString();
    id_awarii_do_naprawy = index.model()->index(index.row(),0).data().toString();

}

void Panel_technika::on_potwierdz_naprawe_awarii_clicked()
{
     emit przejdz_do_okna_dialogowego();
     okno_dialogowe="awaria";
}

void Panel_technika::on_tableView_przeglady_clicked(const QModelIndex &index)
{
    ui->potwierdz_przeglad->setEnabled(true);
    qInfo() << "Klikniete -> rzad: " << index.row() << "kolumna: " << index.column() << "wartosc: " << index.model()->index(index.row(),index.column()).data().toString();
    qInfo() << "Id wybranego przegladu: " << index.model()->index(index.row(),0).data().toString();
    id_przegladu_do_naprawy = index.model()->index(index.row(),0).data().toString();

}

void Panel_technika::on_potwierdz_przeglad_clicked()
{
    emit przejdz_do_panelu_potwierdzania_przegladu();
    okno_dialogowe="przeglad";
}

void Panel_technika::on_szukaj_awarie_do_naprawy_clicked()
{
    ui->potwierdz_naprawe_awarii->setDisabled(true);//dopóki nie zaznaczymy jakiejś awarii to nie da się wcisnąć przycisku
    ui->potwierdz_przeglad->setDisabled(true);//to samo robimy z przyciskiem od przegladów
    if(ui->lineEdit_szukanie_awarii->text() != nullptr || ui->lineEdit_szukanie_awarii->text() != "")
    {
        QString szukana_fraza1 = ui->lineEdit_szukanie_awarii->text();
        QSqlQuery q1;
        q1.prepare("SELECT id_awarii,numer_sali,rodzaj_awarii,opis_awarii,stan_awarii FROM awaria WHERE (((id_awarii LIKE '%"+szukana_fraza1+"%')OR(numer_sali LIKE '%"+szukana_fraza1+"%')OR(rodzaj_awarii LIKE '%"+szukana_fraza1+"%')OR(opis_awarii LIKE '%"+szukana_fraza1+"%')) AND (stan_awarii='do naprawy'))");
        if(!q1.exec()){qDebug() << "Error: " << q1.lastError().text();};
        QSqlQueryModel * m1 = new QSqlQueryModel();
        m1->setQuery(q1);
        ui->tableView_awarie->setModel(m1);
        while(q1.next()){
            //qInfo() << q.value(0).toString();
        }
        q1.clear();
    }
    else return;

}


void Panel_technika::on_szukaj_przeglady_do_wykonania_clicked()
{
    ui->potwierdz_naprawe_awarii->setDisabled(true);//dopóki nie zaznaczymy jakiejś awarii to nie da się wcisnąć przycisku
    ui->potwierdz_przeglad->setDisabled(true);//to samo robimy z przyciskiem od przegladów
    if(ui->lineEdit_szukanie_przegladu->text() != nullptr || ui->lineEdit_szukanie_przegladu->text() != "")
    {
        QString szukana_fraza2 = ui->lineEdit_szukanie_przegladu->text();
        QSqlQuery q2;
        q2.prepare("SELECT id_przegladu,numer_sali,stan_przegladu FROM przeglad WHERE (((id_przegladu LIKE '%"+szukana_fraza2+"%')OR(numer_sali LIKE '%"+szukana_fraza2+"%')) AND (stan_przegladu='do wykonania'))");
        if(!q2.exec()){qDebug() << "Error: " << q2.lastError().text();};
        QSqlQueryModel * m2 = new QSqlQueryModel();
        m2->setQuery(q2);
        ui->tableView_przeglady->setModel(m2);
        while(q2.next()){
            //qInfo() << q.value(0).toString();
        }
        q2.clear();
    }
    else return;
}


void Panel_technika::on_lineEdit_szukanie_awarii_textChanged(const QString &arg1)
{
    if(arg1=="") zaktualizuj_panel_technika();
}


void Panel_technika::on_lineEdit_szukanie_przegladu_textChanged(const QString &arg1)
{
    if(arg1=="") zaktualizuj_panel_technika();
}


void Panel_technika::on_listView_powiadomienia_doubleClicked(const QModelIndex &index)
{

    QString powiadomienie = index.model()->index(index.row(),0).data().toString();
    QSqlQuery q;
    q.prepare("DELETE FROM powiadomienie WHERE (uzytkownik_iduzytkownik = "+ id_uzytkownika_zalogowanego +" AND tekst =  '"+ powiadomienie +"')");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();
    zaktualizuj_panel_technika();
}

