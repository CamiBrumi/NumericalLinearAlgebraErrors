#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void invermat(int n, double **a, double **ainv, double &determ);

int main() {

	system ("clear");

	ifstream label1 ("datos//datos.in"); // Abre el archivo de entrada de datos

	// Definición de variables y asignación dinámica de memoria	

	int i, j, n;

        label1 >> n;

	double **a, **ainv, determ;

	a = new double* [n], ainv = new double* [n];

	for(j=0; j<n; j++){

		a[j] = new double [n], ainv[j] = new double [n];
	
	}	

	// Lectura de la matriz (label1 apunta a datos.in en el subdirectorio datos del home de usuario)

        for(i=0; i<n; i++){

                for(j=0; j<n; j++){

                         label1 >> a[i][j];
                }

	}

	cout << "Imprime la matriz de origen\n\n";

	// Matriz de origen; a

	for(i=0; i<n; i++){

                for(j=0; j<n; j++){

                         cout <<  a[i][j] << " ";
                }

	cout << endl;

        }

	cout << endl;

	invermat (n, a, ainv, determ);

	if (determ != 0) {

        cout << "Imprime la matriz inversa\n\n";

        // Matriz inversa; ainv

	cout.setf(ios::fixed);
	cout.precision(6);

        for(i=0; i<n; i++){

                for(j=0; j<n; j++){

                         cout << setw(10) << ainv[i][j] << " ";
                }

        cout << endl;

        }
        
        }

		else cout << "La matriz no tiene inversa\n\n";
       
 
	delete a;

	return 0;

}

void invermat(int n, double **a, double **ainv, double &determ) {

// Algoritmo para la eliminación simple de Gauss

	int i, j, k;

	double factor;

	double **L, *D, *X;
	
	X = new double [n]; D = new double [n];

	L = new double* [n];
	
	for (j = 0; j < n; j++) 

		L[j] = new double [n];

	for (k = 0; k < n - 1; k++) {
		
		for (i = k+1; i < n;  i++) {

			factor = a[i][k]/a[k][k]; 

			for (j = k+1; j < n + 1; j++) {

				a[i][j] = a[i][j] - factor * a[k][j];

			}
		


		}

	}

// Cálculo del determinante

        determ = 1.;

	for (i = 0; i < n; i++) {

		determ = determ * a[i][i];

	}

if (determ != 0) {

// Rutina para determinar las matrices L (inferior) y U (superior) de la 
// descomposición LU


        for (i = 0; i < n; i++) {

               for (j = 0; j < n; j++) {

                  if (i > j) {
     
                      L[i][j] = a[i][j]/a[j][j];

                      a[i][j] = 0;

                   }


               }

        }


       for (i = 0; i < n; i++) {

            for (j = 0; j < n; j++) {

                  L[j][j] = 1;

            }

        }


// Implementación de la rutina para el cálculo de la inversa


 for (k = 0; k < n; k++) {


// Esta rutina inicializa los L[i][n] para ser utilizados con la matriz L


          for (i = 0; i < n; i++) {

               if (i == k) L[i][n] = 1;

               else  L[i][n] = 0;

           }

// Esta función implementa la sustitución hacia adelante con la matriz L y los L[i][n]
// que produce la rutina anterior

  double sum;

  D[0] = L[0][n];

  for (i = 1; i < n; i++) {

       sum = 0;

       for (j = 0; j < i; j++) {

            sum = sum + L[i][j]*D[j];

       }

        D[i] = L[i][n] - sum;

   }



// Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U

  for (i = 0; i < n; i++) {

          a[i][n] = D[i];

  }

// Rutina que aplica la sustitución hacia atras


 X[n-1] = a[n-1][n]/a[n-1][n-1];

 // Determinación de las raíces restantes


  for (i = n - 2; i > -1; i--) {

        sum = 0;

        for (j = i+1; j < n; j++) {

              sum = sum + a[i][j]*X[j];

         }

         X[i] = (a[i][n] - sum)/a[i][i];

   }


// Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa

  for (i = 0; i < n; i++) {

         ainv[i][k] = X[i];

  }

 }   // llave de cierre del for para k

}   // cierre del if


	delete L, D, X;

}
