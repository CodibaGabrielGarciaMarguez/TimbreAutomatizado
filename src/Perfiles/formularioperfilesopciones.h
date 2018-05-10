#ifndef FORMULARIOPERFILESOPCIONES_H
#define FORMULARIOPERFILESOPCIONES_H

#include <QDialog>
#include <QTableWidget>
#include <QDebug>

namespace Ui {
class FormularioPerfilesOpciones;
}

class FormularioPerfilesOpciones : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioPerfilesOpciones(QTableWidget *tableWidget, QWidget *parent = 0);
    ~FormularioPerfilesOpciones();

    void setColumn(int nCol);
    void setRow(int nRow);

private slots:
    void on_editarBtn_clicked();
    void on_eliminarBtn_clicked();
    void on_seleccionarBtn_clicked();

    inline bool celdaVacia() { return true; }

private:
    Ui::FormularioPerfilesOpciones *ui;
    QTableWidget *tableWidget;
    int nRow, nCol;
};

#endif // FORMULARIOPERFILESOPCIONES_H
