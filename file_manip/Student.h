// Created on 07/19/22.

#ifndef FILE_MANIP_STUDENT_H
#define FILE_MANIP_STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {

public:

    string name;
    vector<char> grades;
    int approved;

    Student();
    Student(string name, vector<char> grades);

};

#endif FILE_MANIP_STUDENT_H
