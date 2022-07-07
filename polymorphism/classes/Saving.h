// Created on 07/05/22.


#ifndef POLYMORPHISM_SAVING_H
#define POLYMORPHISM_SAVING_H

#include "Account.h"


class Saving: public Account {

private:

    string name;
    double balance;
    double int_rate;

public:

    Saving(const string &name, const double &balance = 0.0, const double &int_rate = 0.0);
    Saving(const Saving &source, const double &int_rate);
    Saving(const Saving &&source, const double &int_rate);
    virtual ~Saving() = default;

    virtual bool deposit(const double &amount) override;
    virtual bool withdraw(const double &amount) override;

};


#endif //POLYMORPHISM_SAVING_H
