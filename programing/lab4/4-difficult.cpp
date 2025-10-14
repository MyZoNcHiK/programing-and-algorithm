#include<iostream>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

bool check(vector<int> num) {
    int n = num.size();
    int half = n / 2;
    int total = accumulate(num.begin(), num.end(), 0);

    if (total % 2 != 0) return false;
    int need = total / 2;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) != half) continue;

        int sum = 0;
        for (int q = 0; q < n; ++q)
            if (i & (1 << q))
                sum += num[q];

        if (sum == need)
            return true;
    }
    return false;
}

int main() {
    unsigned long long N;
    cin >> N;
    string s = to_string(N);
    vector<int> num;
    for (char c : s) num.push_back(c - '0');

    if (num.size() == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    if (num.size() % 2 == 0) {
        cout << (check(num) ? "Yes" : "No") << endl;
    } else {
        bool ok = false;
        for (int i = 0; i < (int)num.size(); ++i) {
            vector<int> tryIgnor;
            for (int j = 0; j < (int)num.size(); ++j)
                if (i != j) tryIgnor.push_back(num[j]);
            if (check(tryIgnor)) { ok = true; break; }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}

