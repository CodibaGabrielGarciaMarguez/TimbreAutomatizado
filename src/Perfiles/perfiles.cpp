#include <QtWidgets>
#include "perfiles.h"
#include "ui_perfiles.h"
#include <QDesktopWidget>
#include <Inicio/inicio.h>

Perfiles::Perfiles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Perfiles)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    auto tamDisponible = qApp->desktop()->availableGeometry().size();
    auto anchoD = tamDisponible.width()/2-width()/2;
    auto alturaD = tamDisponible.height()/2-height()/2;
    move(anchoD, alturaD);
}

Perfiles::~Perfiles()
{
    delete ui;
}

void Perfiles::on_cerrarBtn_clicked() {
    //TODO Implementar confirmacion
    close();
}

void Perfiles::on_retrocederBtn_clicked() {
    auto inicio = new Inicio();
    close();
    inicio->show();
}
