//
// Created by davixcky_dev on 5/4/18.
//

#ifndef TIMBREAUTOMATIZADO_JSONSERIALIZER_H
#define TIMBREAUTOMATIZADO_JSONSERIALIZER_H


#include <QString>
#include <QFile>
#include <QString>
#include "formularioperfiles.h"

class JsonSerializer {
public:
    JsonSerializer(QString filename, FormularioPerfiles *fp = nullptr);
    ~JsonSerializer();

    int writeJson();
    int readJson();
    inline QString pathJson(){ return  filePath; }

    void removeObject(const QString key);

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
