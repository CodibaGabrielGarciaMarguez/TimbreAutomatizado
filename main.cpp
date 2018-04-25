#include <QApplication>
#include <Inicio/inicio.h>
#include "Splash/splash.h"
#include <QDesktopWidget>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Splash miSplash(QPixmap(":/new/prefix1/resource/index.png"),
                        5500);

    Inicio inicio;
    miSplash.iniciar(inicio);
    inicio.setWindowIcon(QPixmap(":new/prefix1/resource/icono.png"));

    /*QSize availableSize = qApp->desktop()->availableGeometry().size();
    auto width = availableSize.width()/2-inicio.width()/2;
    auto height = availableSize.height()/2-inicio.height()/2;
    inicio.move(width,height);*/

    return app.exec();
}
