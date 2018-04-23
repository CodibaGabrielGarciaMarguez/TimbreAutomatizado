//
// Created by davixcky_dev on 4/21/18.
//

#ifndef TIMBREAUTOMATIZADO_SPLASH_H
#define TIMBREAUTOMATIZADO_SPLASH_H

#include <QSplashScreen>
#include <QTimer>
#include <QString>
#include <QDebug>

class Splash {
public:
    explicit Splash(QPixmap dirLogo,  int t);
    explicit Splash(const int tiempo);
    ~Splash();

    void iniciar( QWidget &w);
    void setLogo(const QPixmap logo);
    void setTiempo(const int tiempo);

    //Test
private:
    QSplashScreen *splashScreen;
    QPixmap logo;
    int tiempo;


};


#endif //TIMBREAUTOMATIZADO_SPLASH_H
