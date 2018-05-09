#ifndef PERFILES_H
#define PERFILES_H

#include <QWidget>
#include <QTableWidgetItem>
#include "formularioperfiles.h"
#include "JsonSerializer.h"

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

    void testTabla(int nRow, int nCol);
    void opcionesTabla(int nRow, int nCol);
    void celdaEditada(int nRow, int nCol);

private:
    Ui::Perfiles *ui;

    void cargarPerfilesTabla(FormularioPerfiles *o);
    void iniciarTabla();

    //Tabla
    enum Columna {
        NOMBRE,
        Hr_Entrada, Hr_Salida,                  //E/S
        Nro_Clases,Tiempo_Clases,Tiempo_Receso  //Clases
    };

};

#endif // PERFILES_H
