#ifndef PANEL_LOGOWANIA_H
#define PANEL_LOGOWANIA_H

#include <QWidget>

namespace Ui {
class Panel_logowania;
}

class Panel_logowania : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_logowania(QWidget *parent = nullptr);
    ~Panel_logowania();

signals:
    void zaloguj();
    void zaktualizuj_dane();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Panel_logowania *ui;
};

#endif // PANEL_LOGOWANIA_H
