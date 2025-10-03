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
        while(pos>=0 && a[pos] == 10-(N-pos))
            pos--;
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
   NumN(N);
   return 0; 
}
