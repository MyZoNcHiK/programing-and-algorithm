#include<iostream>
#include<string>
using namespace std;

int head = 0;
int a[32];
void cycle(string cmd, int size);
void baseSyntax(string cmd){
    for(int i=0; i<(cmd.size()-1); i++){
        switch(cmd[i]){
            case '+': a[head]++; break;
            case '-': a[head]--; break;
            case '>': head++; break;
            case '<': head++; break;
            case '[': cycle(cmd, cmd.size()-1); break; 
        }
    }
    return;
}
void cycle(string cmd, int size){
    int end;
    string cmdInC;
    for(int i=head; i<size; i++){
        if(cmd[i] == '['){
            head++;
            cycle(cmd, cmd.size()-1);
        } else if(cmd[i] == ']'){
            end == i;    
        }
    }
    for(int i = head+1; i<end; i++){
       cmdInC[i-(head+1)] == cmd[i];
    }
    while(cmd[head]>0){
        baseSyntax(cmdInC);
    }
    return;
}
int main(){
    string cmd;
    cin >> cmd;
    baseSyntax(cmd);
    for(int x: a){cout << x << " ";}
    cout << endl;
    return 0;
}
