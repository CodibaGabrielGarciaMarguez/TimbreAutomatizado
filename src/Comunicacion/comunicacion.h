//
// Created by davixcky_dev on 4/28/18.
//

#ifndef TIMBREAUTOMATIZADO_COMUNICACION_H
#define TIMBREAUTOMATIZADO_COMUNICACION_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>

class Comunicacion {
public:
    explicit Comunicacion();
    ~Comunicacion();

    bool send(const char *n) const;
    bool sendOn(const char *n) const ;
    bool sendOff(const char *n) const ;

private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;

};


#endif //TIMBREAUTOMATIZADO_COMUNICACION_H
