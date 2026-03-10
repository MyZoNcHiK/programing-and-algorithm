#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    for (char& c : s) {
        if (!isalnum(static_cast<unsigned char>(c))) c = ' ';
        else c = tolower(static_cast<unsigned char>(c));
    }

    map<string, int> m;
    string word;
    stringstream ss(s);
    while (ss >> word) m[word]++;

    for (const auto& p : m) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}

