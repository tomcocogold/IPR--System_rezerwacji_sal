#include "panel_dostep_do_sali.h"
#include "ui_panel_dostep_do_sali.h"
#include "mainwindow.h"

Panel_dostep_do_sali::Panel_dostep_do_sali(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_dostep_do_sali)
{
    ui->setupUi(this);
}

Panel_dostep_do_sali::~Panel_dostep_do_sali()
{
    delete ui;
}

void Panel_dostep_do_sali::on_wroc_clicked()
{
    emit zaktualizuj_panel_technika();
    emit wroc();
}


void Panel_dostep_do_sali::on_zglos_prosbe_clicked()
{
    if(ui->wybierz_sale->currentText() == nullptr || ui->wybierz_sale->currentText() == "" || ui->liczba_uczestnikow->currentText() == nullptr ||
            ui->liczba_uczestnikow->currentText() == "" || ui->krotki_opis_celu_2->toPlainText() == nullptr || ui->krotki_opis_celu_2->toPlainText() == "")
    {
        return;//muszą być wypełnione wszystkie pola, żeby okno dialogowe się otworzyło
    }
    else
    {
        okno_dialogowe = "prosba_o_dostep";
        emit przejdz_do_okna_dialogowego();
    }
}


void Panel_dostep_do_sali::wyslij_prosbe_do_bazy_danych()
{
    QString numer_sali = ui->wybierz_sale->currentText();
    QString liczba_uczestnikow = ui->liczba_uczestnikow->currentText();
    QString data_rozpoczęcia = ui->data_rozpoczecia->text()+ui->godzina_rozpoczecia_2->text();
    QString data_zakonczenia = ui->data_zakonczenia->text()+ui->godzina_zakonczenia_2->text();
    QString opis_celu = ui->krotki_opis_celu_2->toPlainText();
    QSqlQuery q;

    q.prepare("INSERT INTO prosba_o_dostep (sala_numer_sali,data_rozpoczecia,data_zakonczenia,ilosc_uczestnikow,opis) VALUES ('"+ numer_sali +"', '"+ data_rozpoczęcia +"', '"+ data_zakonczenia +"', '"+ liczba_uczestnikow +"', '"+ opis_celu +"');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();

    q.prepare("INSERT INTO powiadomienie(uzytkownik_iduzytkownik,tekst) VALUES ('"+ id_uzytkownika_zalogowanego +"', 'Twoja prośba o dostęp do sali została zatwierdzona przez opiekuna sali');");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();
        return;};
    q.clear();
}

void Panel_dostep_do_sali::zaktualizuj_panel_dostep_do_sali()
{
    QDate date = QDate::currentDate();
    //QString dateString = date.toString();
    QTime time = QTime::currentTime();
    //QString timeString = time.toString();
    QTime endtime = time.addSecs(3600);
    //QString endtimeString = endtime.toString();

    //czyścimy wcześniej wprowadzone dane
    ui->wybierz_sale->clear();
    ui->liczba_uczestnikow->clear();
    ui->data_rozpoczecia->setDate(date);
    ui->godzina_rozpoczecia_2->setTime(time);
    ui->data_zakonczenia->setDate(date);
    ui->godzina_zakonczenia_2->setTime(endtime);
    ui->krotki_opis_celu_2->clear();

    QSqlQuery q;
    q.prepare("SELECT numer_sali FROM sala;");
    if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
    ui->wybierz_sale->addItem("");
    while(q.next()){
        //qInfo() << q.value(0).toString();
        ui->wybierz_sale->addItem(q.value(0).toString());
    }
    q.clear();

}



void Panel_dostep_do_sali::on_wybierz_sale_currentIndexChanged(int index)
{

    if(ui->wybierz_sale->currentText() != "")//wybraliśmy jakąś salę
    {

        QSqlQuery q;
        q.prepare("SELECT pojemnosc FROM sala WHERE numer_sali = "+ui->wybierz_sale->currentText()+";");
        if(!q.exec()){qDebug() << "Error: " << q.lastError().text();};
        q.first();
        QString pojemnosc_sali = q.value(0).toString();
        qDebug() << "Pojemnosc wybranej sali to: "<<pojemnosc_sali;
        ui->liczba_uczestnikow->addItem("");
        int i = 1;
        while(i<pojemnosc_sali.toInt()+1)
        {
            ui->liczba_uczestnikow->addItem(QString::number(i));
            i++;
        }
        q.clear();
    }

    else return;
}

