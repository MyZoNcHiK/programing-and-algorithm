#include<iostream>
using namespace std;

int main(){
    double t=10;
    for(int i=2;i<=10;i++){
        t*=1.1; 
        cout << "День:" << i << " Пробіг:" << t << endl;
    }
    double sum=10;
    for(int i=2;i<=7;i++){
        t*=1.1; 
        sum+=t;
    }
    cout << "На 7 день сумарний пробіг:" << sum << endl;
    return 0;
}
