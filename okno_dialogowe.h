#ifndef OKNO_DIALOGOWE_H
#define OKNO_DIALOGOWE_H

#include <QDialog>

namespace Ui {
class Okno_dialogowe;
}

class Okno_dialogowe : public QDialog
{
    Q_OBJECT

public:
    explicit Okno_dialogowe(QWidget *parent = nullptr);
    ~Okno_dialogowe();

signals:
    void wroc();
    void powrot_z_okna_dialogowego();
    void zaktualizuj_panel_technika();
    void wyslij_awarie_do_bazy_danych();
    void zaktualizuj_panel_zglaszania_awarii();
    void zaktualizuj_panel_potwierdzania_przegladu();
    void wyslij_przeglad_do_bazy_danych();
    void zaktualizuj_panel_dostep_do_sali();
    void wyslij_prosbe_do_bazy_danych();

private slots:
    void on_dialogButtonBox_rejected();

    void on_dialogButtonBox_accepted();

private:
    Ui::Okno_dialogowe *ui;
};

#endif // OKNO_DIALOGOWE_H
