#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include <QApplication>
#include <QSize>
#include <QDesktopWidget>
#include <src/Manual/manual.h>
#include <src/Perfiles/perfiles.h>

namespace Ui {
class Inicio;
}

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = 0);
    ~Inicio();

private slots:
    void on_closeBtn_clicked();
    void on_manualBtn_clicked();
    void on_perfilesBtn_clicked();
    void on_configuracionBtn_clicked();

private:
    Ui::Inicio *ui;
    Manual *manual;
    Perfiles *perfiles;
};

#endif // INICIO_H
