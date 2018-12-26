#include "matricekalk.h"
#include "matrice_input.h"
#include "../Parte_logica/matrice.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>

MatriceKalk::MatriceKalk(QWidget*parent) : QWidget(parent)
{
    setWindowTitle ("Official");
    QWidget* x=new Matrice_Input(4,4);
    QWidget* y=new Matrice_Input(4,4);

    princ= dynamic_cast<Matrice_Input*>(x);
    due =dynamic_cast<Matrice_Input*>(y);

    QVBoxLayout* tasti=new QVBoxLayout();

    QPushButton* somma= new QPushButton("Somma",this);
    QPushButton* diff=new QPushButton("Differenza",this);
    QPushButton* molt= new QPushButton("Moltiplicazione",this);
    QPushButton* copy= new QPushButton("->Copia->",this);
    QPushButton* copy1= new QPushButton("<-Copia<-",this);

    connect(somma,SIGNAL(released()),this,SLOT(somma()));
    connect(diff,SIGNAL(released()),this,SLOT(diff()));
    connect(molt,SIGNAL(released()),this,SLOT(molt()));
    connect(copy,SIGNAL(released()),this,SLOT(copy()));
    connect(copy1,SIGNAL(released()),this,SLOT(copy1()));

    tasti->addWidget(somma);
    tasti->addWidget(diff);
    tasti->addWidget(molt);
    tasti->addWidget(copy);
    tasti->addWidget(copy1);

    QHBoxLayout* b=new QHBoxLayout();
    b->addWidget(x);
    b->addLayout(tasti);
    b->addWidget(y);

    setLayout(b);
};


void MatriceKalk::somma(){
    if((*(princ->getMat())).stesseDim(*(due->getMat()))){
        *(princ->getMat())=*(princ->getMat()) + *(due->getMat());
        princ->upMat();
    }
    else{Matrice_Input::warning("Non puoi sommare due matrici con dimensioni diverse");}
}


void MatriceKalk::diff(){
    if((*(princ->getMat())).stesseDim(*(due->getMat()))){
        *(princ->getMat())=*(princ->getMat()) - *(due->getMat());
        princ->upMat();
    }
    else{Matrice_Input::warning("Non puoi fare la differenza fra due matrici con dimensioni diverse");}
}


void MatriceKalk::molt(){
    if((princ->getMat())->stesseDim(*(due->getMat()))){
        if((princ->getMat())->uguali(*(due->getMat())))
        {
        *(princ->getMat())=(*(princ->getMat())) * (*(due->getMat()));
        matrice<double> cp=*(princ->getMat());
        princ->newMat(princ->getMat()->getH(),princ->getMat()->getL());
        *(princ->getMat())=cp;
        princ->upMat();}
        else{{Matrice_Input::warning("Le matrici devono essere quadrate");}}
    }
    else{Matrice_Input::warning("La dimensione delle matrici devono essere uguali");}
}

void MatriceKalk::copy(){
    due->newMat((*(princ->getMat())).getH(),((*(princ->getMat())).getL()));
    *(due->getMat())=*(princ->getMat());
    due->upMat();
}

void MatriceKalk::copy1(){
    princ->newMat(((*(due->getMat()))).getH(),(*(due->getMat())).getL());
    *(princ->getMat())=*(due->getMat());
    princ->upMat();
}



