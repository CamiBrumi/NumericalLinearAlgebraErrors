#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int nr_digits_before_point(int n) {
    int count = 0;
    while (n > 0) {
        ++count;
        n /= 10;
    }
    return count;
}

float truncar(float f) {
    int n = nr_digits_before_point(int(f));
    float pow_of_ten = pow(10.0, n - 3);
    f /= pow_of_ten;
    int f_truncat = int(f);
    return f_truncat*pow_of_ten;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(3);
    unsigned long n = 1;
    float sum = 0;
   
    while (n <= 15) {
        sum = truncar(sum) + truncar(truncar(1.0f)/truncar(n*n));
        ++n;
    }
   
    cout << "decreixent: "<< setw(8) << sum << endl;
    sum = 0;
    n = 15;
    while (n > 0) {
        sum = truncar(sum) + truncar(truncar(1.0f)/truncar(n*n));
        --n;
    }
   
    cout << "creixent: "<< setw(8) << sum << endl;
   
   
    return 0;
}