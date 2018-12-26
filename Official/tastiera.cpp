#include "tastiera.h"
#include<QGridLayout>
#include<QPushButton>

Tastiera::Tastiera(Matrice_Input* mm, QWidget* parent): mi(mm), QWidget(parent)
{
    QVBoxLayout* final= new QVBoxLayout();
    QGridLayout* gridel= new QGridLayout();
    QGridLayout* gridin= new QGridLayout();
    QGridLayout* gridvt= new QGridLayout();

    QPushButton* trasp= new QPushButton("Trasposta",this);
    QPushButton* pow= new QPushButton("Potenza X",this);
    QPushButton* norm= new QPushButton("Norma Euclidea",this);
    QPushButton* scal= new QPushButton("Gauss",this);


    gridel->addWidget(pow,0,0);

    gridin->addWidget(trasp,0,0);
    gridin->addWidget(scal,1,0);

    gridvt->addWidget(norm,0,0);

    connect(trasp,SIGNAL(released()),mm,SLOT(trasposta()));
    connect(scal,SIGNAL(released()),mm,SLOT(scala()));
    connect(pow,SIGNAL(released()),this,SLOT(sendpowX()));
    connect(norm,SIGNAL(released()),mm,SLOT(norm()));

    connect(this,SIGNAL(powX(double )),mm,SLOT(powX(double )));

    QLabel* elem= new QLabel("Operazioni sui singoli elementi");
    QLabel* inte= new QLabel("Operazioni sull' intera matrice");
    QLabel* vett= new QLabel("Operazioni sui vettori");

    QHBoxLayout* xcount= new QHBoxLayout();
    QLabel* val= new QLabel("Valore X",this);
    x=new QLineEdit("0",this);
    x->setValidator(new QDoubleValidator(x));
    xcount->addWidget(val);
    xcount->addWidget(x);

    final->addWidget(elem);
    final->addLayout(gridel);
    final->addLayout(xcount);
    final->addWidget(inte);
    final->addLayout(gridin);
    final->addWidget(vett);
    final->addLayout(gridvt);
    setLayout(final);
}

void Tastiera::sendpowX(){
    emit powX(x->text().toDouble());
}
