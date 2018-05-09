#include "formularioperfilesopciones.h"
#include "ui_formularioperfilesopciones.h"
#include "JsonSerializer.h"

FormularioPerfilesOpciones::FormularioPerfilesOpciones(QTableWidget *tableWidget,QWidget *parent) :
    QDialog(parent),
    tableWidget(tableWidget),
    ui(new Ui::FormularioPerfilesOpciones)
{
    ui->setupUi(this);

    connect(tableWidget, SIGNAL(cellChanged(int, int)),
            this, SLOT(celdaVacia()));

}


FormularioPerfilesOpciones::~FormularioPerfilesOpciones()
{
    delete ui;
}

void FormularioPerfilesOpciones::on_editarBtn_clicked() {

}

void FormularioPerfilesOpciones::on_eliminarBtn_clicked() {
    qDebug() << "\nEliminando fila #" << nRow;
    tableWidget->removeRow(0);

    JsonSerializer *jsonSerializer = new JsonSerializer("Perfiles.json");
    jsonSerializer->removeObject();

    if(celdaVacia()) close;

}

void FormularioPerfilesOpciones::on_seleccionarBtn_clicked() {

}

void FormularioPerfilesOpciones::setColumn(int nCol) {
    this->nCol = nCol;
}

void FormularioPerfilesOpciones::setRow(int nRow) {
    this->nRow = nRow;
}

bool FormularioPerfilesOpciones::celdaVacia() {
    return true;
}