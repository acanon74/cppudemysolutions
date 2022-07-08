// Created on 07/07/22.


#ifndef POLYMORPHISM_TRUST_H
#define POLYMORPHISM_TRUST_H

#include "Account.h"


class Trust: public Account {

private:


    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_bonus = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;

protected:

    int num_withdrawals;
    double bonus;

public:


    Trust(string name = def_name, double balance = def_balance, double bonus = def_bonus);
    Trust(const Trust &source, double bonus);
    Trust(const Trust &&source, double bonus);
    virtual ~Trust() = default;

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

};


#endif //POLYMORPHISM_TRUST_H
