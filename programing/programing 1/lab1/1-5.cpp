#include<iostream>
using namespace std;

int main(){
    int N;
    cout << "Введіть скільки секунд пройшло з початку доби" << endl;
    cin >> N;
    int h = N/3600;
    int m = (N-h*3600)/60;
    int s = N-h*3600-m*60;
    
    cout << "Годинник покаже " << h <<":"<< m <<":"<< s << endl;
}
