// Created on 07/07/22.


#include "Trust.h"


Trust::Trust(string name, double balance, double bonus) : Account(name, balance), bonus{bonus} {}

Trust::Trust(const Trust &source, double bonus) : Account(source), bonus{bonus}{}

Trust::Trust(const Trust &&source, double bonus) : Account(source), bonus{bonus} {}


bool Trust::deposit(double amount) {

    if(amount >= bonus_threshold) {
        amount += bonus;
    }
    return Account::deposit(amount);
}


bool Trust::withdraw(double amount) {


    if(num_withdrawals >= max_withdrawals || (amount > balance*max_withdraw_percent)) {
        return false;
    }
    else{
        num_withdrawals++;
        return Account::withdraw(amount);
    }

}