// Created on 07/05/22.


#ifndef POLYMORPHISM_SAVING_H
#define POLYMORPHISM_SAVING_H

#include "Account.h"


class Saving: public Account {

private:

    static constexpr const char *def_name = "Unnamed Saving Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:

    double int_rate;

public:

    Saving(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    Saving(const Saving &source, double int_rate);
    Saving(const Saving &&source, double int_rate);
    virtual ~Saving() = default;

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

};


#endif //POLYMORPHISM_SAVING_H
