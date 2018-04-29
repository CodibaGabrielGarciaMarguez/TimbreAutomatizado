#include <src/Inicio/inicio.h>
#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
    auto tamDisponible = qApp->desktop()->availableGeometry().size();
    auto anchoD = tamDisponible.width()/2-width()/2;
    auto alturaD = tamDisponible.height()/2-height()/2;
    move(anchoD, alturaD);

}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_retrocederBtn_clicked() {
    auto inicio = new Inicio();
    close();
    inicio->show();
}

