#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

//retorna un vector que la posició i conté 1/i!. Aquest representarà el polinomi de Taylor de la exponencial.
vector<double> taylor_grau(int n) { 
    vector<double> polinomi(n+1);
    polinomi[n] = 1;
    int factorial = 1;
    for (int i = 1; i <= n; ++i){
        factorial *= i;
        polinomi[n - i] = 1./factorial;
    }
    return polinomi;
}

void escriure(vector<double> p) {
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        cout << " " << p[i];
    }
    cout << endl;
}

//retorna el vector resultant després de fer la factorització i el RESIDU
vector<double> Ruffini(vector<double>& polinomi, double x) { //ha de ser enter??
    int m = polinomi.size();
    vector<double> p(m + 1);
    p[0] = polinomi[0];
    for (int i = 1; i <= m; ++i) {
        p[i] = polinomi[i] + x*p[i - 1];
    }
    cout << "Debug: residu (dins rutina) = " << p[m] << endl;
    return p;
}

int main() {
    //cout << "Grau del polinomi de Taylor de l'exponencial: ";
    //int n;
    //cin >> n;
    vector<double> v;
    

    //cout << endl << "Valor en el qual s'avalua el polinomi: ";
    double x = 1;
    //cin >> x;

    //vector<double> v_factoritzat = Ruffini(v, x);

    cout << "e^(" << 1 << ") = " << exp(x) << endl;
    v = taylor_grau(7);
    cout << endl << "p(1," << 7 << ") = " << Ruffini(v, x)[8] << endl;
    v = taylor_grau(8);
    cout << endl << "p(1," << 8 << ") = " << Ruffini(v, x)[9] << endl;
    v = taylor_grau(9);
    cout << endl << "p(1," << 9 << ") = " << Ruffini(v, x)[10] << endl;
    v = taylor_grau(10);
    cout << endl << "p(1," << 10 << ") = " << Ruffini(v, x)[11] << endl;
    v = taylor_grau(11);
    cout << endl << "p(1," << 11 << ") = " << Ruffini(v, x)[12] << endl;
    v = taylor_grau(12);
    cout << endl << "p(1," << 12 << ") = " << Ruffini(v, x)[13] << endl;
    v = taylor_grau(13);
    cout << endl << "p(1," << 13 << ") = " << Ruffini(v, x)[14] << endl;
    
    
    //escriure(v);
    return 0;
}