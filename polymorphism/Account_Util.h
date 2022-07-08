// Created on 07/05/22.

#ifndef POLYMORPHISM_ACCOUNT_UTIL_H
#define POLYMORPHISM_ACCOUNT_UTIL_H


#include <vector>

#include "classes/Account.h"


void display(const vector<Account *> &accounts);
void deposit(vector<Account *> &accounts, double amount);
void withdraw(vector<Account *> &accounts, double amount);


#endif //POLYMORPHISM_ACCOUNT_UTIL_H