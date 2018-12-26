#ifndef MATRICEKALK_H
#define MATRICEKALK_H

#include <QWidget>
#include "matricekalk.h"
#include "../Parte_logica/matrice.h"
#include <QString>
#include "matrice_input.h"



class MatriceKalk : public QWidget
{
    Q_OBJECT

private:
    Matrice_Input* princ;
    Matrice_Input* due;
public:
    explicit MatriceKalk(QWidget*parent=nullptr);

signals:

public slots:
    void somma();
    void diff();
    void molt();
    void copy();
    void copy1();
};

#endif // MATRICEKALK_H
