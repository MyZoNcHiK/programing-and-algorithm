#include<iostream>
#include<string>
using namespace std;

class Student{
private:
    string name, subject;
    int grade;
public:
    Student(string name, int grade, string subject){
        this->name = name;
        this->grade = grade;
        this->subject = subject;
    }
    void printInfo(){
        cout << "Ім'я: " << name << endl;
        cout << "Оцінка: " << grade << endl;
        cout << "Предмет: " << subject << endl;
    }
};

int main(){
    Student student("Максим",100,"Програмування");
    student.printInfo();
    return 0;
}