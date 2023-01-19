#ifndef PANEL_TECHNIKA_H
#define PANEL_TECHNIKA_H

#include <QWidget>

namespace Ui {
class Panel_technika;
}

class Panel_technika : public QWidget
{
    Q_OBJECT

public:
    explicit Panel_technika(QWidget *parent = nullptr);
    ~Panel_technika();

private:
    Ui::Panel_technika *ui;
};

#endif // PANEL_TECHNIKA_H
