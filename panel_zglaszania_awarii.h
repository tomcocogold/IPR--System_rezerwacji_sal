#ifndef PANEL_ZGLASZANIA_AWARII_H
#define PANEL_ZGLASZANIA_AWARII_H

#include <QWidget>

namespace Ui {
class Panel_zglaszania_awarii;
}

class Panel_zglaszania_awarii : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_zglaszania_awarii(QWidget *parent = nullptr);
    ~Panel_zglaszania_awarii();

signals:
    void wroc();
    void przejdz_do_okna_dialogowego();

private slots:
    void on_wroc_clicked();

    void on_zglos_awarie_clicked();

private:
    Ui::Panel_zglaszania_awarii *ui;
};

#endif // PANEL_ZGLASZANIA_AWARII_H
