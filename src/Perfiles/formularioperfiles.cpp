#include "formularioperfiles.h"
#include "ui_formularioperfiles.h"

FormularioPerfiles::FormularioPerfiles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormularioPerfiles)
{
    ui->setupUi(this);
}

FormularioPerfiles::~FormularioPerfiles()
{
    delete ui;
}
