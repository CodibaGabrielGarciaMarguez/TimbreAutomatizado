//
// Created by davixcky_dev on 4/28/18.
//

#ifndef TIMBREAUTOMATIZADO_COMUNICACION_H
#define TIMBREAUTOMATIZADO_COMUNICACION_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Comunicacion {
public:
    explicit Comunicacion();
    ~Comunicacion();

private:
    QSerialPort *puertoSerial;
    QSerialPortInfo *infoPuertoSerial;

};


#endif //TIMBREAUTOMATIZADO_COMUNICACION_H
