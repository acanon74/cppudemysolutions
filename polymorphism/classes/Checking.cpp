// Created on 06/30/22.


#include "Checking.h"


Checking::Checking(const string &name, const double &balance, const double &fee) : Account(name, balance), fee{fee} {}

Checking::Checking(const Checking &source, const double &fee) : Account(source), fee{fee} {}

Checking::Checking(const Checking &&source, const double &fee) : Account(source), fee{fee} {}


bool Checking::withdraw(const double &amount) {
    return Account::withdraw((amount+fee));
}


bool Checking::deposit(const double &amount) {
    return Account::deposit(amount);
}