#include<iostream>
#include <cfloat>
using namespace std;

// CALCULAR ÈPSILON DE LA MÀQUINA

int main() {
    float epsF = 1.0;
    while (1.0f + epsF != 1.0) {
        epsF /= 2.0f;
    }             
    epsF *= 2;
    cout << "Machide epsilon (F): " << epsF << endl;
    cout << "        FLT_EPSILON: " << FLT_EPSILON << endl;                    
    
    double epsD = 1.0e0;
    while (1+epsD != 1.0e0) {
        epsD/= 2.0;
    }
    epsD *= 2.0;
    cout << endl;
    cout << "Machine epsilon (D): " << epsD << endl;
    cout << "        DBL_EPSILON: " << DBL_EPSILON << endl;
    
    return 0;
}