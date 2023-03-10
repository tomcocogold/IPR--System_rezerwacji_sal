#ifndef PANEL_DOSTEP_DO_SALI_H
#define PANEL_DOSTEP_DO_SALI_H

#include <QWidget>

namespace Ui {
class Panel_dostep_do_sali;
}

class Panel_dostep_do_sali : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_dostep_do_sali(QWidget *parent = nullptr);
    ~Panel_dostep_do_sali();

signals:
    void wroc();
    void przejdz_do_okna_dialogowego();
    void zaktualizuj_panel_technika();

private slots:
    void on_wroc_clicked();

    void on_zglos_prosbe_clicked();

    void wyslij_prosbe_do_bazy_danych();

    void zaktualizuj_panel_dostep_do_sali();

    void on_wybierz_sale_currentIndexChanged(int index);

private:
    Ui::Panel_dostep_do_sali *ui;
};

#endif // PANEL_DOSTEP_DO_SALI_H
