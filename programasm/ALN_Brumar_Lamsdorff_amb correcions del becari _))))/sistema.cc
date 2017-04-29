#include "sistema.hh"
#include <iostream>
#include <vector>

using namespace std;

int sistema(double **a, double x[], double b[], int n, double tol){
	//PRE: a apuntador d'apuntadors de files de la matriu A, n dimensió de la matriui, tol tolerància, i b terme intependent
    vector<vector<double> > aprima(n, vector<double>(n));
    //copio la matriu a element a element
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) aprima[i][j] = a[i][j];
    }
    vector<double> baux(n);
    for (int i = 0; i < n; ++i) baux[i] = b[i];
	int perm[n];
	for (int i = 0; i < n; ++i) perm[i] = i; // creem i omplim el vector permutació
	int resultat = lu(a, n, perm, tol);
	if (resultat != 0 ) resol(a, x, b, n, perm);	
    
    //càlcul norma residu
    double res[n];
    

    for( int  i = 0; i < n; ++i){ //bucle del producte ax (-b)
        double aux = 0;
        for( int j = 0; j < n; ++j){
            aux += aprima[i][j]*x[j];
        }
        res[i] = aux - baux[i];
    }
    double norma = 0;
    for( int i = 0; i < n; ++i){ //bucle de la norma
        norma += res[i]*res[i];
    }
    
    norma = sqrt(norma);
    cout << " La norma del residu ||Ax - b|| és: " << norma << '.' << endl;
    
	return resultat;	
}

	/*POST: 
	 * 	la matriu A, que està descomposada LU (però és inútil a partir d'ara perquè no tenim per[]
	 * 	 x és la solució del sistema, 
	 * 	i retorna:
	 * 1 si descomposició exitosa amb # parell de permutacions
	 * -1 "" "" si nombre senar
	 * 0 si és singular respecte la tolerància, i hem destruit la matriu.
	 */ 
