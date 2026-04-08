#include<iostream>
using namespace std;

class Computer{
    private:
    int price;
    int characteristiks;
    public:
    Computer(int p, int c) : price(p), characteristiks(c){}

    virtual void call(){
        cout << "computer call" << endl;
    }
    virtual void sendMessege(){
        cout << "computer messege" << endl;
    }
};
class Phone{
    private:
    int price;
    int number;
    public:
    Phone(int p, int n) : price(p), number(n){}

    virtual void call(){
        cout << "phone call" << endl;
    }
    virtual void sendMessege(){
        cout << "phone messege" << endl;
    }
};
class Smartphone : virtual public Computer, virtual public Phone{
    private:
    int price;
    int number;
    int characteristiks;
    public:
    Smartphone(int p, int n, int c) : Computer(p, c), Phone(p, n), price(p), number(n), characteristiks(c){}

    void call () override{
        cout << "smartphone call" << endl;
    }
    void sendMessege() override{
        cout << "smartphone messege" << endl;
    }
};
int main(){
   Smartphone example(10000, 981234567, 8);
   example.call();
   example.sendMessege();
   return 0;
}
