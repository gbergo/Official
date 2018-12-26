#ifndef SQUARE_MATRICE_H
#define SQUARE_MATRICE_H

#include "matrice.h"


template<class T>
class square_matrice: public matrice<T>{
public:
    /*Costruttori*/
    square_matrice(int);
    square_matrice(const matrice<T>&);

    /*Metodi*/
    square_matrice<T>* clone() const;


    /*Matrice inversa*/
    virtual T Det()const;

    square_matrice<T> WithOut(int row, int col)const;

};

// //////////////////////
//      COSTRUTTORI
// //////////////////////


template<class T>
      square_matrice<T>::square_matrice(int dim): matrice<T>(dim,dim){}

template<class T>
square_matrice<T>::square_matrice(const matrice<T>& m): matrice<T>(m){}

// ///////////////////////////////////
//  C A L C O L O  I N V E R S A   //
// ///////////////////////////////////

template<class T>
square_matrice<T> square_matrice<T>:: WithOut(int row, int col)const{
    square_matrice<T> temp(this->getH()-1);
    int pos=0;
    for (int i = 0; i < this->getH(); i++)
    {
        for (int j = 0; j < this->getL(); j++)
        {
            if(j!=col && i!= row)
                {temp[pos++]= (*this)[i*this->getL()+j];}
        }
    }
    return temp;
}

template<class T>
T square_matrice<T>:: Det()const{
    if(this->getH()==2 && this->getL()==2)
        {return ((*this)[0]*(*this)[3] - (*this)[1]*(*this)[2]);}

T det=0;
int sign;
for(int i=0; i<this->getL(); i++)
{
    if(i%2==0) sign=1;
    else sign=-1;

    det=det+(*this)[i]*sign * WithOut(0,i).Det();
}

return det;
}


template<class T>
square_matrice<T>* square_matrice<T>::clone()const{
  return (new square_matrice<T>(*this));
}



#endif // SQUARE_MATRICE_H
