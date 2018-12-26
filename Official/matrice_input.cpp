#include "matrice_input.h"
#include "../Parte_logica/matrice.h"
#include "../Parte_logica/square_matrice.h"
#include "../Parte_logica/diagonal_matrice.h"
#include "../Parte_logica/vector.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QItemDelegate>
#include <QLineEdit>
#include <QValidator>
#include "math.h"
#include <QString>
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>
class Delegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const{
        QLineEdit* lineEdit= new QLineEdit(parent);

        QDoubleValidator * validator= new QDoubleValidator(parent);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};




Matrice_Input::Matrice_Input(int r, int c, QWidget *parent): QWidget(parent)
{

    mat=0;
    tab=0;
    tast=new Tastiera(this);

    QHBoxLayout* size= new QHBoxLayout();

    QLabel* righe= new QLabel("Righe",this);
    QLabel* colo= new QLabel("Colonne",this);
    tipo= new QLabel(this);

    QPushButton* piuRow= new QPushButton("+",this);
    QPushButton* menoRow= new QPushButton("-",this);
    QPushButton* piuCol= new QPushButton("+",this);
    QPushButton* menoCol= new QPushButton("-",this);

    connect(piuRow,SIGNAL(released()),this,SLOT(plusRow()));
    connect(menoRow,SIGNAL(released()),this,SLOT(minRow()));
    connect(piuCol,SIGNAL(released()),this,SLOT(plusColumns()));
    connect(menoCol,SIGNAL(released()),this,SLOT(minColumns()));

    size->addWidget(righe);
    size->addWidget(menoRow);
    size->addWidget(piuRow);
    size->addWidget(colo);
    size->addWidget(menoCol);
    size->addWidget(piuCol);

    newMat(r,c);
    det=new QLabel(detText(),this);
     connect(tab,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(model(QTableWidgetItem*)));

     QHeaderView* oriz= new QHeaderView(Qt::Horizontal,tab);
     QHeaderView* vert= new QHeaderView(Qt::Vertical,tab);
     oriz->setSectionResizeMode(QHeaderView::Stretch);
     vert->setSectionResizeMode(QHeaderView::Stretch);
     tab->setHorizontalHeader(oriz);
     tab->setVerticalHeader(vert);

     QVBoxLayout* lay= new QVBoxLayout(this);
     lay->addLayout(size);
     lay->addWidget(tipo);
     lay->addWidget(tab);
     lay->addWidget(det);
     lay->addWidget(tast);
     setLayout(lay);

     tipo->setText(tipoText());

}

void Matrice_Input::scala(){

        mat->scalini();
        matrice<double> cp=*mat;
        newMat(mat->getH(),mat->getL());
        *mat=cp;
        upMat();

}

matrice<double>* Matrice_Input::getMat() const{
    return mat;
}

void Matrice_Input::upMat(){
    tab->clear();
    for(int r=0;r<mat->getH();r++)
    {
        for(int c=0;c<mat->getL();c++)
        {
            tab->setItem(r,c,new QTableWidgetItem(QString::number((*mat)[r*mat->getL()+c])));
        }
    }
}


void Matrice_Input::trasposta(){
    mat->Trasposta();
    matrice<double> cp=*mat;
    newMat(mat->getH(),mat->getL());
    *mat=cp;
    upMat();
}

void Matrice_Input::newMat(int r,int c){
    if(!tab)
    {
     tab=new QTableWidget(this);
     tab->setItemDelegate(new Delegate);
    }

    if(mat)
        delete mat;

    mat= new matrice<double>(r,c);
    mat->Fill(0);
    tabRes(mat->getH(),mat->getL());
    upMat();


}

void Matrice_Input::tabRes(int h, int l){
    tab->setRowCount(h);
    tab->setColumnCount(l);
}

void Matrice_Input::powX(double d){
    mat->eleva(d);
    upMat();
}

/*void Matrice_Input::Molti(double d){
    mat=*mat*d;
    upMat();
}*/



