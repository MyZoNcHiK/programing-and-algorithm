#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int N;
    while (cin >> N) {
        if (N == 0) break;
        a.push_back(N);
    }

    for (int id = 0; id < a.size(); ++id) {
        int n = a[id];
        int width = 2*n - 1;

        for (int i = 1; i <= n; ++i) {
            int stars = 2*i - 1;
            int spaces = (width - stars) / 2; // = n - i
            cout << string(spaces, ' ') << string(stars, '*') << '\n';
        }
        for (int i = n-1; i >= 1; --i) {
            int stars = 2*i - 1;
            int spaces = (width - stars) / 2;
            cout << string(spaces, ' ') << string(stars, '*') << '\n';
        }

        if (id + 1 < a.size()) cout << '\n';
    }
    return 0;
}

