#include <iostream>
#include <cmath> 
using namespace std;

bool horseDanger(int k, int l, int m, int n) {
    int dY = abs(k - m);
    int dX = abs(l - n);

    if (dY == 1) {
        if (dX == 2) {
            return true;
        } else return false;
    } else if (dY == 2) {
        if (dX == 1) {
            return true;
        } else return false;
    } else return false;
}

int main() {
    int k, l, m, n;

    cout << "Введіть k: ";
    cin >> k;
    cout << "Введіть l: ";
    cin >> l;
    cout << "Введіть m: ";
    cin >> m;
    cout << "Введіть n: ";
    cin >> n;

    if (horseDanger(k, l, m, n)) {
        cout << "Кінь загрожує клітинці" << endl;
    } else {
        cout << "Кінь не загрожує клітинці" << endl;
    }

    return 0;
}
