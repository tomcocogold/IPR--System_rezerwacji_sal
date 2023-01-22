#include "panel_logowania.h"
#include "ui_panel_logowania.h"
#include "mainwindow.h"


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
    // ### Pobranie wpisanego loginu i hasla i sprawdzenie czy jest taki uzytkownik, w naszym przypadku tylko techników sprawdzamy
    QString nazwa_uzytkownika = ui->haslo_2->text();
    QString haslo = ui->nazwa_uzytkownika_2->text();

    QSqlQuery q;
    q.prepare("SELECT * FROM uzytkownik");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
    while(q.next()){
        if(q.value(3).toString() == nazwa_uzytkownika && q.value(4).toString() == haslo){
            //zaloguj_id_uzytkownika = q.value(0).toString();
            //zaloguj_nazwa_uzytkownika = nazwa_uzytkownika;
            //zaloguj_haslo = haslo;
            qInfo() << "Zalogowano: " << nazwa_uzytkownika << haslo;
            emit zaloguj();
            ui->haslo_2->clear();
            ui->nazwa_uzytkownika_2->clear();
        }
    }
    q.clear();
    // ###
}

