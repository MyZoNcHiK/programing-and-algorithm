#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return pow(x, 4);
}

double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += f(x) * h;
    }
    return sum;
}

int main() {
    double a, b;
    cout << "Введіть межі інтегрування";
    cin >> a >> b;

    int n = 100000;
    double result = integrate(a, b, n);

    cout << "Приблизне значення інтегралу x^4 від " << a << " до " << b << " = " << result << endl;
}

