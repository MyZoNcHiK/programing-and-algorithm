#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int rnd(int a, int b) { return a + rand() % (b - a + 1); }

int main() {
    srand(time(0));
    int prices[30];

    for (int i = 0; i < 30; i++) {
        prices[i] = rnd(100, 300);
        cout << prices[i] << " ";
    }
    cout << endl;

    int minPrice = prices[0], minIndex =0, buyDay = 0, sellDay = 0, maxProfit = 0;

    for (int i = 1; i < 30; i++) {
        if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
            buyDay = minIndex; 
            sellDay = i;
        }

        if (prices[i] < minPrice) {
            minPrice = prices[i];
            minIndex = i;
        }
    }

    cout << "Максимальний прибуток: " << maxProfit << endl;
    cout << "Купити в день: " << buyDay + 1 << " за ціною " << prices[buyDay] << endl;
    cout << "Продати в день: " << sellDay + 1 << " за ціною " << prices[sellDay] << endl;

    return 0;
}
