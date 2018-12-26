public class IndiceSbagliato extends Throwable{
	private int ini;
	private int mass;

	public IndiceSbagliato(int i, int max)
	{
		ini=i; mass=max;
		System.out.print("indice i"+ini+"non rientra nella dimensione dell'array"+mass);
	}
}