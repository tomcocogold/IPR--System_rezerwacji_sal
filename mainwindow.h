#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

#include <QMessageBox>
#include <QFileInfo>
#include <ctime>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>

#include <panel_logowania.h>
#include <okno_dialogowe.h>
#include <panel_technika.h>
#include <panel_dostep_do_sali.h>
#include <panel_potwierdzania_przegladu.h>
#include <panel_zglaszania_awarii.h>
#include <panel_wyswietlania_rezerwacji.h>
#include <lista_awarii.h>
#include <lista_prob.h>
#include <lista_przegladow_technicznych.h>
#include <lista_rezerwacji.h>
#include <lista_sal.h>
#include <lista_sprzetow.h>
#include <lista_uzytkownikow.h>
#include <lista_wynajmow.h>
#include <lista_powiadomien.h>

// Zmienne globalne
extern QString id_uzytkownika_zalogowanego;
extern QString id_awarii_do_naprawy;
extern QString id_przegladu_do_naprawy;
extern QString okno_dialogowe;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase mydb;

private slots:
    void zaloguj();
    void wroc();
    void wyloguj();
    void przejdz_do_okna_dialogowego();
    void przejdz_do_panelu_potwierdzania_przegladu();
    void przejdz_do_panelu_zglaszania_awarii();
    void przejdz_do_panelu_wyswietlania_rezerwacji();
    void przejdz_do_panelu_dostepu_do_sali();
    void przejdz_do_panelu_technika();
    void powrot_z_okna_dialogowego();


private:
    Ui::MainWindow *ui;

    Okno_dialogowe* okno_dialogowe; //popup window
    Panel_logowania panel_logowania;
    Panel_dostep_do_sali panel_dostep_do_sali;
    Panel_technika panel_technika;
    Panel_potwierdzania_przegladu panel_potwierdzania_przegladu;
    Panel_wyswietlania_rezerwacji panel_wyswietlania_rezerwacji;
    Panel_zglaszania_awarii panel_zglaszania_awarii;

    QVector<int> formerIndex; // Numer okna ktory byl wyswietlany
};
#endif // MAINWINDOW_H
