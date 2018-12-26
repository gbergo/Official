public class Vector extends Matrice{

	public Vector(int height, int lenght) throws IndiceSbagliato{
		super(height,lenght);
	}

	public double Euclidean_norm() throws IndiceSbagliato{
		double mtv=0;
		 for(int i=0; i<getH()*getL();i++)
		 {
		 	double a= ToDouble(getEL(i));
		 	 mtv=mtv + Math.pow(a,2);
		 }
		 return Math.sqrt(mtv);
	}

	public void Normalize() throws IndiceSbagliato{
		double norm=this.Euclidean_norm();
		 for(int i=0; i<getH()*getL();i++){
		 	double a=ToDouble(getEL(i));
		 	double b=a/norm;
		 	setRaw(i,b);
		 }
	}
}