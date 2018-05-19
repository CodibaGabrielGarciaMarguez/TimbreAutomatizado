//
// Created by davixcky_dev on 5/4/18.
//
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include "JsonSerializer.h"

JsonSerializer::JsonSerializer(QString filename, FormularioPerfiles *fp)
        : fn(filename), fp(fp) {

    openFile();

}

JsonSerializer::~JsonSerializer() {
    delete fp;
}

void JsonSerializer::openFile() {
    QDir dirHome = QDir::home();
    if (!dirHome.cd("Documents/TimbreAutomatizado/"))
        dirHome.mkdir("Documents/TimbreAutomatizado/");
    filePath = dirHome.path() + "/" + fn;
}

int JsonSerializer::readJson() {
    qDebug() << "\n______________________________________";
    qDebug() << "\t\tReading json";
    qDebug() << filePath;

    QFile jsonFile(filePath);

    if(!fileVerify(&jsonFile)) return FAIL_OPEN;

    QByteArray jsonFileData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonFileData);
    QJsonObject object = document.object();

    QJsonValue value = object.value("Perfiles");
    QJsonArray array = value.toArray();

    /*foreach(QJsonValue v, array)
        qDebug() << v.toObject().value("Nombre");
*/

    return SUCESS;
}

int JsonSerializer::writeJson() {
    qDebug() << "\n______________________________________";
    qDebug() << "\t\tWriting json";
    qDebug() << filePath;

    QFile jsonFileR(filePath);

    if(!fileVerify(&jsonFileR)) return FAIL_OPEN;

    QByteArray jsonFileData = jsonFileR.readAll();
    jsonFileR.close();

    QJsonDocument document = document.fromJson(jsonFileData);

    auto jsonObject = document.object();
    auto perfiles = jsonObject.value("Perfiles");
    auto arrayPerfiles = perfiles.toArray();

    QJsonObject nuevoPerfil;
    nuevoPerfil.insert("Nombre",fp->nombre());
    QJsonObject e_sObj;
    e_sObj.insert("EntradaHr",fp->hrEntrada());
    e_sObj.insert("SalidaHr",fp->hrSalida());
    nuevoPerfil.insert("E/S",e_sObj);
    QJsonObject clasesObj;
    clasesObj.insert("Nro clases",fp->nHoras());
    clasesObj.insert("TiempoHora",fp->tHoras());
    clasesObj.insert("TiempoReceso",fp->tReceso());
    nuevoPerfil.insert("Clases",clasesObj);
    arrayPerfiles.push_back(nuevoPerfil);
    jsonObject.insert("Perfiles",arrayPerfiles);



    QJsonDocument documentNew(jsonObject);

    QFile jsonFileW(filePath);
    jsonFileW.open(QIODevice::WriteOnly | QIODevice::Text);
    jsonFileW.write(documentNew.toJson());
    jsonFileW.close();

    return SUCESS;
}

int JsonSerializer::updateJson(FormularioPerfiles *fpKey) {
    qDebug() << "\n______________________________________";
    qDebug() << "\t\tEditing object from json";
    qDebug() << filePath;

    QFile jsonFile(filePath);
    if(!fileVerify(&jsonFile)){ return FAIL_OPEN; }

    QByteArray jsonFileData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonFileData);
    
    auto jsonObject = document.object();
    auto perfilesRoot =  jsonObject.value("Perfiles");
    auto arrayPerfiles = perfilesRoot.toArray();

    auto nombre = fpKey->nombre();
    qDebug() << "Nombre fpKey => " << nombre;

    QJsonObject nuevoPerfil;
    nuevoPerfil.insert("Nombre", nombre);
    nuevoPerfil.insert("Editado", true);
    QJsonObject e_sObj;
    e_sObj.insert("EntradaHr",fpKey->hrEntrada());
    e_sObj.insert("SalidaHr",fpKey->hrSalida());
    nuevoPerfil.insert("E/S",e_sObj);
    QJsonObject clasesObj;
    clasesObj.insert("Nro clases",fpKey->nHoras());
    clasesObj.insert("TiempoHora",fpKey->tHoras());
    clasesObj.insert("TiempoReceso",fpKey->tReceso());
    nuevoPerfil.insert("Clases",clasesObj);
    arrayPerfiles.push_back(nuevoPerfil);
    jsonObject.insert("Perfiles",arrayPerfiles);

    QJsonDocument documentNew(jsonObject);

    QFile jsonFileW(filePath);
    jsonFileW.open(QIODevice::WriteOnly | QIODevice::Text);
    jsonFileW.write(documentNew.toJson());
    jsonFileW.close();

}

bool JsonSerializer::fileVerify(QFile *file) {
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text))  return false;
    if(!file->exists()) return false;

    return true;
}

void JsonSerializer::removeObject(const QString key) {
    qDebug() << "\n______________________________________";
    qDebug() << "\t\tRemoving object from json";
    qDebug() << filePath;

    QFile jsonFile(filePath);

    if(!fileVerify(&jsonFile)) return;

    QByteArray jsonFileData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonFileData);
    QJsonObject object = document.object();

    QJsonValue value = object.value("Perfiles");
    QJsonArray array = value.toArray();

    for (int i = 0; i < array.size(); ++i) {
        if(array[i].toObject().value("Nombre") ==  key){
            qDebug() << array[i].toObject().value("Nombre") << " = " << key;
            array.removeAt(i);
        }
    }

    QJsonObject jsonObject = document.object();
    jsonObject.insert("Perfiles",array);
    QJsonDocument documentNew(jsonObject);

    QFile jsonFileW(filePath);
    jsonFileW.open(QIODevice::WriteOnly | QIODevice::Text);
    jsonFileW.write(documentNew.toJson());
    jsonFileW.close();

}

QJsonArray JsonSerializer::obtenerArray() {
    QFile jsonFile(filePath);
    if(!fileVerify(&jsonFile)){ return {}; }

    QJsonDocument document =
            QJsonDocument::fromJson(jsonFile.readAll());
    QJsonObject object = document.object();
    jsonFile.close();

    QJsonValue value = object.value("Perfiles");
    QJsonArray array = value.toArray();

    return array;
}

