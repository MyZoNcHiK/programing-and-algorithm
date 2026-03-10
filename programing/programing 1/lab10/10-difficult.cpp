#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int rnd(int a, int b) { return a + rand() % (b - a + 1); }
int main() {
    srand(time(0));
    const int n = 7;
    const int m = 7;

    int a[n][m];
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            a[i][j] = rnd(0, 7);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int bestRow = 0;
    int bestLen = 1;

    for (int i = 0; i < n; i++) {
        int currentLen = 1; 
        int maxLenRow = 1; 

        for (int j = 1; j < m; j++) {
            if (a[i][j] == a[i][j-1]) {
                currentLen++;
                if (currentLen > maxLenRow){
                    maxLenRow = currentLen;
                }
            } else {
                currentLen = 1;
            }
        }

        if (maxLenRow > bestLen) {
            bestLen = maxLenRow;
            bestRow = i;
        }
    }

    cout << "Рядок з найдовшою послідовністю: ";
    for (int j = 0; j < m; j++) cout << a[bestRow][j] << " ";
    cout << "\nДовжина послідовності: " << bestLen << endl;

    return 0;
}

