#include <QtWidgets>
#include "perfiles.h"
#include "ui_perfiles.h"
#include <QDesktopWidget>
#include <src/Inicio/inicio.h>
#include "formularioperfiles.h"

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

void Perfiles::on_nuevoBtn_clicked(){
    FormularioPerfiles fp(this);
    auto res = fp.exec();

    if (res == QDialog::Rejected){
        return;
    }

    auto nombre = fp.nombre();

    //TODO json
    writeJson();

}

void Perfiles::writeJson() {
    QJsonObject recordObject;
    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
    recordObject.insert("Age", QJsonValue::fromVariant(43));

    QJsonObject addressObject;
    addressObject.insert("Street", "Downing Street 10");
    addressObject.insert("City", "London");
    addressObject.insert("Country", "Great Britain");
    recordObject.insert("Address", addressObject);

    QJsonArray phoneNumbersArray;
    phoneNumbersArray.push_back("+44 1234567");
    phoneNumbersArray.push_back("+44 2345678");
    recordObject.insert("Phone Numbers", phoneNumbersArray);

    QJsonDocument doc(recordObject);
    qDebug() << doc.toJson();
}