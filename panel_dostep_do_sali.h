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

private:
    Ui::Panel_dostep_do_sali *ui;
};

#endif // PANEL_DOSTEP_DO_SALI_H
