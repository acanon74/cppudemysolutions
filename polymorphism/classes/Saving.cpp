// Created on 07/05/22.


#include "Saving.h"


Saving::Saving(string name, double balance, double int_rate) : Account(name, balance), int_rate{int_rate} {}

Saving::Saving(const Saving &source, double int_rate) : Account(source), int_rate{int_rate} {}

Saving::Saving(const Saving &&source, double int_rate) : Account(source), int_rate{int_rate} {}


bool Saving::deposit(double amount) {

    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}


bool Saving::withdraw(const double amount) {
    return Account::withdraw(amount);
}