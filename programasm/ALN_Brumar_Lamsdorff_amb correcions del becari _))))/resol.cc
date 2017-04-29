#include "sistema.hh"

void resol(double **a, double x[], double b[], int n, int perm []){
//PRE: 
    //Permutem el b.
    double baux[n];
    for (int i = 0; i < n; ++i) {
        baux[i] = b[perm[i]];
    }
    b = baux;
    
    //farem servir l'algorisme de substitució endavant per resoldre el sistema triangular
    
    // Ly = b
    double y[n];
    for( int i = 0; i < n; ++i){
        
        double acum = 0; 
        for( int j = 0; j < i; ++j ){
            acum += a[i][j]*y[j];
        }
        y[i] = (b[i] - acum);
    }
    
    
    // Ux = y per substitucio enrere

    for( int i = n - 1; i >= 0; --i){
        
        double acum = 0; 
        for( int j = n-1; j > i; --j ){
            acum += a[i][j]*x[j];
        }
        x[i] = (y[i] - acum)/a[i][i];
    }
}
