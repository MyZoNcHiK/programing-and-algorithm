#include<iostream>
#include<cstdlib>
#include<ctime>
#include<thread>
#include<chrono>
#include<iomanip>
using namespace std;

//повертає псевдовипадкове число
int randomNum(int min, int max){
    srand(time(0));
    int r = min + rand() % max;
    return r;
}
//Перша гра 
int findNumber(int bal){
    bal -= 50;
    int n = 0, r = randomNum(1, 100);
    for(int i=5; i>1; i--){
        cout << "Залишилось " << i << " Спроб\nСпробуйте відгадати число" << endl;
        cin >> n;
        cout << endl;
        if (n==r){
            cout << "Вітаю! Ви відгадали число\n" << endl;
            return bal += 250;
        } else if(n>r){
            cout << "Менше\n" << endl;
        } else {
            cout << "Більше\n" << endl;
        }
    }
    cout << "Залишилась остання спроба\nВипробуйте удачу" << endl;
    cin >> n;
    if(n==r){
        cout << "Вітаю! Цього разу вам пощастило, ви відгадали число" << endl;
        return bal += 250;
    } else if(n<r&&n>=(r-2)||n>r&&n<=(r+2)){
        cout << "Отакої, ви були дуже близько, було загадане число: " << r << "\nМожете спробувати ще раз" << endl;
        return bal += 50;
    } else {
        cout << "Пощастить іншим разом! Було загадане число: " << r << endl;
        return bal;
    }
}

//Друга гра
int gameMachine(int bal){
    bal -= 50;
    const int n = 3;
    int res[n];

    cout << "\r";

    for (int i = 0; i < n; i++) {
        int r, spins = 40;

        for (int s = 0; s < spins; s++) {
            r = randomNum(1, 10);

            string output;
            for (int j = 0; j < n; j++) {
                if (j < i) output += to_string(res[j]);
                else if (j == i) output += to_string(r);
                else output += " ";
                if (j < n - 1) output += " ";
            }

            cout << "\r" << string(20,' ') << "\r";
            cout << left << setw(2) << output << flush;
            this_thread::sleep_for(chrono::milliseconds(80 + s * 5));
        }

        res[i] = r;
    }
    cout << "\n" << endl;
    bool win = (res[0] == res[1] == res[2]);
    bool miniWin = (res[0] == res[1] || res[0] == res[2] || res[1] == res[2]);
    if(win){
        cout << "Джекпот!!!" << "\n" << endl;
        bal += 350;
    } else if(miniWin){
        cout << "Ви були близько! Може спробуєте ще разок?" << "\n" << endl;
        bal += 150;
    } else cout << "Пощастить наступного разу!" << "\n" << endl;
    return bal;
}

//третя гра
int rummy(int bal){
   
    return bal;
}

//четверта гра
int nim(int bal){
    
    return bal;
}

//п'ята гра
int bullsAndCows(int bal){
    
    return bal;
}

//правила
void rules(){
    cout << "1: Знайди приховане число\nCпроба: 50 жетонів    Виграш: 100 жетонів    Частковий виграш: 50 жетонів\n\nМашина загадує число від 1 до 100\nВи повинні відгадати його завдяки підказкам за обмежену к-ть спроб\n" << endl;
    cout << "2: Ігровий автомат\nОдин оберт: 50 жетонів    Джекпот: 300 жетонів    Частковий виграш: 100 жетонів\n\nГенеруються три випадкових числа\nЯкщо вони збігаються, то баланс росте\n" << endl;
}

//функція для вибору гри
void choseGame(int bal){
    int g;
    cout << "Ваш баланс: " << bal << "\nОберіть гру в яку хочете зіграти" << endl;
    cout << "1: Знайди приховане число\n2: Ігровий автомат\n3: Rummy\n4: Нім\n5: Бики і корови\n6: Правила ігор" << endl;
    cin >> g;
    cout << "\n" << endl;
    switch(g){
        case 1: choseGame(findNumber(bal)); break;
        case 2: choseGame(gameMachine(bal)); break;
        case 3: choseGame(rummy(bal)); break;
        case 4: choseGame(nim(bal)); break;
        case 5: choseGame(bullsAndCows(bal)); break;
        case 6: rules(); choseGame(bal); break;
    }
}
int main(){
    int bal = 500;
    choseGame(bal);
}
