#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int rnd(int a, int b){ return a + rand() % (b - a + 1); }
int main(){
    srand(time(0));
    vector<int> v(90);

    for(int i = 0; i < 90; i++){v[i] = rnd(35, 45);}

    cout << "Курс за 90 днів:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 30; j++){cout << v[j+i*30] << " ";}
        cout << endl;
    }

    int jump, maxJump = 0;
    for(int i = 1; i < 90; i++){
        jump = abs(v[i] - v[i-1]);
        if(maxJump < jump){maxJump = jump;}
    }
    cout << "Найбільший стрибок: " << maxJump << "\n";

    int mins = 0, maxs = 0;
    for(int i = 1; i < 89; i++){
        if(v[i] < v[i-1] && v[i] < v[i+1]){mins++;}
        if(v[i] > v[i-1] && v[i] > v[i+1]){maxs++;}
    }
    cout << "Локальних мінімумів: " << mins << ", максимумів: " << maxs << "\n";

    int seg  = 1, best = 1;
    for(int i = 1; i < 90; i++){
        if(v[i] > v[i-1]){seg++;}
        else {seg = 1;}
        if(seg > best){best=seg;}
    }
    cout << "Найдовше зростання: " << best << " днів\n";
}

