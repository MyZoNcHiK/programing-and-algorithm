#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int rnd(int a, int b){ return a + rand() % (b - a + 1); }

int main() {
    srand((unsigned)time(nullptr));
    vector<int> v;
    for (int i = 0; i < 20; ++i){
        v.push_back(rnd(-10, 10));
    }

    cout << "Числа: ";
    for (int x : v) cout << x << ' ';
    cout << '\n';

    int zeros = count(v.begin(), v.end(), 0);
    int negatives = count_if(v.begin(), v.end(), [](int x){ return x < 0; });
    int sum = accumulate(v.begin(), v.end(), 0);
    double avg = (double)sum / v.size();
    int greater_than_avg = count_if(v.begin(), v.end(), [=](int x){ return x > avg; });

    cout << "Нулів: " << zeros << '\n';
    cout << "Від’ємних: " << negatives << '\n';
    cout << "Сума: " << sum << '\n';
    cout << fixed << setprecision(2) << "Середнє: " << avg << '\n';
    cout << "Більших за середнє: " << greater_than_avg << '\n';
    return 0;
}

