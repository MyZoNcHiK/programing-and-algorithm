#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string n;
    cin >> n;
    cout << endl; 
    int S = 0,nsize,type;

    for(int i=0; i<n.length(); i++){
        if(!isdigit(n[i])){
            cout << "Номер містить недопустимі символи" << endl;
            return 1;
        }
    }
    if(n.length() == 14){
    nsize = 14;
    type = 1;
    } else if (n.length() == 16){
    nsize = 16;
    type = 2;
    } else if (n.length() == 19){
    nsize = 19; 
    type = 3;
    } else { 
        cout << "Номер містить не відповідну кількість символів" << endl;
    }
    int num[nsize];
    for(int i=0; i<n.length(); i++){
        num[i] = n[i] - '0';
    }
    for(int i=0; i<n.length()-1; i += 2){
        num[i] *= 2;
        int l = num[i] % 10;
        if(num[i] > 9){        
            num[i] = l+1;
        }
    } 
    for(int i=0; i<n.length(); i++){
        S += num[i];
    }
    cout << endl << S << endl;
    if(type == 1){
        if((S*9)%10 == num[nsize-1]){
            cout << "Контрольна цифра вірна" << endl;
        } else {
            cout << "Контрольна цифра не вірна" << endl;
        }
    } else if(type == 2){
        if(S%10==0){
            cout << "Контрольна сума вірна" << endl;
        } else {
            cout << "Контрольна сума не вірна" << endl;
        }
    } 
    return 0;
}
