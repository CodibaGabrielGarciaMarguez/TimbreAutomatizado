//
// Created by davixcky_dev on 5/4/18.
//

#ifndef TIMBREAUTOMATIZADO_JSONSERIALIZER_H
#define TIMBREAUTOMATIZADO_JSONSERIALIZER_H


#include <QString>
#include <QFile>
#include "formularioperfiles.h"

class JsonSerializer {
public:
    JsonSerializer(QString filename, FormularioPerfiles *fp);
    ~JsonSerializer();

    int writeJson();
    int readJson();

    enum State{
        SUCESS, FAIL, FAIL_OPEN
    };

private:
    QString fn;
    FormularioPerfiles *fp;
    QString filePath;

    void openFile();
    bool fileVerify(QFile *file);


};


#endif //TIMBREAUTOMATIZADO_JSONSERIALIZER_H
