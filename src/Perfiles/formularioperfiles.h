#ifndef FORMULARIOPERFILES_H
#define FORMULARIOPERFILES_H

#include <QDialog>

namespace Ui {
class FormularioPerfiles;
}

class FormularioPerfiles : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioPerfiles(QWidget *parent = 0);
    ~FormularioPerfiles();

    void editarFormulario(const QString key,
                          const QString filename = "Perfiles.json");

    QString nombre() const;
    double hrSalida() const;
    double hrEntrada() const;
    int nHoras() const;
    double tReceso() const;
    double tHoras() const;


private slots:
    void on_confirmar_accepted();
    void on_confirmar_rejected();

    //void llenarDesdeJson();

private:
    Ui::FormularioPerfiles *ui;


};

#endif // FORMULARIOPERFILES_H
