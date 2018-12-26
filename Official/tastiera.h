#ifndef TASTIERA_H
#define TASTIERA_H

#include"matrice_input.h"
#include<QWidget>
#include<QLineEdit>

class Matrice_Input;

class Tastiera : public QWidget
{
    Q_OBJECT
private:
    Matrice_Input* mi;
    QLineEdit* x;
public:
    explicit Tastiera(Matrice_Input* mm, QWidget* parent=nullptr);

signals:

    void powX(double d);

public slots:
    void sendpowX();

};

#endif // TASTIERA_H
