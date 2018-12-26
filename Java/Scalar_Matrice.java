public class Scalar_Matrice extends Diagonal_Matrice{
	
	public Scalar_Matrice(int dim,Object t) throws IndiceSbagliato{
		super(dim,t);
	}

	public Scalar_Matrice(int dim)throws IndiceSbagliato{
		super(dim);
	}

	public final Object Det()throws IndiceSbagliato{
		double a= ToDouble(getEL(0));
		return (Object) Math.pow(a,getL());
	}
}