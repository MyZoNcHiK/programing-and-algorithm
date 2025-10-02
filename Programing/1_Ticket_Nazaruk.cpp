#include<iostream>
using namespace std;

int main(){
    short num;
    cout << "Введіть номер завдання \n 0-Задача про потяг \n 1-Задача про квиток в кіно" << endl;
    cin >> num;
    if (num > 1){
        cout << "Такої опції немає" << endl;
    } else if(num == 0){
        int v, d, p, s;
        cout << "Введіть ціну квитка (грн)"<< endl;
        cin >> p;
        cout << "Введіть ваш баланс (грн)" << endl;
        cin >> s;
        if(s==0){
        cout << "Чого ви взагалі сюди прийшли?" << endl; 
        } else if(s<p){
            cout << "У вас недостатньо коштів щоб придбати квиток" << endl;
        } else if(s>p){
            cout << "Введіть відстань (км)" << endl;
            cin >> d;
            cout << "Введіть швидкість (км/год)" << endl;
            cin >> v;
            cout << "Ви прибудете о " << d/v+7 << " годині (цілочисельно)" << endl;
            cout << "Після купівлі квитка у вас залишиться " << s-p << " гривень" << endl;
        }
    } else if(num == 1){
    

    }
}
