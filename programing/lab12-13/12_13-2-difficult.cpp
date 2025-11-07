#include <iostream>
using namespace std;

void findMaxSales(int sales[], int n){
    int maxDay = 0;
    for(int i = 1; i < n; i++){
        if(sales[i] > sales[maxDay]){
            maxDay = i;
        }
    }
    cout << "\nДень із найбільшими продажами: " << (maxDay + 1)
         << " (обсяг = " << sales[maxDay] << ")" << endl;
    sales[maxDay] = sales[maxDay] * 1.1;
}

int main(){
    int n;
    cout << "Введіть кількість днів (n ≤ 31): ";
    cin >> n;
    if(n < 1 || n > 31){
        cout << "Некоректне значення n!";
        return 0;
    }
    int sales[31];
    cout << "Введіть обсяг продажів за кожен день:\n";
    for(int i = 0; i < n; i++){
        cout << "День " << (i + 1) << ": ";
        cin >> sales[i];
    }
    cout << "\nМасив до виклику функції: ";
    for(int i = 0; i < n; i++){
        cout << sales[i] << " ";
    }
    findMaxSales(sales, n);
    cout << "\n\nМасив після виклику функції: ";
    for(int i = 0; i < n; i++){
        cout << sales[i] << " ";
    }
    cout << endl;
    return 0;
}

