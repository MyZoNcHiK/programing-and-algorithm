//Код переважно згенерований GPT проте він не зміг продумати логіку виходу з циклу і обмеження крайньої цифри в числі, тому я також приклав руку до цього
#include<iostream>
#include<vector>
using namespace std;

void NumN(int N){
    std::vector<long> a(N);
    for (int i;i<N;i++) a[i] = i;

    while(true){
        if(a[0] != 0){
            for(int x:a){cout << x;}
            cout << endl;
        }
        int pos = N-1;
        while(pos>=0 && a[pos] == 10-(N-pos))pos--;
        if(pos < 0) {break;}

        a[pos]++;
        for(int i = pos + 1; i < N; i++) {
            a[i] = a[i-1] +1;
        }
    }

}

int main(){
    int N;
    cin>>N;
    if(N>=10||N<=0){
        cout << "З таким N умова задачі нездійсненна(0<N<10)" << endl;
    } else {
        NumN(N);
    }
    return 0; 
}
