public class Diagonal_Matrice extends Square_Matrice {
	
	public Diagonal_Matrice (int dim) throws IndiceSbagliato{
		super(dim);
		fill(0);
		for (int i=0; i<dim; i++) {
			setRaw(i*dim+i,1);
		}
	}

	public Diagonal_Matrice(int dim, Object t) throws IndiceSbagliato{
		super(dim);
		fill(0);
		for (int i=0; i<dim; i++) {
			setRaw(i*dim+i,t);
		}
	}


	public Diagonal_Matrice somma(Diagonal_Matrice m) throws IndiceSbagliato, BadDim{
		if (stesseDim(m))
		{
			Diagonal_Matrice temp=new Diagonal_Matrice(getL());
			temp.copy(this);
			for(int i = 0; i < this.getL(); i++){
				double a= ToDouble(temp.getEL(i*this.getL()+i));
				double b= ToDouble(m.getEL(i*this.getL()+i));
				a+=b;
				temp.setRaw(i*this.getL()+i,a);
			}
			return temp;
		}else throw new BadDim();
	}

	public Diagonal_Matrice diff(Diagonal_Matrice m) throws IndiceSbagliato, BadDim{
		if (stesseDim(m))
		{
			Diagonal_Matrice temp=new Diagonal_Matrice(getL());
			temp.copy(this);
			for(int i = 0; i < this.getL(); i++){
				double a= ToDouble(temp.getEL(i*this.getL()+i));
				double b= ToDouble(m.getEL(i*this.getL()+i));
				a-=b;
				temp.setRaw(i*this.getL()+i,a);
			}
			return temp;
		}else throw new BadDim();
	}


	public Diagonal_Matrice molt(Diagonal_Matrice m) throws IndiceSbagliato, BadDim{
		if (stesseDim(m))
		{
			Diagonal_Matrice temp=new Diagonal_Matrice(getL());
			temp.copy(this);
			for(int i = 0; i < this.getL(); i++){
				double a= ToDouble(temp.getEL(i*this.getL()+i));
				double b= ToDouble(m.getEL(i*this.getL()+i));
				a*=b;
				temp.setRaw(i*this.getL()+i,a);
			}
			return temp;
		}else throw new BadDim();
	}

	public Diagonal_Matrice molt(Object t) throws IndiceSbagliato{

			Diagonal_Matrice temp=new Diagonal_Matrice(getL());
			temp.copy(this);
			for(int i = 0; i < this.getL(); i++){
				double a= ToDouble(temp.getEL(i*this.getL()+i));
				double b= ToDouble(t);
				a*=b;
				temp.setRaw(i*this.getL()+i,a);
			}
			return temp;
	}


	public Object Det() throws IndiceSbagliato{
		double t=1.0;
		  for(int i = 0; i < this.getL(); i++){
		  	double a= ToDouble(getEL(i*this.getL()+i));
		  	t*=a;
		  }
		 return (Object)t;
	}

}