//
// Created by USUARIO on 07/05/22.
//

#ifndef POLYMORPHISM_I_PRINTABLE_H
#define POLYMORPHISM_I_PRINTABLE_H

#include <iostream>
#include <string>

using namespace std;

class I_Printable {

    friend ostream &operator<<(ostream &os, const I_Printable &obj);

public:

    virtual string display() const;
    virtual ~I_Printable() = default;
};


#endif //POLYMORPHISM_I_PRINTABLE_H
