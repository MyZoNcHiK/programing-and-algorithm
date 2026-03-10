#include<fstream>
using namespace std;
int main() {
    int n = 30, start = 1;
    int a[n][n];

    int t = 0, b = n - 1, l = 0, r = n - 1;
    while (t <= b && l <= r) {
        for (int i = l; i <= r; i++){a[t][i] = start++;}
        t++;

        for (int i = t; i <= b; i++){a[i][r] = start++;}
        r--;

        for (int i = r; i >= l; i--){a[b][i] = start++;}
        b--;

        for (int i = b; i >= t; i--){a[i][l] = start++;}
        l++;
    }

    ofstream outfile("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){outfile << a[i][j] << "\t";}
        outfile << endl;
    }
    return 0;
}

