#include <QtWidgets>
#include "perfiles.h"
#include "ui_perfiles.h"
#include <QDesktopWidget>
#include <src/Inicio/inicio.h>
#include "formularioperfiles.h"
#include "JsonSerializer.h"
#include "formularioperfilesopciones.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>

Perfiles::Perfiles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Perfiles)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);

    //Tabla
    ui->tablaW->setColumnCount(6);
    QStringList titulos;
    titulos << "Nombre" << "Hr Entrada" << "Hr Salida" << "Nro Clases"
            << "Tiempo Clases" << "Tiempo Receso";
    ui->tablaW->setHorizontalHeaderLabels(titulos);

    iniciarTabla();

    auto tamDisponible = qApp->desktop()->availableGeometry().size();
    auto anchoD = tamDisponible.width()/2-width()/2;
    auto alturaD = tamDisponible.height()/2-height()/2;
    move(anchoD, alturaD);

    //test
    connect( ui->tablaW, SIGNAL( cellDoubleClicked (int, int) ),
            this, SLOT( opcionesTabla(int, int)) );

    connect(ui->tablaW, SIGNAL( cellChanged(int, int) ),
            this, SLOT( celdaEditada(int, int)) );

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

    if (fp.exec() == QDialog::Rejected){  return;  }

    cargarPerfilesTabla(&fp);
    //jsonSerializer->readJson();

}

void Perfiles::iniciarTabla() {
    qDebug() << "\n______________________________________";
    qDebug() << "\t\tInserting items on table";

    JsonSerializer *jsonSerializer = new JsonSerializer("Perfiles.json");
    QFile file(jsonSerializer->pathJson());
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;
    if(!file.exists()) return;
    auto jsonFileData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonFileData);
    QJsonObject object = document.object();

    QJsonValue jsonValue = object.value("Perfiles");
    QJsonArray jsonArray = jsonValue.toArray();

    ui->tablaW->clear();
    ui->tablaW->clearContents();

    for(QJsonValue value: jsonArray){
        qDebug() << value.toObject().value("Nombre");
        auto perfil = value.toObject();
        auto nombrePerfil = perfil.value("Nombre");

        auto e_sObj = perfil.value("E/S").toObject();
        auto entradaHr = e_sObj.value("EntradaHr");
        auto salidaHr = e_sObj.value("SalidaHr");

        auto clasesObj = perfil.value("Clases").toObject();
        auto nHoras = clasesObj.value("Nro clases");
        auto tHoras = clasesObj.value("TiempoHora");
        auto tReceso = clasesObj.value("TiempoReceso");

        ui->tablaW->insertRow(ui->tablaW->rowCount());
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, NOMBRE,
                            new QTableWidgetItem(nombrePerfil.toString()));
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Hr_Entrada,
                            new QTableWidgetItem(QString::number(entradaHr.toDouble())));
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Hr_Salida,
                            new QTableWidgetItem(QString::number(salidaHr.toDouble())));
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Nro_Clases,
                            new QTableWidgetItem(QString::number(nHoras.toDouble())));
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Tiempo_Clases,
                            new QTableWidgetItem(QString::number(tHoras.toDouble())));
        ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Tiempo_Receso,
                            new QTableWidgetItem(QString::number(tReceso.toDouble())));

    }
}

void Perfiles::cargarPerfilesTabla(FormularioPerfiles *fp) {
    ui->tablaW->insertRow(ui->tablaW->rowCount());
    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, NOMBRE,
                        new QTableWidgetItem(fp->nombre()));

    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Hr_Entrada,
                        new QTableWidgetItem(QString::number(fp->hrEntrada())));

    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Hr_Salida,
                        new QTableWidgetItem(QString::number(fp->hrSalida())));

    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Nro_Clases,
                        new QTableWidgetItem(QString::number(fp->nHoras())));

    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Tiempo_Clases,
                        new QTableWidgetItem(QString::number(fp->tHoras())));

    ui->tablaW->setItem(ui->tablaW->rowCount() - 1, Tiempo_Receso,
                        new QTableWidgetItem(QString::number(fp->tReceso())));

    JsonSerializer *jsonSerializer = new JsonSerializer("Perfiles.json", fp);
    jsonSerializer->writeJson();

}

void Perfiles::testTabla(int nRow, int nCol) {
    QMessageBox::information(this, "",
                             "Cell at row ",QString::number(nRow),
    " column ",QString::number(nCol));
}

void Perfiles::opcionesTabla(int nRow, int nCol) {
    FormularioPerfilesOpciones fp(ui->tablaW, this);
    auto nombreItem =  ui->tablaW->takeItem(nRow, 0)->text();
    fp.setRow(nRow);
    fp.setColumn(nCol);
    ui->tablaW->setItem(nRow, 0,
                        new QTableWidgetItem(nombreItem));
    fp.setWindowTitle(nombreItem);
    fp.exec();
}

void Perfiles::celdaEditada(int nRow, int nCol) {
    qDebug() << "\nFila => " << nRow << " \nColumna => " << nCol;

    //TODO Implementar cambio de valor de celda
}

