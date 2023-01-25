#include "panel_zglaszania_awarii.h"
#include "ui_panel_zglaszania_awarii.h"
#include "mainwindow.h"

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

void Panel_zglaszania_awarii::on_wroc_clicked()
{
    emit zaktualizuj_panel_technika();
    emit wroc();
}


void Panel_zglaszania_awarii::on_zglos_awarie_clicked()
{
    if(ui->wybierz_rodzaj_awarii_2->currentText() == nullptr || ui->wybierz_sale_2->currentText() == nullptr || ui->krotki_opis_awarii->toPlainText() == nullptr ||
            ui->wybierz_rodzaj_awarii_2->currentText() == "" || ui->wybierz_sale_2->currentText() == "" || ui->krotki_opis_awarii->toPlainText() == "")
    {
        return;//muszą być wypełnione wszystkie pola, żeby okno dialogowe się otworzyło
    }
    else
    {
        okno_dialogowe = "zglos_awarie";
        emit przejdz_do_okna_dialogowego();
    }

}

void Panel_zglaszania_awarii::wyslij_awarie_do_bazy_danych()
{
    QString numer_sali = ui->wybierz_sale_2->currentText();
    QString rodzaj_awarii = ui->wybierz_rodzaj_awarii_2->currentText();
    QString opis_awarii = ui->krotki_opis_awarii->toPlainText();
    QSqlQuery q;

    q.prepare("INSERT INTO awaria (numer_sali,rodzaj_awarii,opis_awarii) VALUES ('"+ numer_sali +"', '"+ rodzaj_awarii +"', '"+ opis_awarii +"');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();

    q.prepare("INSERT INTO powiadomienie(uzytkownik_iduzytkownik,tekst) VALUES ('"+ id_uzytkownika_zalogowanego +"', 'Zgłoszona przez ciebie awaria została zatwierdzona przez opiekuna sali');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();
}

void Panel_zglaszania_awarii::zaktualizuj_panel_zglaszania_awarii()
{
    //czyścimy wcześniej wprowadzone dane
    ui->krotki_opis_awarii->clear();
    ui->wybierz_rodzaj_awarii_2->clear();
    ui->wybierz_sale_2->clear();


    QSqlQuery q;
    q.prepare("SELECT numer_sali FROM sala;");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
    ui->wybierz_sale_2->addItem("");
    while(q.next()){
        //qInfo() << q.value(0).toString();
        ui->wybierz_sale_2->addItem(q.value(0).toString());
    }
    q.clear();

    ui->wybierz_rodzaj_awarii_2->addItem("");
    ui->wybierz_rodzaj_awarii_2->addItem("rura poszla");
    ui->wybierz_rodzaj_awarii_2->addItem("piwo");
    ui->wybierz_rodzaj_awarii_2->addItem("studenci nie przyszli");
    ui->wybierz_rodzaj_awarii_2->addItem("rzutnik spadl");
    ui->wybierz_rodzaj_awarii_2->addItem("kreda przestala pisac");
    ui->wybierz_rodzaj_awarii_2->addItem("student wie wiecej od profesora");
    ui->wybierz_rodzaj_awarii_2->addItem("wskaznik polimorficzny");
    ui->wybierz_rodzaj_awarii_2->addItem("inne");

}
