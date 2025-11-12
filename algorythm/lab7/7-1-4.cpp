#include<iostream>
using namespace std;
int main(){
    int a, z=-1, buf;
    cin >> a;
    int A[a];
    for(int i = 0; i<a; i++){
        cin >> A[i];
        if(A[i]==0){ z=i; buf=A[i];}
    }
    for(int i = a-1; i>0; i--){
        if(A[i]<0){
        A[z] = A[i];
        A[i] = buf; 
        break;}
    }
    for(int i = 0; i<a; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
