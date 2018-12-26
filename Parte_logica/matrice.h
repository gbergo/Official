#ifndef MATRICE_H
#define MATRICE_H

#include<iostream>
#include<math.h>
template<class T>
class matrice
{
        /*
        Tutte le istanze di questi overload sono amiche della classe matrice,
    indipendentemente dal tipo U che matrix contiene.
        */

        template<class U>
        friend std::istream& operator>>(std::istream& is, matrice<U>& m);

        template<class U>
        friend std::ostream& operator<<(std::ostream& os, const matrice<U>& m);

private:

        int h, l;
        T* raw_matrix;//array che tiene conto el

        /*Fa una deep copy di un array (raw_matrix) da una matrice m, e ne torna
    il puntatore*/
        static T* copyArr(const matrice<T>& m);

        /*Esegue il prodotto vettoriale fra due vettori estrapolati da matrici
    sulla riga row e colonna col*/
    static T VectProd(const matrice<T>& m1, int row, const matrice<T>& m2, int col);


public:

        int getH()const;
        int getL()const;

        //Ridefinizione delle operazioni principali
        matrice(const int& =1, const int& =1);//inizializzo con l=1 e h=1
        matrice(const matrice<T>& );//costruttore di copia;
        virtual ~matrice();//distruttore virtuale
        virtual matrice<T>* clone()const;//nuovo puntatore a una matrice

        /*Operazioni matematiche fra matrici*/
        matrice<T>& operator=(const matrice<T>& );
        matrice<T> operator+(const matrice<T>& )const;
        matrice<T> operator-(const matrice<T>& )const;
        matrice<T> operator*(const matrice<T>& )const;
        bool stesseDim (const matrice<T>&)const;
        bool uguali(const matrice<T>&)const;

        /*Operazioni in più su matrice*/

        virtual void Trasposta();
        virtual matrice<T> scalini();


    //Funzioni scalari che si applicano elemento per elemento
    virtual matrice<T> operator*(const T&)const;

    void eleva(const double& o);

        /*Operatore di selezione di un elemento nell'array */
        T& operator[](const int&)const;

        /*Operatore di uguaglianza*/
        bool operator==(const matrice<T>&)const;

        /*Operatore di conversione fra vari tipi di matrice
    Il template class U è necessario perchè voglio rendere
    la conversione disponibile con ogni tipo di matrice*/
        template <class U>
        operator matrice<U>();


        //Metodi di taglia-cuci per matrici
    void Fill(const T& t);//riempire
    void Cut(int row_start, int row_num, int col_start, int col_num);
    void Appendcol(const matrice<T>& m1);
    void Appendriga(const matrice<T>& m1);

};


//   /////////////////////////////////
//    RITORNO RIGHE E COLONNE MATRICE
//  /////////////////////////////////

template<class T>
int matrice<T>::getH()const{return h;}

template<class T>
int matrice<T>::getL()const{return l;}

/**/

template<class T>
bool matrice<T>::stesseDim(const matrice<T>& m)const{
        if(h==m.h && l==m.l){return true;}
}

template<class T>
bool matrice<T>::uguali(const matrice<T>& t) const{
    if(h==l && t.h==t.l)
        {return true;}
    else return false;
}


// /////////////////////////
//       OP OVERLOAD
// /////////////////////////

template <class T>
std::istream& operator>>(std::istream& is, matrice<T>& m){
        for(int i=0;i<m.h *m.l;i++)
        {
                is>>m[i];
        }
        return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const matrice<T>& m){
        for (int i = 0; i < m.h; i++)
        {
                for(int j=0;j<m.l;j++)
                {
            os<<m[i*m.l+j]<<"\t\t";
                }
                os<<std::endl;
        }
        return os;
}


template<class T>
T& matrice<T>::operator[](const int& i)const{
        return raw_matrix[i];
}

template<class T>
matrice<T> matrice<T>::operator+(const matrice<T>& m)const{
        if((*this).stesseDim(m)){
                matrice<T> temp(h,l);
                for(int i=0; i< l*h; i++)
                        {temp[i]=(*this)[i] + m[i];}
                return temp;
        }
}

template<class T>
matrice<T> matrice<T>::operator-(const matrice<T>& m)const{
        if((*this).stesseDim(m)){
                matrice<T> temp(h,l);
                for(int i=0; i< l*h; i++)
                        {temp[i]=(*this)[i] - m[i];}
                return temp;
        }
}

template<class T>
matrice<T> matrice<T>::operator*(const matrice<T>& m)const{
        if(l==m.h)
        {
                matrice<T> temp(h,m.l);
                for (int i = 0; i < temp.h; i++)
                {
                        for (int j = 0; j < temp.l; j++)
                        {
                                temp[i*temp.l+j]=VectProd((*this),i,m,j);
                        }
      }

                return temp;
        }
}

template <class T>
bool matrice<T>::operator==(const matrice<T>& m)const{
        if(!(*this).stesseDim(m))
                {return false;}
        for(int i=0; i<l*h;i++)
        {
                if((*this)[i]!=m[i])
                        {return false;}
        }
        return true;
}

template <class T>
matrice<T>& matrice<T>::operator=(const matrice<T>& m){
        if(this == &m)
        {
                return (*this);
        }
        T* p= raw_matrix;
        delete[] p;
        l=m.l;
        h=m.h;
        raw_matrix=copyArr(m);
        return (*this);
}

