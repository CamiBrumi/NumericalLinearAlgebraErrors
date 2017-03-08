#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CALCULAR LA INTEGRAL DE x^n*e^(x-1).

float cal_integral(int n) { //amb n interacions l'error és de n!*error (la i-èssima iteració es multiplica l'error per i)
    if (n == 0) return 1. - 1./M_E;
    return 1. - n*cal_integral(n - 1);
}

float cal_integral_millorat_E20(int n) {
    if (n == 20) return 0;
    return (1.0 - cal_integral_millorat_E20(n + 1))/(n + 1);
}

float cal_integral_taylor(int n) {
    int factorial = 1;
    float integral = 0;
    int i = 1;
    while (i <= 10) {
        integral += (1./factorial)*1./(n+i);
        factorial *= i;
        ++i;
    }
    return (1./M_E)*integral;
}

int main() {
    int n;
    cin >> n;
    cout << "--------1r Mètode--------" << endl;
    cout << cal_integral(n) << endl;
    
    cout << "--------2r Mètode (el millorat)--------" << endl;
    cout << cal_integral_millorat_E20(n) << endl;
    
    cout << "--------3r Mètode (Taylor)--------" << endl;
    cout << cal_integral_taylor(n) << endl;
  
  
    return 0;
}