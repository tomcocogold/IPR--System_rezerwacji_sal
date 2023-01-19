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

private:
    Ui::Panel_wyswietlania_rezerwacji *ui;
};

#endif // PANEL_WYSWIETLANIA_REZERWACJI_H
