// Created on 06/30/22.


#include "Account.h"

Account::Account(string name, double balance) : name{name}, balance{balance} {}

Account::Account(const Account &source) : Account(source.name, source.balance) {}

Account::Account(const Account &&source) : Account(source.name, source.balance) {}

bool Account::deposit(double amount) {

    if(amount < 0){
        return false;
    }
    else{
        balance += amount;
        return true;
    }
}


bool Account::withdraw(double amount) {
    if((balance-amount) >= 0){
        balance -= amount;
        return true;
    }
    else{
        return false;
    }
}

string Account::display() const {
    return name + " : " + to_string(balance);
}