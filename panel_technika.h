#ifndef PANEL_TECHNIKA_H
#define PANEL_TECHNIKA_H

#include <QWidget>

namespace Ui {
class Panel_technika;
}

class Panel_technika : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_technika(QWidget *parent = nullptr);
    ~Panel_technika();

signals:
    void wroc();    //wyloguj
    void przejdz_do_okna_dialogowego();
    void przejdz_do_panelu_potwierdzania_przegladu();
    void przejdz_do_panelu_zglaszania_awarii();
    void przejdz_do_panelu_wyswietlania_rezerwacji();
    void przejdz_do_panelu_dostepu_do_sali();
    void zaktualizuj_panel_zglaszania_awarii();
    void zaktualizuj_panel_dostep_do_sali();

private slots:


    void on_potwierdz_przeglad_clicked();

    void on_wyswietl_rezerwacje_clicked();

    void on_popros_o_dostep_clicked();

    void on_zglos_awarie_clicked();

    void on_wyloguj_clicked();

    void on_potwierdz_naprawe_awarii_clicked();

    void zaktualizuj_panel_technika();

    void on_tableView_awarie_clicked(const QModelIndex &index);

    void on_tableView_przeglady_clicked(const QModelIndex &index);

    void on_szukaj_awarie_do_naprawy_clicked();

    void on_szukaj_przeglady_do_wykonania_clicked();

    void on_lineEdit_szukanie_awarii_textChanged(const QString &arg1);

    void on_lineEdit_szukanie_przegladu_textChanged(const QString &arg1);



    void on_listView_powiadomienia_doubleClicked(const QModelIndex &index);

private:
    Ui::Panel_technika *ui;
};

#endif // PANEL_TECHNIKA_H
