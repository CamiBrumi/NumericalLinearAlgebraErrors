#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<double> fila;
typedef vector<fila> matriu;

void swap(fila& a, fila& b) { // intercanvia dues files
	fila c = a;
	a = b;
	b = c;
}

// Quan utilitzem el TOL??
// no se com fer la matriu perm
// com mirem si hi ha un nombre parell/senar de permutacions?
// aquest programa em compila però no em dóna el resultat esperat
int pivotatge_parcial(matriu a, int n, double tol, int k) {
	for(int i = k; i <= n - 1; ++i) {
			double max_fila = abs(a[i][k]);
			for(int j = k + 1; j <= n - 1; ++j) { // busquem el màxim (en valor absolut) de la fila i-èssima
				max_fila = max(max_fila, abs(a[i][j]));
			}
			for(int j = k; j <= n - 1; ++j) { // dividim la fila pel màxim
				a[i][j] /= max_fila; 
			}
	}
	double max_col = abs(a[k][k]);
	int max_pos = k;
	for(int i = k + 1; i <= n - 1; ++i) { // busquem el màxim de la columna
		double aik = abs(a[i][k]);
		if (max_col < aik) {
			max_col = aik;
			max_pos = i;
		}
		if(max_col < tol) return 0;
		// hem trobat el màx, i ara permutem la fila on es troba el màxim amb la fila k-èssima
	}
	return max_pos;
	//retornar -1 si max_col < tol

}

int lu(matriu& a, int n, fila perm, double tol) { //
	for(int k = 0; k < n - 1; ++k) {
		int max_pos = pivotatge_parcial(a, n, tol, k); // he borat lo del pivot
			swap(a[max_pos], a[k]);
			perm[k] = max_pos;
		for(int i = k + 1; i <= n - 1; ++i) {
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

