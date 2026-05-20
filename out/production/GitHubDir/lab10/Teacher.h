#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher {
private:
    string surname, name, cathedra;
    int exp;

public:
    Teacher(string sr, string nm, string cath, int exp);
    string get_surname() const;
    string get_name() const;
    string get_cathedra() const;
    int get_exp() const;
};

#endif