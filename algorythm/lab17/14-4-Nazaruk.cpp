#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<double> s;
    double x, m = 0;
    while(cin >> x){
      s.push(x);
      if(s.top() > m){
        m = x;
      }
    } 
    while(!s.empty()){
      cout << s.top() << " ";
      s.pop();
    }
    return 0;
}