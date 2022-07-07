// Created on 07/07/22.


#ifndef POLYMORPHISM_TRUST_H
#define POLYMORPHISM_TRUST_H

#include "Account.h"


class Trust: public Account {

private:

    string name;
    double balance;
    double bonus;
    int max_withdrawals;

public:


    Trust(const string &name, const double &balance = 0.0, const double &bonus = 0.0);
    Trust(const Trust &source, const double &bonus);
    Trust(const Trust &&source, const double &bonus);
    virtual ~Trust() = default;

    virtual bool deposit(const double &amount) override;
    virtual bool withdraw(const double &amount) override;

};


#endif //POLYMORPHISM_TRUST_H
