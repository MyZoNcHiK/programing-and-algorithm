#include<iostream>
using namespace std;

class Like{
    private:
        int count;
    public:
        Like(int c) : count(c){}
        Like operator++(){count++; return *this;}
        Like operator--(){count--; return *this;}
        bool operator<(Like l){
            if(this->count < l.count){return true;}
                else return false;
        }
        bool operator>(Like l){
            if(this->count > l.count){return true;} 
                else return false;
        }
        int getCount() const{
            return count;
        }
};
int main(){
    Like like1(15), like2(20);
    ++like1;
    --like2;
    cout << like1.getCount() << " " << like2.getCount() << endl;
    if(like1 < like2){
        cout << "Перше менше" << endl;
    } else if(like1 > like2){
        cout << "Перше більше" << endl; 
    }
}
