public class Matrice{

	private int h;
	private int l;
	private Object[] raw_matrix;

	public Matrice(){
		h=0;
		l=0;
		raw_matrix=new Object[0];
	}

	public Matrice(int height, int lenght)
	{
		if(height<=0){h=1;}
		if(lenght<=0){l=1;}

		h=height;
		l=lenght;
		raw_matrix=new Object[l*h];
		for (int i=0; i<l*h; i++) {
			raw_matrix[i]=new Object();
		}
	}

	public void fillRawMatrice(Object[] ob)
{
	System.arraycopy(ob,0,raw_matrix,0,h*l);
}

public void Stampa()
{

		for (int i=0;i<h ; i++) {
		for (int j=0; j<l; j++) {
		System.out.print(ToDouble(raw_matrix[i*h+j])+" ");	
		}
		System.out.print("\n");
	}
	System.out.print("\n");
}


public void fill(Object ob){
	for (int i=0;i<l*h ; i++) {
		raw_matrix[i]=ob;
	}
}

public final int getH(){
	return h;
}

public final int getL(){
	return l;
}

public final static double ToDouble(Object ob)
{
	String s1=ob.toString();
	return Double.parseDouble(s1);
}

public final void setRaw(int i, Object t) throws IndiceSbagliato{
	if(i<l*h || i>=0){
		raw_matrix[i]=t;
	}
}

public final Object getEL(int i) throws IndiceSbagliato{
	if(i<0 || i>h*l) throw new IndiceSbagliato(i,l*h);
	else return raw_matrix[i];
}

public final void setEL(int i, Object t) throws IndiceSbagliato{
	if(i<0 || i>h*l) throw new IndiceSbagliato(i,l*h);
	else raw_matrix[i]=t;
}

public final static Object VectProd(Matrice m1, int row, Matrice m2, int col){
	double sum=0.0;
	for (int i=0; i<m2.h ; i++) {
		double a=ToDouble(m1.raw_matrix[i+m1.l*row]);
		double b=ToDouble(m2.raw_matrix[col+m2.l*i]);
		sum+=a*b;
	}
	return (Object)sum;
}

public final void copy(Matrice m)
{
	h=m.h;
	l=m.l;
	System.arraycopy(m.raw_matrix,0,raw_matrix,0,m.h*m.l);
}

public final boolean stesseDim(Matrice m)
{
	return(m.h==h && m.l==l);
}

public final boolean equalsTo(Matrice m){
	if(stesseDim(m))
	{
		for (int i=0; i<m.h*m.l; i++) {
			String s1=raw_matrix[i].toString();
			String s2=raw_matrix[i].toString();
			if(s1.equals(s2))
				{return true;}else return false;
		}
	}
return false;
}

public Matrice add(Matrice m) throws BadDim{
	if(stesseDim(m))
	{
		Matrice temp= new Matrice(m.h,m.l);
		double som;
		for (int i=0;i<m.l*m.h ; i++) {
			double a= ToDouble(raw_matrix[i]);
			double b= ToDouble(m.raw_matrix[i]);
			som=a+b;
			temp.raw_matrix[i]=(Object)som;
		}
return temp;
	}else throw new BadDim();
}

public Matrice diff(Matrice m) throws BadDim{
	if(stesseDim(m))
	{
		Matrice temp=new Matrice(m.h,m.l);
		double som;
		for (int i=0;i<m.l*m.h ; i++) {
			double a= ToDouble(raw_matrix[i]);
			double b= ToDouble(m.raw_matrix[i]);
			som=a-b;
			temp.raw_matrix[i]=(Object)som;
		}
return temp;
	}else throw new BadDim();
}

public Matrice molt(Matrice m) throws BadDim{
	if(stesseDim(m)){
		Matrice temp= new Matrice(m.h,m.l);
		for (int i=0; i<temp.h; i++) {
			for (int j=0; j<temp.l; j++) {
				temp.raw_matrix[i*temp.l+j]=VectProd(this,i,m,j);
			}
		}
		return temp;
	}else throw new BadDim();
}

public Matrice molt(Object t) throws IndiceSbagliato{//controllare
	Matrice temp= new Matrice(h,l);
	temp.copy(this);
	double d=ToDouble(t);
	for (int i=0;i<temp.h*temp.l ;i++ ) {
		double a=ToDouble(raw_matrix[i]);
		double mol=d*a;
		temp.raw_matrix[i]=(Object)mol;
	}
	return temp;
}


public void Trasposta(){
	Object[] temp=new Object[l*h];
	int h1=h;
	for (int i=0;i<h ; i++) {
		for (int j=0;j<l ; j++) {
			temp[j*h+i]=raw_matrix[i*l+j];		}
	}
	h=l; l=h1;
	System.arraycopy(temp,0,raw_matrix,0,h*l);
}


public final void cut(int row_start, int row_num, int col_start, int col_num){
	Matrice temp= new Matrice(row_num-row_start,col_num-col_start);
	int pos=0;

	for (int r=row_start;r<row_num ; r++) {
		for (int j=col_start; j<col_num; j++) {
			temp.raw_matrix[pos]=raw_matrix[r*l+j];
			pos++;
		}
	}
	copy(temp);
}

public final void appendRiga(Matrice m1) throws BadDim{
	if(m1.l!=l) throw new BadDim();
	else{
		Matrice temp= new Matrice(h + m1.h,m1.l);
		int i=0;
		for (;i<l*h ; i++) 
			temp.raw_matrix[i]=raw_matrix[i];
		for (;i<temp.h*temp.l ; i++) 
			temp.raw_matrix[i]=m1.raw_matrix[i - l*h];
		copy(temp);
	}
}

public final void appendCol(Matrice m5) throws BadDim{
	if(m5.h!=h)throw new BadDim();
	else{
		int pos=0;
		Matrice temp= new Matrice (m5.h,l + m5.l);
		for(int r = 0; r < m5.h; r++){
      for(int c = 0; c < l; c++){
      	temp.raw_matrix[pos]=raw_matrix[r*l+c];
      	pos++;
	}
	for(int c = 0; c < m5.l; c++){
        temp.raw_matrix[pos] = m5.raw_matrix[r*m5.l+c];
        pos++;
      } }
      copy(temp);
}
}


public Matrice scalini(){

	Matrice nuova= new Matrice(h,l);
	nuova.copy(this);

	double coeff=0;

	 for (int i = 0; i < h; i++)
    {boolean test=false;
        for (int j = 0;j < l; j++)
        {
          if(ToDouble(raw_matrix[i*l+j])!=0 ){

              if(ToDouble(raw_matrix[i*l+j])!=1 )
              {
                coeff=ToDouble(raw_matrix[i*l+j]);
                int z = j;
                for (; z < l; z++)
              {
               nuova.raw_matrix[i*l+z]=(Object)(ToDouble(raw_matrix[i*l+z]) / coeff);

              }

                this.copy(nuova);

              }

            if(ToDouble(raw_matrix[i*l+j])==1 /*&& (*this)[(1+i)*l+j]!=0*/&& (1+i)*l+j<l*h)
            {int r=i+1;
                while(r<h)
                {if(ToDouble(raw_matrix[(r)*l+j])!=0)

           {
                double e=ToDouble(raw_matrix[(r)*l+j])* -1;
                test=true;
int z=j;
int t=r;
                for (; z < l; z++)
                {
                  coeff= e * ToDouble(raw_matrix[i*l+z]);
                    nuova.raw_matrix[(t)*l+z]=(Object)(coeff + ToDouble(raw_matrix[(t)*l+z]));
                }

 }
              r++;}
 
}

  this.copy(nuova);  j=l;}//chiusura ((*this)[i*l+j]!=0)
          }//chiusura for colonne
        }//chiusura for righe

   this.copy(nuova);
    return this;

}
}
