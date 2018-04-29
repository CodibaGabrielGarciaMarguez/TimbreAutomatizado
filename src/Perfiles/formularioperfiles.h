#ifndef FORMULARIOPERFILES_H
#define FORMULARIOPERFILES_H

#include <QDialog>

namespace Ui {
class FormularioPerfiles;
}

class FormularioPerfiles : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioPerfiles(QWidget *parent = 0);
    ~FormularioPerfiles();

private:
    Ui::FormularioPerfiles *ui;
};

#endif // FORMULARIOPERFILES_H
