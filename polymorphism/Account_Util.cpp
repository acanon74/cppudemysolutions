// Created on 07/05/22.

#include "classes/Account.h"
#include "Account_Util.h"


void display(const vector<Account *> &accounts) {
    for(const auto i: accounts) {
        cout << *i << endl;
    }
}

void deposit(vector<Account *> &accounts, double amount) {
    for(auto i: accounts) {
        if(i->deposit(amount)) {
            cout << "Deposited " << amount << " to " << *i << endl;
        }
        else{
            cout << "Failed deposit of " << amount << " from " << *i << endl;
        }
    }
}

void withdraw(vector<Account *> &accounts, double amount) {

    for(const auto i: accounts) {
        if(i->withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << *i << endl;
        }
        else{
            cout << "Failed withdrawal of " << amount << " from " << *i << endl;
        }
    }

}
