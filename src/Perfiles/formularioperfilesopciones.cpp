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
    qDebug() << "\nEditando perfil #" << nRow;
    FormularioPerfiles fp(this);

    auto nombre = tableWidget->item(nRow, 0)->text();
    fp.setWindowTitle("Editando [" + nombre + "]");

    fp.editarFormulario(nombre);
    if (fp.exec() == QDialog::Rejected) { return; }

    auto jsonSerializer = new JsonSerializer("Perfiles.json", &fp);
    jsonSerializer->removeObject(nombre);
    tableWidget->removeRow(nRow);
    jsonSerializer->updateJson(&fp);
    actualizarTabla(&fp);


    //cargar json nuevamente a la tabla


}

void FormularioPerfilesOpciones::on_eliminarBtn_clicked() {
    qDebug() << "\nEliminando fila #" << nRow;
    qDebug() << "Eliminando columna #" << nCol;

    auto item = tableWidget->item(nRow, 0);

    JsonSerializer *jsonSerializer = new JsonSerializer("Perfiles.json");
    jsonSerializer->removeObject(item->text());
    tableWidget->removeRow(nRow);

    if(celdaVacia()) { close(); }

}

void FormularioPerfilesOpciones::on_seleccionarBtn_clicked() {

}

void FormularioPerfilesOpciones::setColumn(int nCol) {
    this->nCol = nCol;
}

void FormularioPerfilesOpciones::setRow(int nRow) {
    this->nRow = nRow;
}

void FormularioPerfilesOpciones::actualizarTabla(FormularioPerfiles *fp) {
    tableWidget->insertRow(tableWidget->rowCount());
    tableWidget->setItem(tableWidget->rowCount() - 1, NOMBRE,
                         new QTableWidgetItem(fp->nombre()));

    tableWidget->setItem(tableWidget->rowCount() - 1, Hr_Entrada,
                         new QTableWidgetItem(QString::number(fp->hrEntrada())));

    tableWidget->setItem(tableWidget->rowCount() - 1, Hr_Salida,
                         new QTableWidgetItem(QString::number(fp->hrSalida())));

    tableWidget->setItem(tableWidget->rowCount() - 1, Nro_Clases,
                         new QTableWidgetItem(QString::number(fp->nHoras())));

    tableWidget->setItem(tableWidget->rowCount() - 1, Tiempo_Clases,
                         new QTableWidgetItem(QString::number(fp->tHoras())));

    tableWidget->setItem(tableWidget->rowCount() - 1, Tiempo_Receso,
                         new QTableWidgetItem(QString::number(fp->tReceso())));

    //JsonSerializer *jsonSerializer = new JsonSerializer("Perfiles.json", fp);
    //jsonSerializer->writeJson();
}
