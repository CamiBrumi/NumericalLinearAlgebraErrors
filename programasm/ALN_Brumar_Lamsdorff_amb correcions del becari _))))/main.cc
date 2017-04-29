
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sistema.hh"

#define FOUT "out.txt"


using namespace std;
using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[]) {
	


    ifstream fileIn;
    ofstream fileOut;

    fileIn.open(argv[1]); // obrim el fitxer per llegir les dades.

    // comprovem si el fitxer s'ha obert correctament

    if (!fileIn.is_open()) {

        cout << "Error: no s'ha pogut obrir el fitxer " << argv[1] << " per llegir les dades" << endl;

        exit(-1);

    }

    // Lectura del fitxer i assignació dels valors llegits a les components

    // de les matrius i del vector
    int n, m;

    fileIn >> n;

    fileIn >> m; 


	double **a = new double *[n];
	for(int i = 0; i < n; ++i){
		a[i] = new double[n];
		for( int j = 0; j < n; ++j){
			a[i][j] = 0;
		}
	}
	
    //omplim A amb les dades del fitxer
    for (int i = 0; i < m; ++i) {
        int j, k;
        fileIn >> j >> k;
        double x;
        fileIn >> x;
        a[j][k] = x;
    }
       


    //creem el vector b terme independent
    double *b = new double [n];
    for( int i = 0; i < n; ++i) b[i] = 0; 
    
    //k és el nombre de no-zeros que hi ha
    int k;
    fileIn >> k;

	
	//omplim b amb les dades del fitxer
    for( int i = 0; i < k; ++i){
        int f;
        fileIn >> f;
        double x;
        fileIn >> x;
        b[f] = x;
    }
    


    fileIn.close(); // Un com llegit i assignades les components,

                // tanquem el fitxer.

       
    double x[n];   
    
    int res = sistema( a, x, b, n, 0.00000000000001);
      // Abrimos el fichero para escribir los resultados
      fileOut.open(FOUT, ofstream::out);
      if (!fileOut.is_open()) {
        cout << "Error al abrir el fichero " << FOUT
             << " para escritura de datos. " << endl;
        return EXIT_FAILURE;
      }
      
      
     if ( res != 0 ){
         for( int i = 0; i < n; ++i){
             fileOut << i << "  " << x[i] << endl;               
         }               
     } else {
         cout << "La descomposicio no ha estat exitosa. La matriu A és singular d'acord amb la tolerància." << endl;
     }
        
     fileOut.close();  // Cerramos el fichero con los resultados

// escriptura de les solucions al fitxer de sortida,
// eliminació de l'espai reservat

    return 0;

}  
