#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
#include "matrice.h"

template<class T>

class vector: public matrice<T>{
public:
    vector(int height, int lenght);
    vector(const matrice<T>& t);

    vector<T>* clone()const;

    T Euclidean_norm()const;
    void Normalize();

};


template <class T>
vector<T>::vector(int height, int length):matrice<T>(height,length){}

template <class T>
vector<T>::vector(const matrice<T>& t):matrice<T>(t){}


template <class T>
vector<T>* vector<T>::clone()const{
  return (new vector<T>(*this));
}

template <class T>
T vector<T>::Euclidean_norm()const{
  T mtv=0;
  for(int i=0; i<this->getH()*this->getL();i++)
  {
    mtv=mtv+pow((*this)[i],2);
  }
  return sqrt(mtv);
}

template <class T>
void vector<T>::Normalize(){
  T norm=this->Euclidean_norm();
  for(int i=0; i<this->getH()*this->getL();i++)
  {
    (*this)[i]=(*this)[i]/norm;
  }
  
}








#endif
