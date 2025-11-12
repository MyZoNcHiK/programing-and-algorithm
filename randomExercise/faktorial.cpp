#include <iostream>
using namespace std;

long long f(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int testValues[] = {0, 1, 5, 10};
    int size = 4;

    for (int i = 0; i < size; i++) {
        int n = testValues[i];
        cout << "!(" << n << ") = " << f(n) << endl;
    }

    return 0;
}

