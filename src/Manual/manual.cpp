#include "manual.h"
#include "ui_manual.h"
#include "Inicio/inicio.h"

Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);

    //Centrar widget
    auto tamDisponible = qApp->desktop()->availableGeometry().size();
    auto anchoD = tamDisponible.width()/2-width()/2;
    auto alturaD = tamDisponible.height()/2-height()/2;
    move(anchoD,alturaD);
}

Manual::~Manual()
{
    delete ui;
}

void Manual::on_cerrarBtn_clicked() {
    //TODO Implementar cerrado
    close();
}

void Manual::on_retrocederBtn_clicked() {
    //TODO Implementar retroceder
    auto inicio = new Inicio();
    close();
    inicio->show();
}

void Manual::on_timbreBtn_clicked() {
    //TODO Cambiar imagen (Si esta presionado _btnOn sino _btnOff )
}

