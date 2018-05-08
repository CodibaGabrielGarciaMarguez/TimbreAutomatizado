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

QString FormularioPerfiles::nombre() const {
    return ui->nombre->text();
}

double FormularioPerfiles::hrSalida() const {
    return ui->hrSalida->value();
}

double FormularioPerfiles::hrEntrada() const {
    return ui->hrEntrada->value();
}

int FormularioPerfiles::nHoras() const {
    return ui->nHoras->value();
}

double FormularioPerfiles::tReceso() const {
    return ui->tReceso->value();
}

double FormularioPerfiles::tHoras() const {
    return ui->tPorHora->value();
}

void FormularioPerfiles::on_confirmar_accepted() {
    accept();
}

void FormularioPerfiles::on_confirmar_rejected() {
    reject();
}
 //TODO Validar formulario