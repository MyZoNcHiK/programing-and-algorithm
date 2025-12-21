#include <iostream>
using namespace std;

int main() {
    const int n = 9;
    int A[n][n] = {
        {0,1,1,0,0,0,0,0,0},
        {1,0,0,0,0,1,0,0,0},
        {1,0,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0},
        {0,0,0,1,0,1,0,0,0},
        {0,1,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,1,0}
    };

    cout << "Матриця суміжності:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << A[i][j] << " ";
        cout << "\n";
    }

    cout << "\nСписок суміжності:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        for (int j = 0; j < n; j++)
            for (int k = 0; k < A[i][j]; k++) cout << j+1 << " ";
        cout << "\n";
    }

    bool hasLoop = false, hasParallel = false;
    int degree[n] = {0}, isolated[n], isoCount = 0;

    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (A[i][i] > 0) hasLoop = true;
                deg += 2 * A[i][i];
            } else {
                deg += A[i][j];
                if (A[i][j] > 1 && i < j) hasParallel = true;
            }
        }
        degree[i] = deg;
        if (deg == 0) isolated[isoCount++] = i+1;
    }

    cout << "\nСтепені:\n";
    for (int i = 0; i < n; i++) cout << degree[i] << " ";
    cout << "\nПетлі: " << (hasLoop ? "є" : "немає") << "\n";
    cout << "Кратні: " << (hasParallel ? "є" : "немає") << "\n";
    cout << "Ізольовані: ";
    if (isoCount == 0) cout << "немає\n"; else {
        for (int i = 0; i < isoCount; i++) cout << isolated[i] << " ";
        cout << "\n";
    }

    const int m = 9;
    int M[n][m] = {
        {1,1,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,1},
        {0,1,0,1,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
        {0,0,1,0,0,1,1,0,0},
        {0,0,0,0,0,0,1,1,0},
        {0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,1}
    };

    cout << "\nСписок ребер:\n";
    for (int e = 0; e < m; e++) {
        int u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (M[i][e] == 1) {
                if (u == -1) u = i+1; else v = i+1;
            } else if (M[i][e] == 2) { u = i+1; v = i+1; }
        }
        cout << u << "-" << v << "\n";
    }

    return 0;
}