template <class T>
template <class U>
matrice<T>::operator matrice<U>(){
        matrice<T> temp(h,l);
        for(int i=0; i<l*h; i++)
        {
                temp[i]=(*this)[i];
        }
        return temp;
}

// /////////////////////////
//     FUNZ. SCALARI
// /////////////////////////


template <class T>
matrice<T> matrice<T>::operator*(const T& n)const{
  matrice<T> m(h,l);
  for(int i=0; i < h*l; i++)
    m[i] = (*this)[i]*n;
  return m;
}


// /////////////////////////
//       STATICHE
// /////////////////////////

template <class T>
T* matrice<T>::copyArr(const matrice<T>& m){
    T* array1= new T[m.h*m.l];
        for(int i=0;i<m.h*m.l;i++)
        {
                array1[i]=(T)m.raw_matrix[i];
        }
        return array1;
}



template<class T>
T matrice<T>::VectProd(const matrice<T>& m1, int row, const matrice<T>& m2, int col)
{
        T som=0;
        for(int i=0; i<m1.l; i++)

    som+=m1[i+m1.l*row] * m2[i*m2.l+col];
    return som;
}


// /////////////////////////
//        COSTRUTTORI
// /////////////////////////

template <class T>
matrice<T>::matrice(const int& height, const int& lenght): h(height), l(lenght),
raw_matrix(new T[lenght*height]){}

template<class T>
matrice<T>::matrice(const matrice<T>& m): h(m.h), l(m.l), raw_matrix(copyArr(m)){}

template <class T>
matrice<T>::~matrice(){
        delete[] raw_matrix;
}

// /////////////////////////
//      TAGLIA E CUCI
// /////////////////////////

template <class T>
void matrice<T>::Fill(const T& t){
  for(int i = 0; i < l*h; i++)
    (*this)[i] = t;
}

// /////////////////////////
//        OPERAZIONI
// /////////////////////////


template <class T>
matrice<T>* matrice<T>::clone()const{
return (new matrice<T>(*this));
}

template<class T>
void matrice<T>::Trasposta(){
        matrice<T> temp(h,l);
        for (int i = 0; i < h; i++)
        {
                for (int j = 0; j < l; j++)
                {
            temp[j*h+i]=(*this)[i*l+j];
                }
        }
        *this=temp;
}

template <class T>
matrice<T> matrice<T> ::scalini()
{
    matrice<T> nuova(*this);
    double coeff=0;
    for (int i = 0; i < h; i++)
    {bool test=false;
        for (int j = 0;j < l; j++)
        {
          if((*this)[i*l+j]!=0 ){

              if((*this)[i*l+j]!=1 )
              {
                coeff=(*this)[i*l+j];
                int z = j;
                for (; z < l; z++)
              {
               nuova[i*l+z]=(*this)[i*l+z] / coeff;

              }

                *this=nuova;

              }

            if((*this)[i*l+j]==1 /*&& (*this)[(1+i)*l+j]!=0*/&& (1+i)*l+j<l*h)
            {int r=i+1;
                while(r<h)
                {if((*this)[(r)*l+j]!=0)

           {
                int e=(*this)[(r)*l+j]* -1;
                test=true;
int z=j;
int t=r;
                for (; z < l; z++)
                {
                  coeff=e*(*this)[i*l+z];
                    nuova[(t)*l+z]=coeff + (*this)[(t)*l+z];
                }

 }
              r++;}

}

  *this=nuova;  j=l;}//chiusura ((*this)[i*l+j]!=0)
          }//chiusura for colonne
        }//chiusura for righe

   *this=nuova;
    return *this;
}


template <class T>
void matrice<T>::Appendriga(const matrice<T>& m1){//riga
  if(m1.l == l){

    matrice<T> temp(h + m1.h,m1.l);
    int i = 0;
    for(; i < l*h; i++)
        temp[i] = (*this)[i];
    for(; i < temp.h*temp.l; i++)
        temp[i] = m1[i - l*h];

    *this = temp;
  }
}

template <class T>
void matrice<T>::Appendcol(const matrice<T>& m1){//col
  if(m1.h == h){
    int pos = 0;
    matrice<T> temp(m1.h,l+m1.l);
    for(int r = 0; r < m1.h; r++){
      for(int c = 0; c < l; c++){
        temp[pos] = (*this)[r*l+c];
        pos++;
      }
      for(int c = 0; c < m1.l; c++){
        temp[pos] = m1[r*m1.l+c];
        pos++;
      }
    }
    *this = temp;
  }
}

template <class T>
 void matrice<T>::Cut(int row_start, int row_num, int col_start, int col_num){

        matrice<double> temp(row_num-row_start,col_num-col_start);
        int pos=0;

        for(int r=row_start; r<row_num;r++)
        {
                for (int c = col_start; c < col_num; ++c)
                {
                        temp[pos]=(*this)[r*l+c];
                        pos++;
                }
        }

        *this=temp;
 }


template <class T>
void matrice<T>:: eleva(const double& o)
{
    for(int i = 0; i < l*h; i++)
           (*this)[i] = pow((*this)[i],o);
}


#endif // MATRICE_H
