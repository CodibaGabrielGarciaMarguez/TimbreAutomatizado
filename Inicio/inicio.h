#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <QApplication>
#include <QSize>
#include <QDesktopWidget>

namespace Ui {
class Inicio;
}

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();


private:
    void centrar();

    Ui::Inicio *ui;
};

/*
void Widget::moveToCenter()
{
    move(qApp->desktop()->availableGeometry(this).center()-rect().center());
}
*/

#endif // INICIO_H
