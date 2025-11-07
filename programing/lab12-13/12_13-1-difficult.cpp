#include <iostream>
#include <vector>
using namespace std;

void processPrices(vector<double> prices) {
    double minPrice = prices[0];
    for (int i = 1; i < prices.size(); i++){
        if (prices[i] < minPrice){minPrice = prices[i];}}

    double sum = 0;
    for (double p : prices){sum += p;}
    double avg = sum / prices.size();

    for (double &p : prices){
        if (p > avg){p *= 0.9;}}

    cout << "\nНайнижча ціна: " << minPrice << endl;
    cout << "Масив після функції ";
    for (double p : prices){cout << p << " ";}
    cout << endl;
}

int main() {
    vector<double> prices = {120, 150, 200, 130, 90, 110, 140, 170, 160, 100};

    cout << "Масив до функції: ";
    for (double p : prices){cout << p << " ";}
    cout << endl;

    processPrices(prices);
}

