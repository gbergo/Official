class main{
	
	public static void main(String[] args) throws BadDim,IndiceSbagliato {
		
	Matrice uno= new Matrice(4,4);					// //////// MATRICE //////// //
	Object[] one={1,2,0,0,0,1,1,0,1,1,2,3,4,3,2,1};
	uno.fillRawMatrice(one);					//  Riempimento Matrice

	uno.Stampa();

	Matrice due= new Matrice(4,4);		
	Object[]two ={1,2,0,0,0,1,1,0,1,1,2,3,4,3,2,1};
	due.fillRawMatrice(two);						//  Riempimento Matrice

	due.Stampa();

	Matrice sommatoria=new Matrice(4,4);   // Somma Matrice
//	sommatoria=uno.add(due); 
//	sommatoria.Stampa();

//	uno.Trasposta(); // Trasposta
//	uno.Stampa();

//	uno.scalini(); // Gauss

	Object[]three ={3,1,4,3};

	Matrice meno=new Matrice(4,4);  // Differenza Matrice
//	meno=uno.diff(due);
// 	meno.Stampa();

	Matrice moltiplicazione=new Matrice(4,4);  // Moltiplicazione Matrice
//	moltiplicazione=uno.molt(due);
//	moltiplicazione.Stampa();

	Matrice moltiplica_per_x=new Matrice(4,4); // Moltiplicazione per x Matrice
//	moltiplica_per_x=uno.molt(2);
//	moltiplica_per_x.Stampa();




//	Square_Matrice tre= new Square_Matrice(2);				// ////// SQUARE_MATRICE ////// //
//	tre.fillRawMatrice(three);       			// Riempimento Square_Matrice

//	Object r=tre.Det();							// Determinante Square_Matrice
// 	System.out.print(r+"\n");					// Stampa Determinante Square_Matrice




//	Diagonal_Matrice ciao=new Diagonal_Matrice(4,4);		// ////// DIAGONAL_MATRICE ////// //
//	ciao.fillRawMatrice(three);					// Riempimento Diagonal_Matrice

//	Diagonal_Matrice cacao=new Diagonal_Matrice(4,4);
//	cacao.fillRawMatrice(one);					// Riempimento Diagonal_Matrice

	//ciao=ciao.somma(cacao);					// Somma Diagonal_Matrice
	//ciao=ciao.diff(cacao);					// Differenza Diagonal_Matrice
	//ciao=ciao.molt(cacao);					// Moltiplicazione Diagonal_Matrice
	//ciao=ciao.molt(2);						// Moltiplicazione per x Diagonal_Matrice
	//Object r= ciao.Det();						// Determinante Diagonal_Matrice
	//System.out.print(r+"\n");					// Stampa Determinante Diagonal_Matrice

	//ciao.Stampa();



//	Scalar_Matrice coke= new Scalar_Matrice(4,3);			// ////// SCALAR_MATRICE ////// //
//	Object r= coke.Det();						// Determinante Scalar_Matrice
//	System.out.print(r+"\n");					// Stampa Determinante Scalar_Matrice

//	coke.Stampa();



//	Vector cola= new Vector(1,4);							// ////// VECTOR ////// //
//	cola.fillRawMatrice(one);					// Riempimento Vector

//	cola.Stampa();

//	double r=cola.Euclidean_norm();				// Norma Euclidea
//	System.out.print(r+"\n");						// Stampa Norma Euclidea


	}
}