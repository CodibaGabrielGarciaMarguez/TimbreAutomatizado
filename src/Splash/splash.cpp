//
// Created by davixcky_dev on 4/21/18.
//

#include <QFileDialog>
#include <QSplashScreen>
#include "splash.h"

Splash::Splash(const QPixmap dirLogo, int t):logo(dirLogo),tiempo(t) {
    splashScreen = new QSplashScreen;
}

Splash::Splash(const int tiempo) {
    this->tiempo = tiempo;
}

Splash::~Splash() {
    delete splashScreen;
}

void Splash::iniciar( QWidget &w) {
    splashScreen->setPixmap(logo);
    splashScreen->show();
    QTimer::singleShot(tiempo,splashScreen,SLOT(close()));
    QTimer::singleShot((tiempo-100),&w,SLOT(show()));
}

void Splash::setLogo(const QPixmap logo) {
    this->logo = logo;
}

void Splash::setTiempo(const int tiempo) {
    this->tiempo = tiempo;
}
