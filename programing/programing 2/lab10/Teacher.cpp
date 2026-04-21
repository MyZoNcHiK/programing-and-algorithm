#include"Teacher.h"

Teacher::Teacher(
    string sn, 
    string cath, 
    int exp) : 
     surname_name(sn),
     cathedra(cath), 
     exp(exp), 
    {}
string Teacher::get_surname_name() const{
    return surname_name;
}
string Teacher::get_cathedra() const{
    return cathedra;
}
string Teacher::get_discipline() const{
    return discipline;
}
string Teacher::get_control_format() const{
    return control_format;
}
int Teacher::get_exp() const{
    return exp;
}
