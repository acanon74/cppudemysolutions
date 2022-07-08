// Created on 06/30/22.


#ifndef POLYMORPHISM_CHECKING_H
#define POLYMORPHISM_CHECKING_H

#include <iostream>
#include <string>

#include "Account.h"


class Checking: public Account {

private:

    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;

protected:

    double fee;

public:

    Checking(string name = def_name, double balance = def_balance, double fee = def_fee);
    Checking(const Checking &source, double fee);
    Checking(const Checking &&source, double fee);
    virtual ~Checking() = default;

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

};


#endif //POLYMORPHISM_CHECKING_H
