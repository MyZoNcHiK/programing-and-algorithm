#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(Teacher t, string disc, int h, int s, string ctrl, int new_s)
    : teacher(t), discipline(disc), hours(h), students(s),
      control_format(ctrl), new_students(new_s) {}

Teacher Course::get_teacher() const {
    return teacher;
}

void Course::set_teacher(Teacher nt) {
    teacher = &nt;
}

string Course::get_discipline() const {
    return discipline;
}

string Course::get_control_format() const {
    return control_format;
}

int Course::get_hours() const {
    return hours;
}

int Course::get_students() const {
    return students;
}

void Course::set_students(int ns) {
    students = ns;
}

int Course::get_new_students() const {
    return new_students;
}

void Course::info() {
    cout << "Курс: " << discipline
         << "\nВикладач: " << teacher.get_surname() << " " << teacher.get_name()
         << "\nКафедра: " << teacher.get_cathedra()
         << "\nСтаж: " << teacher.get_exp()
         << "\nКількість годин: " << hours
         << "\nСтудентів: " << students
         << "\nФорма контролю: " << control_format << endl;
}