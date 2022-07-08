// Created on 06/30/22.


#include "Account.h"

Account::Account(const string &name, const double &balance) : name{name}, balance{balance} {}

Account::Account(const Account &source) : Account(source.name, source.balance) {}

Account::Account(const Account &&source) : Account(source.name, source.balance) {}

bool Account::deposit(const double &amount) {
    return (this->balance += amount);
}


bool Account::withdraw(const double &amount) {
    if((balance-amount) > 0){
        balance -= amount;
        return true;
    }
    else{
        cout << "Transaction on account " << *this << " not valid. [insufficient funds]" << endl;
        return false;
    }
}

string Account::display() const {
    return name + " : " + to_string(balance);
}