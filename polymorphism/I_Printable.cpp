//
// Created by USUARIO on 07/05/22.
//
#include <iostream>
#include "I_Printable.h"

string I_Printable::display() const {}

ostream &operator<<(ostream &os, const I_Printable &obj) {
    os << obj.display();
    return os;
}