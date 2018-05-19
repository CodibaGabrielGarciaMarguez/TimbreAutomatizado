#include <QJsonArray>
#include <QJsonObject>
#include "JsonSerializer.h"
#include "formularioperfiles.h"
#include "ui_formularioperfiles.h"
#include <QDir>
#include <QJsonDocument>
#include <QDebug>

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

void FormularioPerfiles::editarFormulario(
        const QString key,
        const QString filename) {

    auto jsonSerializer = new JsonSerializer(filename);
    auto array = jsonSerializer->obtenerArray();

    QJsonObject object;
    for (auto v: array) {
        if (v.toObject().value("Nombre") == key) {
            object = v.toObject();
            break;
        }
    }

    ui->nombre->setText(object.value("Nombre").toString());
    //E/S
    auto e_sObj = object.value("E/S").toObject();
    ui->hrEntrada->setValue(e_sObj.value("EntradaHr").toDouble());
    ui->hrSalida->setValue(e_sObj.value("SalidaHr").toDouble());
    //Clases
    auto clasesObj = object.value("Clases").toObject();
    ui->tPorHora->setValue(clasesObj.value("TiempoHora").toDouble());
    ui->nHoras->setValue(clasesObj.value("Nro clases").toInt());
    ui->tReceso->setValue(clasesObj.value("TiempoReceso").toDouble());

}