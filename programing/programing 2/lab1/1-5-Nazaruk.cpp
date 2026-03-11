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
    string _str_(){
        return name + " " + subject + " " + to_string(grade);
    }
    void printInfo(){
        cout << this->_str_() << endl;
    }
};

int main(){
    Student student("Максим",100,"Програмування");
    student.printInfo();
    return 0;
}
