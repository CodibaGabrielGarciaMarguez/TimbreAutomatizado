#ifndef PERFILES_H
#define PERFILES_H

#include <QWidget>
#include "formularioperfiles.h"

namespace Ui {
class Perfiles;
}

class Perfiles : public QWidget
{
    Q_OBJECT

public:
    explicit Perfiles(QWidget *parent = 0);
    ~Perfiles();

private slots:
    void on_cerrarBtn_clicked();
    void on_retrocederBtn_clicked();
    void on_nuevoBtn_clicked();

private:
    Ui::Perfiles *ui;

    //JSon test
    void writeJson();
    void writeJson(FormularioPerfiles *o, QString filename);
    void readJson();

};

#endif // PERFILES_H
