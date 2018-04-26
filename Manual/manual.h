#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include <Inicio/inicio.h>
#include <QDesktopWidget>
#include <Inicio/inicio.h>

namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = 0);
    ~Manual();

private slots:
    void on_cerrarBtn_clicked();
    void on_retrocederBtn_clicked();
    void on_timbreBtn_clicked();

private:
    Ui::Manual *ui;
    Inicio *inicio;

};

#endif // MANUAL_H
