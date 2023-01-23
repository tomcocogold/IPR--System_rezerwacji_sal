#ifndef PANEL_WYSWIETLANIA_REZERWACJI_H
#define PANEL_WYSWIETLANIA_REZERWACJI_H

#include <QWidget>

namespace Ui {
class Panel_wyswietlania_rezerwacji;
}

class Panel_wyswietlania_rezerwacji : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_wyswietlania_rezerwacji(QWidget *parent = nullptr);
    ~Panel_wyswietlania_rezerwacji();

signals:
    void wroc();
    void zaktualizuj_panel_technika();

private slots:
    void on_wroc_clicked();
    void zaktualizuj_panel_wyswietlania_rezerwacji();

    void on_kalendarz_clicked(const QDate &date);

private:
    Ui::Panel_wyswietlania_rezerwacji *ui;
};

#endif // PANEL_WYSWIETLANIA_REZERWACJI_H
