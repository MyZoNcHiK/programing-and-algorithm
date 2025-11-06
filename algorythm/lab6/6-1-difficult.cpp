#include<iostream>
using namespace std;
int main(){
    double x, s = 0;
    cin >> x;
    double u1 = -x;
    for(int k=1;k<=6;k++){
        u1 *= -x;
        s += u1/(k*k);
        cout << "s" << k << ": " << s << endl;
    }
}
