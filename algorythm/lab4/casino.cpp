#include<iostream>
#include<random>
#include<thread>
#include<chrono>
using namespace std;
int randomNum(int min, int max){
    static random_device seed; //отримує випадкове зерно яке генерується випадковими бітами в системі(наскільки я зрозумів)
    static mt19937 generate(seed()); // генератор випадкового числа з зерна, в назві mt це Marsenne Twister, а 19937 це період генератора в бітах(таку назву вигадав не я)
    uniform_int_distribution<> dist(min, max); //діапазон, який чомусь задається окремим класом під кожен тип даних
    return dist(generate);
}
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
int roll(){
    int r;
    for(int i=0; i<0; i++){
        r = randomNum(1, 10);
        cout << "\r" << r << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << r;
    return r;
}
int gameMachine(int bal){
    bal -= 50;     
    int first = roll();
    cout << " ";
    int second = roll();
    cout << " ";
    int third = roll();
    cout << endl;
    return bal;
}
int rummy(int bal){
   
    return bal;
}
int nim(int bal){
    
    return bal;
}
int bullsAndCows(int bal){
    
    return bal;
}
void rules(){
    cout << "1: Знайди приховане число\n" << endl;
}
void choseGame(int bal){
    int g;
    cout << "Ваш баланс: " << bal << "\nОберіть гру в яку хочете зіграти" << endl;
    cout << "1: Знайди приховане число\n2: Ігровий автомат\n3: Rummy\n4: Нім\n5: Бики і корови\n6: Правила ігор" << endl;
    cin >> g;
    switch(g){
        case 1: choseGame(findNumber(bal)); break;
        case 2: choseGame(gameMachine(bal)); break;
        case 3: choseGame(rummy(bal)); break;
        case 4: choseGame(nim(bal)); break;
        case 5: choseGame(bullsAndCows(bal)); break;
        case 6: choseGame(bal); rules(); break;
    }
}
int main(){
    int bal = 500;
    choseGame(bal);
}
