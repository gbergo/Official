#ifndef SCALARMATRIX_H
#define SCALARMATRIX_H

#include "diagonal_matrice.h"

template<class T>
class scalar_matrice: public diagonal_matrice<T>{
private:

public:
    scalar_matrice<T>* clone()const;
    scalar_matrice(int, const T& =0);
    scalar_matrice(const matrice<T>& t);
    virtual T Det ()const;
};



//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
scalar_matrice<T>::scalar_matrice(int dim, const T& t): diagonal_matrice<T>(dim,t){}

template <class T>
scalar_matrice<T>::scalar_matrice(const matrice<T>& t): diagonal_matrice<T>(t){}
//////////////////////////////
//   O P E R A Z I O N I    //
//////////////////////////////

#include <math.h>
template<class T>
T scalar_matrice<T>::Det()const{
  return pow((*this)[0],this->getL());
}

template <class T>
scalar_matrice<T>* scalar_matrice<T>::clone()const{
  return (new scalar_matrice<T>(*this));
}

#endif
