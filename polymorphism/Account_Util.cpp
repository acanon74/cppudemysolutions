// Created on 07/05/22.

#include "classes/Account.h"
#include "Account_Util.h"


void display(const vector<Account *> &accounts) {
    for(auto i: accounts) {
        cout << *i << endl;
    }
}

void deposit(const vector<Account *> &accounts, const double &amount) {
    for(auto i: accounts) {
        i->deposit(amount);
    }
}

void withdraw(const vector<Account *> &accounts, const double &amount) {

    for(auto i: accounts) {
        i->withdraw(amount);
    }
}
