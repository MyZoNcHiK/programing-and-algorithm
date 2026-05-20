#include<iostream>
#include<string>
#include"Course.h"
#include"Teacher.h"
int main(){
    Teacher teach1("Булатецький", "Віталій", "Ком'ютерні науки та кібербезпека", 20);
    Teacher teach2("Борозинець", "Дмитро", "Комп'ютерні науки та кібербезпека", 12);
    Course course1(teach1, "Програмування мовою c++", 200, 40, "Іспит", 34);
    course1.set_teacher(teach2);
    course1.info();
    return 0;
}