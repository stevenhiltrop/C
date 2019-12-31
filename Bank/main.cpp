//
//  main.cpp
//  Bank
//
//  Created by Steven Hiltrop on 21/02/2019.
//  Copyright © 2019 Steven Hiltrop. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include "bank.h"

using namespace std;

// TODO:
// Check for invalid input and throw exceptions
// Check bank status not to go under 0
// Replace code with a switch statement
// Create a thread with progress bar on transaction

// Make an alternative (vulnerable buffer overflow) version with socket

// Multiple instances on name based. If name exists, continue, else new client. Create Client class
// Create clients through:
//      1. Enumeration declaration
//      2. Configuration file
//      3. Database

// Make a random password based account access for reverse engineering purpose.

int main()
{
    int action;
    int amount;
    char letter;
    bool isValidAction = false;
    bool keepGoing = true;
    
    Bank *bank = new Bank(1400);
    
    while (keepGoing)
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        
        cin >> action;
        
        if (action == 1)
        {
            cout << bank->Balance() << endl;
        }
        else
        {
            cout << "How much money?" << endl;
            cin >> amount;
            
            if (action == 2)
            {
                cout << "Deposit " << amount << " dollars" << endl;
                bank->Deposit(amount);
            }
            else if (action == 3)
            {
                cout << "Withdrew " << amount << " dollars" << endl;
                bank->Withdraw(amount);
            }
        }
        
        cout << "Would you like to make another transaction? [Y/N]" << endl;
        cin >> letter;
        
        if (toupper(letter) == 'N')
        {
            keepGoing = false;
        }
    }
    delete bank;
    return 0;
}
