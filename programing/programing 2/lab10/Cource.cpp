#include"Course.h"

Course::Course(
    Teacher t,
    string disc, 
    int h=150, 
    int s, 
    string ctrl="Іспит", 
    int new_s) : 
    teacher(t),
    discipline(disc),
    hours(h),
    students(s),
    control_format(ctrl),
    new_students(new_s)
    {}
Teacher Course::get_Teacher() const{
    return t;
}
string Course::get_discipline() const{
    return discipline;
}
string Course::get_control_format() const{
    return control_format;
}
int Course::get_hours() const{
    return hours;
}
int Course::get_students() const{
    return students;
}
int Course::get_new_students() const{
    return new_students;
}
