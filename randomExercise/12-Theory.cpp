#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

double entropy(const string &text) {
    map<char, int> counter;
    int total = text.size();

    for (char c : text) {
        char ch = tolower(c);
        counter[ch]++;
    }

    double H = 0.0;
    for (auto &p : counter) {
        double prob = (double)p.second / total;
        H -= prob * log2(prob);
    }

    return H;
}

int main() {
    string text = "Gorgun ggggg";

    double H = entropy(text);
    
    cout << "Ентропія тексту: "<< text << ": " << H << " біт/символ\n";
    cout << "Щоб записати текст потрібно приблизно: " << H*text.length() << endl;
    cout << "Ймовірності символів:\n";

    map<char, int> counter;
    for (char c : text) counter[tolower(c)]++;

    for (auto &p : counter) {
        double prob = (double)p.second / text.size();
        cout << "'" << p.first << "' = " << prob << endl;
    }

    return 0;
}

