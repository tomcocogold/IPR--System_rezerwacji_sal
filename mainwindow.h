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

// Zmienne globalne
extern QString logged_email;
extern QString logged_password;
extern QString logged_id;
extern QString logged_account_type;
extern QString selected_advert_id;
extern QString selected_raport;

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
    void logowanie();
    void login_admin();
    void go_back();
    void registration();
    void add_advert();
    void show_advert();
    void search_advert();

private:
    Ui::MainWindow *ui;

    Okno_dialogowe okno_dialogowe;
    Panel_dostep_do_sali panel_dostep_do_sali;
    Panel_technika panel_technika;
    Panel_potwierdzania_przegladu panel_potwierdzania_przegladu;
    Panel_wyswietlania_rezerwacji panel_wyswietlania_rezerwacji;
    Panel_zglaszania_awarii panel_zglaszania_awarii;
    QVector<int> formerIndex; // Numer okna ktory byl wyswietlany
};
#endif // MAINWINDOW_H
