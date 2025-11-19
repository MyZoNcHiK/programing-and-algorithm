#include <iostream>
#include <vector>
#include <string>
using namespace std;

int powmod(int a, int b, int mod) {
    int result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int mod_inverse(int e, int phi) {
    int x, y;
    int g = egcd(e, phi, x, y);
    if (g != 1) {
        return -1;
    }
    x %= phi;
    if (x < 0) {
        x += phi;
    }
    return x;
}

int main() {
    int p = 11;
    int q = 13;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 23;
    int d = mod_inverse(e, phi);

    cout << "Відкритий ключ (e, n): (" << e << ", " << n << ")\n";
    cout << "Приватний ключ (d, n): (" << d << ", " << n << ")\n\n";

    string text;
    cout << "Введіть слово українською ВЕЛИКИМИ літерами: ";
    cin >> text;

    vector<int> message;
    for (char c : text) {
        int code = (unsigned char)c - (unsigned char)'А';
        message.push_back(code);
    }

    vector<int> encrypted;
    for (int m : message) {
        encrypted.push_back(powmod(m, e, n));
    }

    cout << "Зашифровані числа: ";
    for (int c : encrypted) {
        cout << c << " ";
    }
    cout << "\n";

    vector<int> decrypted;
    for (int c : encrypted) {
        decrypted.push_back(powmod(c, d, n));
    }

    cout << "Розшифровані числа: ";
    for (int x : decrypted) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Розшифроване слово: ";
    for (int x : decrypted) {
        char c = (char)('А' + x);
        cout << c;
    }
    cout << "\n";

    return 0;
}

