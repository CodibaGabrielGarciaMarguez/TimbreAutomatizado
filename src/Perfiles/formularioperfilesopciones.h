#ifndef FORMULARIOPERFILESOPCIONES_H
#define FORMULARIOPERFILESOPCIONES_H

#include <QDialog>

namespace Ui {
class FormularioPerfilesOpciones;
}

class FormularioPerfilesOpciones : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioPerfilesOpciones(QWidget *parent = 0);
    ~FormularioPerfilesOpciones();

private:
    Ui::FormularioPerfilesOpciones *ui;
};

#endif // FORMULARIOPERFILESOPCIONES_H
