#include <iostream>
#include "matricekalk.h"
#include "../Parte_logica/matrice.h"
#include <QApplication>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MatriceKalk fin;
    fin.show();
    return a.exec();
}
