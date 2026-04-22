#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Teacher.h"
using namespace std;

class Course {
private:
    string discipline, control_format;
    int hours, students, new_students;
    Teacher teacher;

public:
    Course(Teacher t, string disc, int h, int s, string ctrl, int new_s);

    Teacher get_teacher() const;
    void set_teacher(Teacher nt);
    
    string get_discipline() const;
    string get_control_format() const;
    int get_hours() const;
    int get_students() const;
    void set_students(int ns);
    int get_new_students() const;

    void info();
};

#endif