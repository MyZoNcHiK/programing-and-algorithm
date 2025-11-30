#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string text;
    getline(cin, text);
    for(int i=0; i<text.length();i++){
        if(text[i]==' '){
            continue;
        } else {
            text[i] += 4;
        }
    }
    cout << text << endl;

    cout << "Розшифрований текст" << endl;
    for(int i=0; i<text.length();i++){
        if(text[i]==' '){
            continue;
        } else {
            text[i] -= 4;
        }
    }
    cout << text << endl;
}
