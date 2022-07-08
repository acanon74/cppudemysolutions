// Created on 06/30/22.


#include "Checking.h"


Checking::Checking(string name, double balance, double fee) : Account(name, balance), fee{fee} {}

Checking::Checking(const Checking &source, double fee) : Account(source), fee{fee} {}

Checking::Checking(const Checking &&source, double fee) : Account(source), fee{fee} {}


bool Checking::deposit(double amount) {
    return Account::deposit(amount);
}


bool Checking::withdraw(double amount) {
    return Account::withdraw(amount+fee);
}