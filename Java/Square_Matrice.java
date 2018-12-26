public class Square_Matrice extends Matrice{

	public Square_Matrice(int dim){
		super(dim,dim);
	}


	public Object Det() throws IndiceSbagliato{
		 if(this.getH()==2 && this.getL()==2)
        {	
        	double uno=ToDouble(this.getEL(0));
        	double due=ToDouble(this.getEL(3));
        	double tre=ToDouble(this.getEL(1));
        	double quattro=ToDouble(this.getEL(2));

        	return (Object) (uno*due-tre*quattro);}


double det=0.0;
int sign;
for(int i=0; i<getL(); i++)
{
    if(i%2==0) sign=1;
    else sign=-1;

    double ele=ToDouble(getEL(i));
    double el1=ToDouble(WithOut(0,i).Det());
    det+= ele * sign * el1;
}

return (Object)det;
	}

		public final Square_Matrice WithOut(int row, int col)throws IndiceSbagliato {
		 Square_Matrice temp= new Square_Matrice(this.getH()-1);
    int pos=0;
    for (int i = 0; i < this.getH(); i++)
    {
        for (int j = 0; j < this.getL(); j++)
        {
            if(j!=col && i!= row)
    {
    	Object t=getEL(i*this.getL()+j);
    	temp.setRaw(pos,t);
    	pos++;}
        }
    }
    return temp;
	}
}
