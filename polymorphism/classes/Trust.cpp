// Created on 07/07/22.


#include "Trust.h"


Trust::Trust(const string &name, const double &balance, const double &bonus) : Account(name, balance), bonus{bonus} {
    max_withdrawals = 0;
}

Trust::Trust(const Trust &source, const double &bonus) : Account(source), bonus{bonus} {
    max_withdrawals = 0;
}

Trust::Trust(const Trust &&source, const double &bonus) : Account(source), bonus{bonus} {
    max_withdrawals = 0;
}


bool Trust::deposit(const double &amount) {

    if(amount >= 5000){
        return Account::deposit((amount+bonus));
    }
    else{
        return Account::deposit(amount);
    }
}


bool Trust::withdraw(const double &amount) {

    if(max_withdrawals < 3) {
        max_withdrawals++;
        return Account::withdraw(amount);
    }
    else if (max_withdrawals >= 3){
        cout << "Transaction with account" << *this << " not valid. [withdraw limit reached]" << endl;
    }
    else{
        cout << "Transaction with account" << *this << " not valid. [insufficient funds]" << endl;
        return false;
    }
}