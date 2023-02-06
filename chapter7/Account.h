#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account{
public:
    void calculate(){amount += amount * interestRate;}    
    static double rate(){return interestRate;}
    static void rate(double newRate){interestRate = newRate;}
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate(){return 4.0;}
};

double Account::interestRate = initRate();
#endif