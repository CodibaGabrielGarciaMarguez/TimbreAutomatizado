//
// Created by davixcky_dev on 4/28/18.
//

#include <iostream>

#include "comunicacion.h"

Comunicacion::Comunicacion() {
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;
 //   arduino->setPort(QSerialPortInfo);

  /*  qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if (serialPortInfo.hasProductIdentifier()) {
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }*/

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            arduino_port_name = serialPortInfo.portName();
            arduino_is_available = true;
        }
    }

    if (arduino_is_available) {
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        qDebug() << "Arduino info => " << arduino->portName();
    } else {
        // give error message if not available
        QMessageBox::warning(nullptr, "Port error", "Couldn't find the Arduino!");
    }

}

Comunicacion::~Comunicacion() {
    arduino->clear();
    arduino->close();
    std::cout << "\n Destructor comunicacion... \n";
    delete arduino;
}

bool Comunicacion::sendOn(const char *n) const {
    if (arduino->isWritable()) {
        arduino->write("1");
    } else {
        qDebug() << arduino->error();
        qDebug() << arduino->errorString().toHtmlEscaped();
        qDebug() << "Couldn't write to serial!";
    }
}

bool Comunicacion::sendOff(const char *n) const {
    if (arduino->isWritable()) {
        arduino->write("0");
    } else {
        qDebug() << arduino->error();
        qDebug() << arduino->errorString();
        qDebug() << "Couldn't write to serial!";
    }
}

bool Comunicacion::send(const char *n) const {
    if (arduino->isWritable()) {
        arduino->write(n);
    } else {
        std::cout << arduino->errorString().toStdString();
        qDebug() << "Couldn't write to serial!";
    }
}
