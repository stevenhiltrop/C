//
//  bank.h
//  Bank
//
//  Created by Steven Hiltrop on 21/02/2019.
//  Copyright © 2019 Steven Hiltrop. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Bank
{
private:
    int balance;
    int modifiedBalance;
    
public:
    Bank(int b) : balance(b) {}
    
    int Balance(void);
    int Deposit(int amount);
    int Withdraw(int amount);
};

int Bank::Balance(void)
{
    return balance;
}

int Bank::Deposit(int amount)
{
    balance += amount;
    return balance;
}

int Bank::Withdraw(int amount)
{
    modifiedBalance = balance - amount;
    if (modifiedBalance < 0)
    {
        cout << "Insufficient funds" << endl;
    }
    else
    {
        balance = modifiedBalance;
    }
    return balance;
}
