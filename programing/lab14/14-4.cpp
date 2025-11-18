#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, surname, password;
    bool ok = true;

    cout << "Введіть ім'я: ";
    cin >> name;
    cout << "Введіть прізвище: ";
    cin >> surname;
    cout << "Введіть пароль: ";
    cin >> password;

    string passwordL = password, nameL = name, surnameL = surname;
    for(int i=0; i < passwordL.size(); i++){passwordL[i] = tolower(passwordL[i]);}
    for(int i=0; i < nameL.size(); i++){nameL[i] = tolower(nameL[i]);}
    for(int i=0; i < surnameL.size(); i++){surnameL[i] = tolower(surnameL[i]);}


    if (password.size() < 8) {
        cout << "Пароль повинен містити не менше 8 символів.\n";
        ok = false;
    }
    bool upper = false, lower = false, digit = false;
    for (char c : password) {
        if (isupper(c)){upper = true;}
        if (islower(c)){lower = true;}
        if (isdigit(c)){digit = true;}
    }
    if (!upper) { cout << "Пароль повинен містити хоча б одну велику літеру.\n"; ok = false; }
    if (!lower) { cout << "Пароль повинен містити хоча б одну малу літеру.\n"; ok = false; }
    if (!digit) { cout << "Пароль повинен містити хоча б одну цифру.\n"; ok = false; }

    if (passwordL.find(nameL) != string::npos && nameL.size() >= 3) {
        cout << "Пароль не повинен містити ім'я користувача.\n";
        ok = false;
    }
    if (passwordL.find(surnameL) != string::npos && surnameL.size() >= 3) {
        cout << "Пароль не повинен містити прізвище користувача.\n";
        ok = false;
    }
    bool namepart = false, surpart = false;
    for (int len = 3; len <= nameL.size(); len++) {
        for (int i = 0; i + len <= nameL.size(); i++) {
            string sub = nameL.substr(i, len);
            if (passwordL.find(sub) != string::npos) {
                namepart = true;
                ok = false;
            }
        }
    }

    for (int len = 3; len <= surnameL.size(); len++) {
        for (int i = 0; i + len <= surnameL.size(); i++) {
            string sub = surnameL.substr(i, len);
            if (passwordL.find(sub) != string::npos) {
                surpart = true;
                ok = false;
            }
        }
    }
    if(namepart){cout << "В паролі знайдено частину імені" << endl;}
    if(surpart){cout << "В паролі знайдено частину  прізвища" << endl;}
    if (ok) {
        cout << "Реєстрація успішна!" << endl;
    }

    return 0;
}

