#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string H = "Nazaruk";
    int H0 = 7, N = 13*31;
    for(int i=0; i<H.length(); i++){
        H0 = ((H0+H[i])*(H0+H[i]))%N;
    }
    cout << H0 << endl;
}
