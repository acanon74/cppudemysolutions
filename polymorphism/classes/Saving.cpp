// Created on 07/05/22.


#include "Saving.h"


Saving::Saving(const string &name, const double &balance, const double &int_rate) : Account(name, balance), int_rate{int_rate} {}

Saving::Saving(const Saving &source, const double &int_rate) : Account(source), int_rate{int_rate} {}

Saving::Saving(const Saving &&source, const double &int_rate) : Account(source), int_rate{int_rate} {}


bool Saving::deposit(const double &amount) {

    if (int_rate == 0) {
        return Account::deposit(amount);

    } else {
        return Account::deposit(amount+(amount * int_rate));
    }
}


bool Saving::withdraw(const double &amount) {
    return Account::withdraw(amount);
}