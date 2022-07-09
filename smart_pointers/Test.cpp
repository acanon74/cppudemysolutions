// Created on 07/09/22.

#include "Test.h"


Test::Test() : data{0} {
    cout << "-Test constructor (" << data << ")" << endl;
}

Test::Test(int data) : data{data} {
    cout << "-Test constructor (" << this->data << ")" << endl;
}

int Test::get_data() const {
    return data;
}

Test::~Test() {
    cout << "-Test destructor (" << data << ")" << endl;
}

ostream &operator<<(ostream &os, const Test &obj) {
    os << obj.get_data();
    return os;
}