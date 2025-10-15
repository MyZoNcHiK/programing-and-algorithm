#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double d_cm = 10.0;
    double t_mm = 5.0;
    int n = 12;

    double r1 = d_cm / 2.0;
    double t_cm = t_mm / 10.0;

    double r_out = r1 + n * t_cm;

    double V_cm3 = (4.0 / 3.0) * M_PI * (pow(r_out, 3) - pow(r1, 3));

    double V_l = V_cm3 / 1000.0;

    cout << fixed << setprecision(6);
    cout << "Загальний об'єм (л): " << V_l << '\n';

    return 0;
}
