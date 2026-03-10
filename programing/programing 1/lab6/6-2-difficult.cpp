#include<iostream>
using namespace std;
int main(){
    double x,a,b,c;
    cout << "Введіть проміжок:" << endl;
    cin >> a >> b;
    cout << "Введіть крок:" << endl;
    cin >> c;
    while(a<=b){
            cout << "x: " << a << " y: " << (a*2 + 22) << endl;
            a += c;
        }
}
