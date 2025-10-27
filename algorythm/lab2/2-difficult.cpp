#include <iostream>
using namespace std;
float  S(float x1, float y1, float x2, float y2, float x3, float y3) {
    return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    cout << "Введіть координати трьох вершин трикутника:\n";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    float A = S(x1, y1, x2, y2, x3, y3);
    cout << A << endl;
    
    float A1 = S(0, 0, x2, y2, x3, y3);
    float A2 = S(x1, y1, 0, 0, x3, y3);
    float A3 = S(x1, y1, x2, y2, 0, 0);
    if (A == (A1+A2+A3)){
        cout << "Початок координат належить трикутнику.\n";
    } else  {cout << "Початок координат не належить трикутнику.\n";}

    return 0;
}
