#include "sistema.hh"
using namespace std;

void interc(double **a, int b, int c) { // intercanvia dues files
	double *d;
    d = a[b];
	a[b] = a[c];
	a[c] = d;
}

// exemple del funcionament del vector perm:
// on està la i-èssima fila
//p.e. perm = {2 0 1}, la fila 0 està a la posició 2


void permuta(int perm[], int pos1, int pos2){ //intercanvia dins el vector perm 
	int x = perm[pos1];
	perm[pos1] = perm[pos2];
	perm[pos2] = x;	
}

int pivotatge_parcial(double **a, int n, double tol, const int k) {
    //PRE: a té la matriu, int mida de la matriu, k pas de l'eliminació
    double maxs_fila_i [n - k];
	for(int i = k; i < n; ++i) {
			double max_fila = abs(a[i][k]);
			for(int j = k + 1; j < n; ++j) { // busquem el màxim (en valor absolut) de la fila i-èssima
				max_fila = max(max_fila, abs(a[i][j]));
			}
            maxs_fila_i[i - k] = max_fila;
	}
	
	
    maxs_fila_i[0] = abs(a[k][k])/maxs_fila_i[k];
	double max_col = maxs_fila_i[0];
    int max_pos = k;
    for(int i = 1; i < n - k; ++i){ //iterem sobre el vector de màxims
        maxs_fila_i[i] = abs(a[k + i][ k ])/maxs_fila_i[i]; //convertim el vector de maxims per la fila en vector de pivots divits per màxim de la seva fila
        if ( max_col < maxs_fila_i[i] ) {
            max_col = maxs_fila_i[i];
            max_pos = k + i;          
        }        
    }
    if(abs(a[max_pos][k]) < tol) return -1; // retornem -1 perquè la funcio pivotatge_parcial retorna la posició del pivot. La posició mai pot ser un nombre negatiu.
	
	return max_pos; 
	//ja hem trobat el màxim, retornem la seva fila, per tornar a la funció lu,
	// que farà la permutació i modificació de perm[] adient
	
//POST: retorna -1 si el pivot és massa petit i podem considerar la matriu massa singular.
//si no, retorna la fila on es troba el pivot més respecte la resta de la seva fila.
}

int lu(double **a, int n, int perm[], double tol) {
	
	int paritat = 1; // reflecteix la paritat
	
	for(int k = 0; k < n - 1; ++k) {
		int max_pos = pivotatge_parcial(a, n, tol, k);
		if (max_pos == -1) return 0; // matriu singular
		if (max_pos != k ){
			interc(a, max_pos, k); //canvia les files
			permuta(perm, k, max_pos); // indica al vector de permutacions que s'han canviat les files.
			paritat *= -1;		
		}		

		for(int i = k + 1; i < n; ++i) {
			double m = a[i][k]/a[k][k]; // m = m[i][k]
			for(int j = k + 1; j < n; ++j) {
				a[i][j] = a[i][j] - m*a[k][j];
			}
            a[i][k] = m;
		}
	}
	return paritat; 
}
