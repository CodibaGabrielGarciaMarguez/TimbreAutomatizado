#include "formularioperfilesopciones.h"
#include "ui_formularioperfilesopciones.h"

FormularioPerfilesOpciones::FormularioPerfilesOpciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormularioPerfilesOpciones)
{
    ui->setupUi(this);
}

FormularioPerfilesOpciones::~FormularioPerfilesOpciones()
{
    delete ui;
}
