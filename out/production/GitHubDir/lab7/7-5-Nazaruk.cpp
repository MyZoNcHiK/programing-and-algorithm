#include<iostream>
using namespace std;

class B1{
    private:
    int a;
    public:
    B1(int x) : a(x){}

    void show_B1() const{
    cout << "B1=" << a << endl;
    }
};
class B2{
    private:
    int b;
    public:
    B2(int x) : b(x){}

    void show_B2() const{
    cout << "B2=" << b << endl;
    }
};
class D1 : virtual public B1 {
    private:
    int c;
    public:
    D1(int x, int y) : c(x), B1(y){}

    void show_D1() const{
    cout << "D1=" << c << endl;
    }
};
class D2 : virtual private B1 {
    private:
    int d;
    public:
    D2(int x, int y) : d(x), B1(y){}

    void show_D2() const{
    cout << "D2=" << d << endl;
    }

};
class D4 : public B2, public D1, public D2{
    private:
    int e;
    public:
    D4(int x, int y, int z, int w, int q) : e(x),B1(y), B2(z), D1(w, y), D2(q, y){}
 
    void show() const{
        show_B1();
        show_B2();
        show_D1();
        show_D2();
        cout << "D4=" << e << endl;
    }
};
int main(){
    D4 example(5, 1, 2, 3, 4);
    example.show();
    return 0;
}
