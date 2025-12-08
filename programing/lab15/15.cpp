#include <iostream>
#include <string>
using namespace std;

struct Company {
    string name;
    string industry;
    string address;

    void init(string n, string ind, string addr) {
        name = n;
        industry = ind;
        address = addr;
    }

    void print(){
        cout << "Назва: " << name << '\n'
             << "Галузь: " << industry << '\n'
             << "Адреса: " << address << '\n';
    }
};

struct Employee {
    string name;
    string position;
    Company company;

    void init(string n, string pos, Company comp) {
        name = n;
        position = pos;
        company = comp;
    }

    void print(){
        cout << "Ім'я: " << name << '\n'
             << "Посада: " << position << '\n';
        company.print();
    }
};

int main() {
    Company comp;
    comp.init("Corgun.Inc", "Інформаційні технології", "Балка");

    Employee emp;
    emp.init("Назарук Максим", "Software Engineer", comp);

    emp.print();
    return 0;
}

