// Created on 07/19/22.

#include "Student.h"

#include <string>
#include <vector>

using namespace std;

Student::Student() : Student("NULL", vector<char>(0)) {}
Student::Student(string name, vector<char> grades) : name{name}, grades{grades} {}