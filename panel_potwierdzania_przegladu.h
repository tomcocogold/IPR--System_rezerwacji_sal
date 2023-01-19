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

private:
    Ui::Panel_potwierdzania_przegladu *ui;
};

#endif // PANEL_POTWIERDZANIA_PRZEGLADU_H
