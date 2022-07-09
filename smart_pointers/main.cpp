#include <iostream>
#include <memory>
#include <vector>

#include "Test.h"

using namespace std;


unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &v, int n);
void display(const vector<shared_ptr<Test>> &v);


unique_ptr<vector<shared_ptr<Test>>> make() {
    unique_ptr<vector<shared_ptr<Test>>> unq = make_unique<vector<shared_ptr<Test>>>();
    return unq;
}


void fill(vector<shared_ptr<Test>> &v, int n) {

    for(int i{0}; i < n; i++){

        int input{0};
        cout << "Enter data point [" + to_string(i) + "] : ";
        cin >> input;

        v.push_back(make_shared<Test>(input));
    }
}


void display(const vector<shared_ptr<Test>> &v) {

    for(int i{0}; i < v.size(); i++) {

        cout << *(v.at(i)) << endl;
    }
}

int main () {

    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;

}