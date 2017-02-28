#include <iostream>
#include <iomanip>
using namespace std;

// SUMA DE LA SÈRIE HARMÒNICA

int main() {
    unsigned long n = 0;
    float sum, sum1 = 0;
    
    do {
        sum = sum1;
        sum1 = sum + 1.0f/++n;
    } while (sum1 != sum);
    
    cout << setw(8) << --n << setw(12) << sum << endl;
    
    
    return 0;
}