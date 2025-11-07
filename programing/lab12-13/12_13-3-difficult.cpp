#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;
const int M = 3;

void inputResults(double results[N][M]){
    for(int i = 0; i < N; i++){
        cout << "Спортсмен " << i + 1 << ":\n";
        for(int j = 0; j < M; j++){
            cout << "  Вправа " << j + 1 << ": ";
            cin >> results[i][j];
        }
    }
}

void printResults(double results[N][M]){
    cout << "\nРезультати:\n";
    cout << setw(12) << "Спортсмен ";
    for(int j = 0; j < M; j++){
        cout << setw(10)  << "Вправа " + to_string(j + 1) << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << setw(3) << i + 1;
        for(int j = 0; j < M; j++){
            cout << setw(10) << results[i][j];
        }
        cout << endl;
    }
}

void calcTotal(double results[N][M], double total[N]){
    for(int i = 0; i < N; i++){
        total[i] = 0;
        for(int j = 0; j < M; j++){
            total[i] += results[i][j];
        }
    }
}

int findWinner(double total[N]){
    int winner = 0;
    for(int i = 1; i < N; i++){
        if(total[i] > total[winner]){
            winner = i;
        }
    }
    return winner;
}

int countBelowAverage(double total[N]){
    double sum = 0;
    for(int i = 0; i < N; i++){
        sum += total[i];
    }
    double avg = sum / N;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(total[i] < avg){
            count++;
        }
    }
    return count;
}

int main(){
    double results[N][M];
    double total[N];
    inputResults(results);
    printResults(results);
    calcTotal(results, total);
    cout << "\nСумарні бали спортсменів:\n";
    for(int i = 0; i < N; i++){
        cout << "Спортсмен " << i + 1 << ": " << total[i] << endl;
    }
    int winner = findWinner(total);
    cout << "\nПереможець: спортсмен " << winner + 1
         << " (бал = " << total[winner] << ")" << endl;
    int below = countBelowAverage(total);
    cout << "Кількість спортсменів нижче середнього: " << below << endl;
    return 0;
}

