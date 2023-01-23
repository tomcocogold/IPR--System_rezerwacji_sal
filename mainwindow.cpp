#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    okno_dialogowe = new Okno_dialogowe;

    // Sloty i sygnaly dla wszystkich okien i zdarzen:
    connect(&panel_logowania, SIGNAL(zaloguj()), this, SLOT(zaloguj()));
    connect(&panel_logowania, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));

    connect(&panel_potwierdzania_przegladu, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(&panel_potwierdzania_przegladu, SIGNAL(przejdz_do_okna_dialogowego()), this, SLOT(przejdz_do_okna_dialogowego()));
    connect(&panel_potwierdzania_przegladu, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));

    connect(&panel_technika, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(&panel_technika, SIGNAL(przejdz_do_okna_dialogowego()), this, SLOT(przejdz_do_okna_dialogowego()));
    connect(&panel_technika, SIGNAL(przejdz_do_panelu_dostepu_do_sali()), this, SLOT(przejdz_do_panelu_dostepu_do_sali()));
    connect(&panel_technika, SIGNAL(przejdz_do_panelu_potwierdzania_przegladu()), this, SLOT(przejdz_do_panelu_potwierdzania_przegladu()));
    connect(&panel_technika, SIGNAL(przejdz_do_panelu_wyswietlania_rezerwacji()), this, SLOT(przejdz_do_panelu_wyswietlania_rezerwacji()));
    connect(&panel_technika, SIGNAL(przejdz_do_panelu_zglaszania_awarii()), this, SLOT(przejdz_do_panelu_zglaszania_awarii()));
    connect(&panel_technika, SIGNAL(zaktualizuj_panel_zglaszania_awarii()), &panel_zglaszania_awarii, SLOT(zaktualizuj_panel_zglaszania_awarii()));
    connect(&panel_technika, SIGNAL(zaktualizuj_panel_dostep_do_sali()), &panel_dostep_do_sali, SLOT(zaktualizuj_panel_dostep_do_sali()));
    connect(&panel_technika, SIGNAL(zaktualizuj_panel_wyswietlania_rezerwacji()), &panel_wyswietlania_rezerwacji, SLOT(zaktualizuj_panel_wyswietlania_rezerwacji()));

    connect(&panel_dostep_do_sali, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(&panel_dostep_do_sali, SIGNAL(przejdz_do_okna_dialogowego()), this, SLOT(przejdz_do_okna_dialogowego()));
    connect(&panel_dostep_do_sali, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));

    connect(&panel_wyswietlania_rezerwacji, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(&panel_wyswietlania_rezerwacji, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));

    connect(&panel_zglaszania_awarii, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(&panel_zglaszania_awarii, SIGNAL(przejdz_do_okna_dialogowego()), this, SLOT(przejdz_do_okna_dialogowego()));
    connect(&panel_zglaszania_awarii, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));

    //connect(&okno_dialogowe, SIGNAL(wroc()), this, SLOT(wroc()));
    connect(okno_dialogowe, SIGNAL(powrot_z_okna_dialogowego()), this, SLOT(powrot_z_okna_dialogowego()));
    connect(okno_dialogowe, SIGNAL(zaktualizuj_panel_technika()), &panel_technika, SLOT(zaktualizuj_panel_technika()));
    connect(okno_dialogowe, SIGNAL(wyslij_awarie_do_bazy_danych()), &panel_zglaszania_awarii, SLOT(wyslij_awarie_do_bazy_danych()));
    connect(okno_dialogowe, SIGNAL(zaktualizuj_panel_zglaszania_awarii()), &panel_zglaszania_awarii, SLOT(zaktualizuj_panel_zglaszania_awarii()));
    connect(okno_dialogowe, SIGNAL(wyslij_przeglad_do_bazy_danych()), &panel_potwierdzania_przegladu, SLOT(wyslij_przeglad_do_bazy_danych()));
    connect(okno_dialogowe, SIGNAL(zaktualizuj_panel_potwierdzania_przegladu()), &panel_potwierdzania_przegladu, SLOT(zaktualizuj_panel_potwierdzania_przegladu()));
    connect(okno_dialogowe, SIGNAL(wyslij_prosbe_do_bazy_danych()), &panel_dostep_do_sali, SLOT(wyslij_prosbe_do_bazy_danych()));
    connect(okno_dialogowe, SIGNAL(zaktualizuj_panel_dostep_do_sali()), &panel_dostep_do_sali, SLOT(zaktualizuj_panel_dostep_do_sali()));

    // Zmiana okien:
    ui->controller->addWidget(&panel_logowania);                //  2
    ui->controller->addWidget(&panel_technika);                 //  3
    ui->controller->addWidget(&panel_dostep_do_sali);           //  4
    ui->controller->addWidget(&panel_potwierdzania_przegladu);  //  5
    ui->controller->addWidget(&panel_zglaszania_awarii);        //  6
    ui->controller->addWidget(&panel_wyswietlania_rezerwacji);  //  7
    //ui->controller->addWidget(&okno_dialogowe);                 //  8

    // Ustawienie poczatkowej logowanie_window jako strone startowa:
    ui->controller->setCurrentIndex(2);
    formerIndex.push_back(ui->controller->currentIndex());
    // formerIndex.removeLast();
    // formerIndex[formerIndex.size()]
    // formerIndex.takeLast(); isEmpty()?

    //formerIndex = ui->controller->currentIndex();

    // Polaczenie sie z baza danych:
    mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("localhost");
    mydb.setDatabaseName("ipr");
    mydb.setPort(3306);
    mydb.setUserName("root");
    mydb.setPassword("");

    if(!mydb.open())
       qDebug()<<"Nie otwarto bazy danych";
    else
       qDebug()<<"Otwarto baze danych";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zaloguj()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(3);
}

void MainWindow::wroc()
{
    ui->controller->setCurrentIndex(formerIndex.takeLast());
}

void MainWindow::przejdz_do_okna_dialogowego()
{
    okno_dialogowe->show();
}

void MainWindow::powrot_z_okna_dialogowego()
{
    if(ui->controller->currentIndex()==5)
    {
        formerIndex.push_back(ui->controller->currentIndex());
        ui->controller->setCurrentIndex(3);
    }

}

void MainWindow::przejdz_do_panelu_potwierdzania_przegladu()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(5);
}

void MainWindow::przejdz_do_panelu_zglaszania_awarii()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(6);
}

void MainWindow::przejdz_do_panelu_wyswietlania_rezerwacji()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(7);
}

void MainWindow::przejdz_do_panelu_dostepu_do_sali()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(4);
}

void MainWindow::przejdz_do_panelu_technika()
{
    formerIndex.push_back(ui->controller->currentIndex());
    ui->controller->setCurrentIndex(3);
}


