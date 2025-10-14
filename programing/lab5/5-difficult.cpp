#include <iostream>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int x = i, r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if (r == i) {cout << i << " " << endl;}
    }
}

