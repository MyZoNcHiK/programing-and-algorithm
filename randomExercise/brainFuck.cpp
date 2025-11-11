#include <iostream>
#include <string>
#include <vector>
using namespace std;

int head = 0;
int a[32] = {0};

void baseSyntax(string& cmd);

void cycle(string& cmd, int& i) {
    int start = i;
    string partCmd;
    int depth = 1;

    for (int j = i + 1; j < cmd.size(); j++) {
        if (cmd[j] == '['){depth++;}
        else if (cmd[j] == ']'){depth--;}
        if (depth == 0) {
            partCmd = cmd.substr(i + 1, j - i - 1); 
            i = j; 
            break;
        }
    }

    while (a[head] != 0) {
        baseSyntax(partCmd);
    }
}

void baseSyntax(string& cmd) {
    for (int i = 0; i < cmd.size(); i++) {
        switch (cmd[i]) {
            case '+': a[head]++; break;
            case '-': a[head]--; break;
            case '>': head++; break;
            case '<': head--; break;
            case '[': cycle(cmd, i); break;
            default: break;
        }
        if(head == -1||head==32) {
            cout << "Помилка: вихід за межі пам'яті" << endl;
            break;
        }
        if(a[head]==-1){
           a[head] = 255; 
        }
    }
}

int main() {
    string cmd;
    cin >> cmd;

    baseSyntax(cmd);

    for (int x : a){cout << x << " ";}
    cout << endl;
    return 0;
}

