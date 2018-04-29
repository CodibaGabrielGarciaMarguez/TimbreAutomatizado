#include <src/Configuracion/configuracion.h>
#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    auto tamDisponible = qApp->desktop()->availableGeometry().size();
    auto anchoD = tamDisponible.width()/2-width()/2;
    auto alturaD = tamDisponible.height()/2-height()/2;
    move(anchoD, alturaD);
}

Inicio::~Inicio(){
    delete ui;
    delete manual;
}

void Inicio::on_closeBtn_clicked(){
    //TODO Confirmar salida del programa
    close();
}

void Inicio::on_manualBtn_clicked() {
    //TODO Implentar boton manual
    manual = new Manual(this);
    close();
    manual->show();
}

void Inicio::on_perfilesBtn_clicked() {
    //TODO Implentar boton perfiles
    perfiles = new Perfiles(this);
    close();
    perfiles->show();
}

void Inicio::on_configuracionBtn_clicked() {
    //TODO Implentar boton configuracion
    auto config = new Configuracion();
    close();
    config->show();
}
