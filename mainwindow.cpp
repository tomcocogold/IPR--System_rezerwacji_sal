#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Sloty i sygnaly dla wszystkich okien i zdarzen:
    connect(&login_window, SIGNAL(login()), this, SLOT(login()));
    connect(&login_window, SIGNAL(login_admin()), this, SLOT(login_admin()));
    connect(&login_window, SIGNAL(registration()), this, SLOT(registration()));
    connect(&login_window, SIGNAL(update_data()), &account_window, SLOT(update_data()));
    connect(&login_window, SIGNAL(clear_lineEdits()), &account_window, SLOT(clear_lineEdits()));

    connect(&register_window, SIGNAL(go_back()), this, SLOT(go_back()));

    connect(&account_window, SIGNAL(go_back()), this, SLOT(go_back()));
    connect(&account_window, SIGNAL(update_data_signal()), &account_window, SLOT(update_data()));
    connect(&account_window, SIGNAL(add_advert()), this, SLOT(add_advert()));
    connect(&account_window, SIGNAL(show_advert()), this, SLOT(show_advert()));
    connect(&account_window, SIGNAL(show_advert()), &advert_window, SLOT(clear_advert_lineEdits()));
    connect(&account_window, SIGNAL(show_advert()), &advert_window, SLOT(update_advert_data()));
    connect(&account_window, SIGNAL(search_advert()), this, SLOT(search_advert()));
    connect(&account_window, SIGNAL(update_search_advert_data_signal()), &search_window, SLOT(update_search_advert_data()));
    connect(&account_window, SIGNAL(update_add_advert_window_data_signal()), &add_advert_window, SLOT(update_data()));

    connect(&admin_window, SIGNAL(go_back()), this, SLOT(go_back()));

    connect(&add_advert_window, SIGNAL(go_back()), this, SLOT(go_back()));
    connect(&add_advert_window, SIGNAL(update_account_window_data()), &account_window, SLOT(update_data()));

    connect(&advert_window, SIGNAL(go_back()), this, SLOT(go_back()));
    connect(&advert_window, SIGNAL(go_back()), &account_window, SLOT(update_data()));
    connect(&advert_window, SIGNAL(update_advert_data_signal()), &advert_window, SLOT(update_advert_data()));

    connect(&search_window, SIGNAL(go_back()), this, SLOT(go_back()));
    connect(&search_window, SIGNAL(update_account_window_data()), &account_window, SLOT(update_data()));

    // Zmiana okien:
    ui->controller->addWidget(&panel_logowania);                //  2
    ui->controller->addWidget(&panel_technika);                 //  3
    ui->controller->addWidget(&panel_dostep_do_sali);           //  4
    ui->controller->addWidget(&panel_potwierdzania_przegladu);  //  5
    ui->controller->addWidget(&panel_zglaszania_awarii);        //  6
    ui->controller->addWidget(&panel_wyswietlania_rezerwacji);  //  7
    ui->controller->addWidget(&okno_dialogowe);                 //  8

    // Ustawienie poczatkowej login_window jako strone startowa:
    ui->controller->setCurrentIndex(2);
    formerIndex.push_back(ui->controller->currentIndex());
    // formerIndex.removeLast();
    // formerIndex[formerIndex.size()]
    // formerIndex.takeLast(); isEmpty()?

    //formerIndex = ui->controller->currentIndex();

    // Polaczenie sie z baza danych:
    mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("localhost");
    mydb.setDatabaseName("psbd");
    mydb.setPort(3306);
    mydb.setUserName("demouser");
    mydb.setPassword("demopassword");

    if(!mydb.open())
        qDebug()<<"Nie otwarto bazy danych";
    else
        qDebug()<<"Otwarto baze danych";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logowanie()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(4);
}

void MainWindow::login_admin()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(5);
}

void MainWindow::go_back()
{
    ui->controller->setCurrentIndex(formerIndex.takeLast());
}

void MainWindow::registration()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(3);
}

void MainWindow::add_advert()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(6);
}

void MainWindow::show_advert()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(7);
}

void MainWindow::search_advert()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(8);
}

