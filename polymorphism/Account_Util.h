// Created on 07/05/22.

#ifndef POLYMORPHISM_ACCOUNT_UTIL_H
#define POLYMORPHISM_ACCOUNT_UTIL_H

#include <iostream>
#include <string>
#include <vector>

#include "classes/Account.h"

void display(const vector<Account *> &accounts);
void deposit(const vector<Account *> &accounts, const double &amount);
void withdraw(const vector<Account *> &accounts, const double &amount);

#endif //POLYMORPHISM_ACCOUNT_UTIL_H