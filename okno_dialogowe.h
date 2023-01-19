#ifndef OKNO_DIALOGOWE_H
#define OKNO_DIALOGOWE_H

#include <QWidget>

namespace Ui {
class okno_dialogowe;
}

class okno_dialogowe : public QWidget
{
    Q_OBJECT

public:
    explicit okno_dialogowe(QWidget *parent = nullptr);
    ~okno_dialogowe();

private:
    Ui::okno_dialogowe *ui;
};

#endif // OKNO_DIALOGOWE_H
