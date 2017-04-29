#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> fila;
typedef vector<fila> matriu;

matriu llegeix_matriu(int n) {
  matriu M = matriu(n, fila(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> M[i][j];
  return M;
}

void escriu(int n, matriu M) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << " " << M[i][j];
    cout << endl;
  }
  cout << endl;
}
/*
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
*/

matriu identitat(int n) {
  matriu I = matriu(n,fila(n, 0));
  for (int i = 0; i < n; ++i) I[i][i] = 1;
  return I;
}

matriu inversa(int n, matriu& a) {
  matriu I = identitat(n);
  for (int k = 0; k < n - 1; ++k) {
    for (int i = k + 1; i < n; ++i) {
			double m = -a[i][k]/a[k][k]; // m = m[i][k]
			for (int j = k; j < n; ++j) {
				a[i][j] = a[i][j] + m*a[k][j];
        I[i][j] = I[i][j] + m*I[k][j];
			}
		}
  }

  for (int k = n - 1; k >= 0; --k) {
    cout << "k = " << k << endl;
    double pivot = a[k][k];
    a[k][k] = 1;
    for (int i = 0; i < n; ++i) {
      cout << "i1 = " << i << endl;
      I[k][i] /= pivot;
    }
    for (int i = k - 1; i >= 0; --i) {
      cout << "i2 = " << i << endl;
      for (int j = 0; j < n; ++j) {
        cout << "j = " << j << endl;
        I[i][j] = I[i][j] - a[i][k]*I[k][j];
      }
      a[i][k] = 0;
    }
  }
  return I;
}


int main() {
  int n;
  cin >> n;
  matriu M = llegeix_matriu(n);
  cout << "La matriu original és:" << endl;
  escriu(n, M);
  cout << "La matriu inversa és:" << endl;
  escriu(n, inversa(n, M));
  escriu(n, M);
}
