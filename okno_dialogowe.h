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
    void wypelnij_panel_technika();

private slots:
    void on_dialogButtonBox_rejected();

    void on_dialogButtonBox_accepted();

private:
    Ui::Okno_dialogowe *ui;
};

#endif // OKNO_DIALOGOWE_H
