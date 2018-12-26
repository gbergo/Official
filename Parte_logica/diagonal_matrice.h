#ifndef DIAGONAL_MATRICE_H
#define DIAGONAL_MATRICE_H


#include"square_matrice.h"


template<class T>
class diagonal_matrice:public square_matrice<T>
{
public:
    diagonal_matrice(int);
    diagonal_matrice(int,const T&);
    diagonal_matrice(const matrice<T>&);
    diagonal_matrice<T>* clone()const;

    diagonal_matrice<T> operator+(const diagonal_matrice<T>&)const;
    diagonal_matrice<T> operator-(const diagonal_matrice<T>&)const;
    diagonal_matrice<T> operator*(const diagonal_matrice<T>&)const;
    virtual matrice<T> operator*(const T&)const;

    virtual T Det()const;
    virtual void Trasposta();

};


//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template<class T>
diagonal_matrice<T>::diagonal_matrice(int dim): square_matrice<T>(dim){}


template<class T>
diagonal_matrice<T>::diagonal_matrice(int dim ,const T& t): square_matrice<T>(dim){
    (*this).Fill(0);
    for(int i=0; i<dim; i++){
        (*this)[i*dim+i]=t;
    }

}

template <class T>
diagonal_matrice<T>::diagonal_matrice(const matrice<T>& t): square_matrice<T>(t){}


//////////////////////////////
//  O P   O V E R L O A D   //
//////////////////////////////

template <class T>
diagonal_matrice<T> diagonal_matrice<T>::operator+(const diagonal_matrice<T>& dm)const{
  diagonal_matrice<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] + dm[i*this->getL()+i];
  return temp;
}


template <class T>
diagonal_matrice<T> diagonal_matrice<T>::operator-(const diagonal_matrice<T>& dm)const{
  diagonal_matrice<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] - dm[i*this->getL()+i];
  return temp;
}


template <class T>
diagonal_matrice<T> diagonal_matrice<T>::operator*(const diagonal_matrice<T>& dm)const{
  diagonal_matrice<T> temp(this->getL());
  temp.Fill(0);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = (*this)[i*this->getL()+i] * dm[i*this->getL()+i];
  return temp;
}

template <class T>
matrice<T> diagonal_matrice<T>::operator*(const T& t)const{
  diagonal_matrice<T> temp(*this);
  for(int i = 0; i < this->getL(); i++)
    temp[i*this->getL()+i] = temp[i*this->getL()+i] * t;
  return temp;
}

template <class T>
T diagonal_matrice<T>::Det()const{
  T t = 1;
  for(int i = 0; i < this->getL(); i++)
    t = (*this)[i*this->getL()+i] * t;
  return t;
}

template <class T>
void diagonal_matrice<T>::Trasposta(){}




template <class T>
diagonal_matrice<T>* diagonal_matrice<T>::clone() const{
  return (new diagonal_matrice<T>(*this));
}
#endif // DIAGONAL_MATRICE_H
