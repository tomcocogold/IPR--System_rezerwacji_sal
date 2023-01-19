#ifndef PANEL_LOGOWANIA_H
#define PANEL_LOGOWANIA_H

#include <QWidget>

namespace Ui {
class Okno_logowania;
}

class Okno_logowania : public QWidget
{
    Q_OBJECT

public:
    explicit Okno_logowania(QWidget *parent = nullptr);
    ~Okno_logowania();

private:
    Ui::Okno_logowania *ui;
};

#endif // PANEL_LOGOWANIA_H
