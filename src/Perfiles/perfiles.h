#ifndef PERFILES_H
#define PERFILES_H

#include <QWidget>

namespace Ui {
class Perfiles;
}

class Perfiles : public QWidget
{
    Q_OBJECT

public:
    explicit Perfiles(QWidget *parent = 0);
    ~Perfiles();

private slots:
    void on_cerrarBtn_clicked();
    void on_retrocederBtn_clicked();

private:
    Ui::Perfiles *ui;
};

#endif // PERFILES_H
