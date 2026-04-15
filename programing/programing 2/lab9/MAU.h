#ifndef lab9
#define lab9
#include<iostream>
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
#endif