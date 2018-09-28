#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include <QDesktopWidget>
#include <src/Comunicacion/comunicacion.h>

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
    void on_timbreBtn_clicked();
    void on_retrocederBtn_clicked();
    void on_apagarBtn_clicked();


private:
    Ui::Manual *ui;
    Comunicacion *comunicacion;

};

#endif // MANUAL_H