void Matrice_Input::norm(){
    vector<double>*p=dynamic_cast<vector <double>*>(mat);
    if(p)
    {
        vector<double> v=*p;
        v.Fill(0);
        if(!(v==*p))
        {
            p->Normalize();
            upMat();
        }else{warning("Non puoi normalizzare lo zero");}
    }else
        warning("La matrice che vuoi normalizzare non è un vettore");
}


void Matrice_Input::warning(const QString &qs){
    QMessageBox msn;
    msn.setText(qs);
    msn.exec();
}

void Matrice_Input::matResize(int r, int c){
    if(r>0)
    {
        matrice<double> temp(r,mat->getL());
        temp.Fill(0);
        mat->Appendriga(temp);
    }
    else if(r<0)
    {
        mat->Cut(0,mat->getH()+r,0,mat->getL());
    }

    if(c>0)
    {
        matrice<double> temp(mat->getH(),c);
        temp.Fill(0);
        mat->Appendcol(temp);
    }
    else if(c<0)
    {
        mat->Cut(0,mat->getH(),0,mat->getL()+c);
    }

    rectify();
    tabRes(mat->getH(),mat->getL());
    upMat();
}

void Matrice_Input::plusRow(){
    if(mat->getH()<50)
    {matResize(1,0);}
}

void Matrice_Input::minRow(){
    if(mat->getH()>1)
    {matResize(-1,0);}
}

void Matrice_Input::plusColumns(){
    if(mat->getL()<50)
    {matResize(0,1);}
}

void Matrice_Input::minColumns(){
    if(mat->getL()>1)
    {matResize(0,-1);}
}

void Matrice_Input::rectify(){
    int r=mat->getH();
    int c=mat->getL();

    if(c==1 || r==1){  //Vettore
        matrice<double>* temp=new vector<double>(*mat);
        delete mat;
        mat=temp;
    }

    else if(r==c){
        bool diag=true;
        for(int i=0;i<r && diag;i++)
            for(int y=0;y<c && diag;y++)
                if(i!=y && (*mat)[i*c+y]!=0)
                   { diag=false;}

        if(diag)
        {
            bool scal=true;
            double test=(*mat)[0];
            for(int i=0;i<r && scal;i++)
                if(test!=(*mat)[i*c+i])
                {scal=false;}
            if(scal)
            {
                if(tipoText()!="Matrice Scalare"){  //Scalare
                    matrice<double>* temp=new scalar_matrice<double>(*mat);
                    delete mat;
                    mat=temp;
                }
            }
            else{
                if(tipoText()!="Matrice Diagonale")  //Diagonale
                {
                    matrice<double>* temp=new diagonal_matrice<double>(*mat);
                    delete mat;
                    mat=temp;
                }
            }
        }
        else{
            if(tipoText()!="Matrice Quadrata")   //Quadrata
            {
                matrice<double>* temp=new square_matrice<double>(*mat);
                delete mat;
                mat=temp;
            }}
}
    else{
        if(tipoText()!="Matrice Ordinaria")   //Ordinaria
        {
            matrice<double>* temp=new matrice<double>(*mat);
            delete mat;
            mat=temp;
        }
    }
}

#include<typeinfo>
QString Matrice_Input::tipoText()const{
    if(dynamic_cast<vector<double>*>(mat))
        return "Vettore";
    if(dynamic_cast<scalar_matrice<double>*>(mat))
        return "Matrice Scalare";
    if(dynamic_cast<diagonal_matrice<double>*>(mat))
        return "Matrice Diagonale";
    if(dynamic_cast<square_matrice<double>*>(mat))
        return "Matrice Quadrata";
    return "Matrice Ordinaria";

}

QString Matrice_Input::detText()const{
    square_matrice<double>* p=dynamic_cast<square_matrice<double>*>(mat);
    if(p==0)
    {return "Determinante non disponibile";}
    else{
        return "Determinante "+ QString::number(p->Det());
    }
}

void Matrice_Input::model(QTableWidgetItem *item){
    item->setText(item->text().replace(",","."));
    (*mat)[item->row()*mat->getL()+item->column()]= (item->text()).QString::toDouble();
    det->setText(detText());
    rectify();
    tipo->setText(tipoText());
}
