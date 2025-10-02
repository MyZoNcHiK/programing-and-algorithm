#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Введіть чотиризначне число" << endl;
    cin >> n;
    int d = n%10;
    int c = (n%100-d)/10;
    cout << "В вашому числі " << c << " десятків та " << d << " одиниць" << endl;
}
