// Created on 06/30/22.


#ifndef POLYMORPHISM_ACCOUNT_H
#define POLYMORPHISM_ACCOUNT_H

#include <iostream>
#include <string>
#include "../I_Printable.h"


class Account: public I_Printable {

private:

    string name;
    double balance;

public:

    Account(const string &name, const double &balance = 0.0);
    Account(const Account &source);
    Account(const Account &&source);
    virtual ~Account() = default;

    virtual bool deposit(const double &amount) = 0;
    virtual bool withdraw(const double &amount) = 0;
    virtual string display() const override final;

};


#endif //POLYMORPHISM_ACCOUNT_H
