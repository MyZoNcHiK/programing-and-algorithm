#include <iostream>
using namespace std;

int main() {
    const int m = 4, n = 5;
    int A[m][n] = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10},
        {3, 5, 7, 9, 11},
        {4, 6, 8, 10, 12}
    };

    int x;
    cin >> x;

    bool foundRow = false;
    bool foundCol = false;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[0][mid] == x) {
            cout << "Знайдено у першому рядку: A[0][" << mid << "] = " << x << endl;
            foundRow = true;
            break;
        } else if (A[0][mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 0; 
    right = m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid][n - 1] == x) {
            cout << "Знайдено в останньому стовпці: A[" << mid << "][" << n - 1 << "] = " << x << endl;
            foundCol = true;
            break;
        } else if (A[mid][n - 1] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!foundRow && !foundCol) {
        cout << "Елемент " << x << " не знайдено ні у першому рядку, ні в останньому стовпці." << endl;
    }

    return 0;
}

