#include "Teacher.h"

Teacher::Teacher(string sr, string nm, string cath, int exp) : surname(sr), name(nm), cathedra(cath), exp(exp) {}

string Teacher::get_surname() const {
    return surname;
}

string Teacher::get_name() const {
    return name;
}

string Teacher::get_cathedra() const {
    return cathedra;
}

int Teacher::get_exp() const {
    return exp;
}