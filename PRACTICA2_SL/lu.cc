#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<double> fila;
typedef vector<fila> matriu;

void swap(fila a, fila b) { // intercanvia dues files
	fila c = a;
	a = b;
	b = c;
}

// Quan utilitzem el TOL??
// no se com fer la matriu perm
// com mirem si hi ha un nombre parell/senar de permutacions?
// aquest programa em compila però no em dóna el resultat esperat
int pivotatge_parcial(matriu& a, int n, fila perm, double tol, int k, double& pivot) {

	for(int i = k + 1; i <= n - 1; ++i) {
			double max_fila = abs(a[i][k]);
			for(int j = k + 1; j <= n - 1; ++j) { // busquem el màxim (en valor absolut) de la fila i-èssima
				double aij = abs(a[i][j]);
				if (max_fila < aij) max_fila = aij; 
			}
			for(int j = k; j <= n - 1; ++j) { // dividim la fila pel màxim
				a[i][j] /= max_fila; 
			}
	}
	double max_col = abs(a[k + 1][k]);
	int max_pos = k + 1;
	for(int i = k + 2; i <= n - 1; ++i) { // busquem el màxim de la columna
		double aik = abs(a[i][k]);
		if (max_col < aik) {
			max_col = aik;
			max_pos = i;
		}
		// hem trobat el màx, i ara permutem la fila on es troba el màxim amb la fila k-èssima
		swap(a[max_pos], a[k]);
	}
	return 1;

}

int lu(matriu& a, int n, fila perm, double tol) { //
	for(int k = 0; k <= n - 1; ++k) {
		for(int i = k + 1; i <= n - 1; ++i) {
			//Anem a fer pivotatge parcial
			double pivot;
			if (pivotatge_parcial( a, n, perm, tol, k, pivot) == 0) return 0;


			double m = a[i][k]/a[k][k]; // m = m[i][k]
			for(int j = k; j <= n - 1; ++j) {
				a[i][j] = a[i][j] - m*a[k][j];
			}
		}
	}
	return 0;
}

void llegeix(matriu& v, int n) { // llegeix una matriu
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}
}

void escriu(matriu& v, int n) { // escriu una matriu per pantalla
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) cout << " " << v[i][j];
		cout << endl;
	}
}


int main() {
	int n;
	cin >> n;
	matriu v(n, fila(n));
	llegeix(v, n);
	escriu(v, n);
	cout << endl;
	fila p(n, 0);
	lu(v, n, p, 0.01);
	escriu(v, n);
}

