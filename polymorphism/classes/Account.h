// Created on 06/30/22.


#ifndef POLYMORPHISM_ACCOUNT_H
#define POLYMORPHISM_ACCOUNT_H

#include <iostream>
#include <string>
#include "../I_Printable.h"


class Account: public I_Printable {

private:

    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:

    string name;
    double balance;

public:

    Account(string name =def_name, const double balance = def_balance);
    Account(const Account &source);
    Account(const Account &&source);
    virtual ~Account() = default;

    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual string display() const override final;

};


#endif //POLYMORPHISM_ACCOUNT_H
