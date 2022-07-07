// Created on 06/30/22.


#ifndef POLYMORPHISM_CHECKING_H
#define POLYMORPHISM_CHECKING_H

#include "Account.h"


class Checking: public Account {

private:

    string name;
    double balance;
    double fee;

public:

    Checking(const string &name, const double &balance = 0.0, const double &fee = 0.0);
    Checking(const Checking &source, const double &fee);
    Checking(const Checking &&source, const double &fee);
    virtual ~Checking() = default;

    virtual bool deposit(const double &amount) override;
    virtual bool withdraw(const double &amount) override;

};


#endif //POLYMORPHISM_CHECKING_H
