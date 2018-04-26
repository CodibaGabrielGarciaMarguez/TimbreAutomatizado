#include <QApplication>
#include <QIcon>
#include "Inicio/inicio.h"
#include "Splash/splash.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Splash miSplash(QPixmap(":/new/prefix1/resource/index.png"),
                        100); //Test

    Inicio inicio;
    miSplash.iniciar(inicio);
    inicio.setWindowIcon(QPixmap(":new/prefix1/resource/icono.png"));

    return app.exec();
}

//Funciona