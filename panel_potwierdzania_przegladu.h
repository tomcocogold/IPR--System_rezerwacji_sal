#ifndef PANEL_POTWIERDZANIA_PRZEGLADU_H
#define PANEL_POTWIERDZANIA_PRZEGLADU_H

#include <QWidget>

namespace Ui {
class Panel_potwierdzania_przegladu;
}

class Panel_potwierdzania_przegladu : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_potwierdzania_przegladu(QWidget *parent = nullptr);
    ~Panel_potwierdzania_przegladu();

signals:
    void wroc();
    void przejdz_do_okna_dialogowego();
    void zaktualizuj_panel_technika();

private slots:
    void on_wroc_clicked();

    void on_potwierdz_przeglad_clicked();

    void wyslij_przeglad_do_bazy_danych();

    void zaktualizuj_panel_potwierdzania_przegladu();

private:
    Ui::Panel_potwierdzania_przegladu *ui;
};

#endif // PANEL_POTWIERDZANIA_PRZEGLADU_H
