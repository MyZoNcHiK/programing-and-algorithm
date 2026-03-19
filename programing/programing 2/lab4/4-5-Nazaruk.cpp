#include<iostream>
#include<vector>
using namespace std;

class MAU{
    private:
    string name, type, time;
    int number;
    public:
    MAU(string name,int number, string type, string time){
        this->name = name;
        this->type = type;
        this->number = number;
        this->time = time;
    } 
    string getName() const{
        return name;
    }
    int getNumber() const{
        return number;
    }
    string getType() const{
        return type;
    }
    string getTime() const{
        return time;
    }
};
void flightTo(string name, vector<MAU> v){
    int num=0;
    for(int i=0; i<v.size();i++){
        if(v[i].getName() == name){
            cout << "Рейс номер: " << v[i].getNumber() << " Відправляється о: " << v[i].getTime() << endl;
            num++;
        }
    }
    if(num>0){
    cout << "До " << name << " прямує " << num << " рейсів." << endl;
    } else { cout << "До " << name << " не прямує жодного рейсу" << endl;}
} 
int main(){
    string name, type, time;
    int number, n;
    vector<MAU> SCHEDULE;
    cout << "Введіть кількість рейсів" << endl;
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << "Введіть данні про рейс №" << i << " (пукнт призначення, номер рейсу, тип літака, час відправлення)" << endl;
        cin >> name >> number >> type >> time;
        MAU mau(name, number, type, time);
        SCHEDULE.push_back(mau);
    }
    string nameTo;
    cout << "Введіть місце призначення" << endl;
    cin >> nameTo;
    flightTo(nameTo, SCHEDULE);
    return 0;    
}
