#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, S = 0, u1 = 1;
    cin >> x;

    for (int k = 1; k <= 7; k++) {
        u1 *= x / 2;
        S += u1;
        cout << "S" << k << ": " << k << "ln3 * " << S << endl;
    }
    return 0;
}

