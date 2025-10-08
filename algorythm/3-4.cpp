#include<iostream>
using namespace std;
int tariff(int h){
    int sum;
    if(h<=2){
        sum = h*20;
    } else if(h<=5){
        sum = h*15;
    } else if (sum>5){
        sum = h*10; 
    }
    if(sum>100){sum = sum - sum/10;}
    return sum;
}
int main(){
    int h;
    cout << "Введіть кількість годин" << endl;
    cin >> h;
    cout << tariff(h) << endl;
}
