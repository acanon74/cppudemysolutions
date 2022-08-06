#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>


#include "Student.h"

using namespace std;

bool compare_answers(vector<char> corr, Student *stud);

int main() {

    ifstream file;

    string filepath = "../responses.txt";
    file.open(filepath, ios::in);

    if(!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        file.close();
        return -1;
    }

    string line;
    vector<char> correct_answers;
    vector<Student*> class_list;


    getline(file, line);

    for(int i{0}; i < line.size(); i++) {
        correct_answers.push_back(line[i]);
    }

    string curr_name;
    string curr_grades;
    vector<char> curr_list_grades;


    while(!file.eof()) {

        if(file.peek() == EOF) {
            break;
        }

        getline(file, curr_name);
        getline(file, curr_grades);


        for(char c: curr_grades) {
            curr_list_grades.push_back(c);
        }

        Student *curr_student = new Student(curr_name, curr_list_grades);

        class_list.push_back(curr_student);

        curr_list_grades.clear();

    }

    for(int i{0}; i < class_list.size(); i++) {

        compare_answers(correct_answers, class_list.at(i));
    }

    cout << "--------------------" << endl;
    cout << "| Student    Score |" << endl;
    cout << "--------------------" << endl;

    double total{0};

    for(Student *stud: class_list) {

        cout << setw(8) << stud->name;
        cout << setw(8) << stud->approved << endl;
        total += stud->approved;

    }



    cout << "--------------------" << endl;
    cout << "| Average :    " << (total/static_cast<double>(class_list.size())) << " |" << endl;
    cout << "--------------------" << endl;

/*
    for(int i{0}; i < class_list.size(); i++) {
        cout << (*(class_list.at(i))).name << endl;
        for( int j{0}; j < (*(class_list.at(i))).grades.size(); j++) {
            cout << (*(class_list.at(i))).grades.at(j) << endl;
        }
    }
*/

    class_list.erase(class_list.begin(), class_list.end());

    file.close();

    return 0;
}

bool compare_answers(vector<char> corr, Student *stud) {

    stud->approved = 0;

    if (corr.size() != stud->grades.size()) {
        cerr << "ERROR: Different answer sheet lengths" << endl;
        return false;
    }

    for(int i{0}; i < corr.size(); i++) {
        if(corr.at(i) == stud->grades.at(i)) {
            stud->approved++;
        }
    }

    return true;
}
