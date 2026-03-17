#include <iostream>
using namespace std;

class AutoInsurance{
private:
    string type;
    int age;   
public:
    AutoInsurance(string t, int a){
        type = t;
        age = a;
    }
    AutoInsurance(AutoInsurance& toCopy){
        type = toCopy.type;
        age = toCopy.age;
    }
    AutoInsurance(int a){
        type = "економ";
        age = a;
    }
    void setType(string t){
        type = t;
    }
    void setAge(int a){
        age = a;
    }
    string getType() const{
        return type;
    }
    int getAge() const{
        return age;
    }
    int calculatePrice() const{
        if (type == "економ") return 3000;
        if (type == "стандарт") return 5000;
        if (type == "преміум") return 8000;
        return 0;
    }
    ~AutoInsurance(){
    }
};

int main() {
    string t;
    int a;
    cout << "Введіть тип авто (економ/стандарт/преміум): ";
    cin >> t;
    cout << "Введіть вік водія: ";
    cin >> a;

    AutoInsurance car1(t, a);
    AutoInsurance car2 = car1;
    AutoInsurance car3 = 25; // створюється авто 'економ'

    cout << "Страхування 1: " << car1.calculatePrice() << " грн" << endl;
    cout << "Страхування 2 (копія): " << car2.calculatePrice() << " грн" << endl;
    cout << "Страхування 3 (авто створено з віку): " << car3.calculatePrice() << " грн" << endl;

    return 0;
}
