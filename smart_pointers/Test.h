// Created on 07/09/22.

#ifndef SMART_POINTERS_TEST_H
#define SMART_POINTERS_TEST_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {

    friend ostream &operator<<(ostream &os, const Test &obj);

private:
    int data;

public:
    Test();
    Test(int data);
    int get_data() const;
    ~Test();
};


#endif //SMART_POINTERS_TEST_H
