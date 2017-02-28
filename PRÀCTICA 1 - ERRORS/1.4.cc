#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CALCULAR LA INTEGRAL DE x^n*e^(x-1).

float cal_integral(int n) {
    if (n == 0) return 1. - 1./M_E;
    return 1. - n*cal_integral(n - 1);
}

int main() {
    cout << "E0 = " << 1. - 1./M_E << endl;
    cout << "E12 = " << cal_integral(12) << endl;
   
   
    return 0;
}