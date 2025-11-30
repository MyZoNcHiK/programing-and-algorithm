#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
    string n;
    cin >> n;
    cout << endl;

    int S = 0, nsize = 0, type = 0;

    for(int i = 0; i < n.length(); i++){
        if(!isdigit(n[i])){
            cout << "Номер містить недопустимі символи" << endl;
            return 1;
        }
    }

    if(n.length() == 15){
        nsize = 15;
        type = 1;
    } 
    else if(n.length() == 16){
        nsize = 16;
        type = 2;
    } 
    else if(n.length() == 20){
        nsize = 20;
        type = 3;
    } 
    else {
        cout << "Номер містить не відповідну кількість символів" << endl;
        return 1;
    }

    int num[25];

    for(int i = 0; i < nsize; i++){
        num[i] = n[i] - '0';
    }

    if(type == 1){//imei
        for(int i = nsize - 2; i >= 0; i--){
            int digitValue = num[i];

            if((nsize - 2 - i) % 2 == 0){
                digitValue *= 2;
                if(digitValue > 9) digitValue = (digitValue % 10) + 1;
            }

            S += digitValue;
        }

        int X = (10 - (S % 10)) % 10;

        if(X == num[nsize - 1])
            cout << "Контрольна цифра вірна" << endl;
        else
            cout << "Контрольна цифра не вірна" << endl;
    }
    if(type == 2){//карта
        S = 0;
        for(int i = nsize - 1; i >= 0; i--){
            int digitValue = num[i];

            if((nsize - 1 - i) % 2 == 1){ 
                digitValue *= 2;
                if(digitValue > 9) digitValue = (digitValue % 10) + 1;
            }

            S += digitValue;
        }

        if(S % 10 == 0)
            cout << "Контрольна сума вірна" << endl;
        else
            cout << "Контрольна сума не вірна" << endl;
    }
    if(type == 3){//iccid
        for(int i = nsize - 2; i >= 0; i--){
            int digitValue = num[i];

            if((nsize - 2 - i) % 2 == 0){
                digitValue *= 2;
                if(digitValue > 9) digitValue = (digitValue % 10) + 1;
            }

            S += digitValue;
        }

        int X = (10 - (S % 10)) % 10;

        if(X == num[nsize - 1])
            cout << "Контрольна цифра ICCID вірна" << endl;
        else
            cout << "Контрольна цифра ICCID не вірна" << endl;
    }

    return 0;
}

