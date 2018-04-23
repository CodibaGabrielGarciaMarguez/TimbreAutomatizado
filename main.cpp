#include <QApplication>
#include <Inicio/inicio.h>
#include "Splash/splash.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Splash miSplash(QPixmap(":/new/prefix1/resource/index.png"),
                        5500);

    Inicio inicio;
    miSplash.iniciar(inicio);

    return a.exec();

}
