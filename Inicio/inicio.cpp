#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    this->move(this->geometry().center());
    setFixedSize(width(), height());
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    centrar();

    //test

}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::centrar() {
    QSize availableSize = qApp->desktop()->availableGeometry().size();
    auto widthS = availableSize.width()/2-width()/2;
    auto heightS = availableSize.height()/2-height()/2;
    move(widthS,heightS);
}
