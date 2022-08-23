#include "RM_Header.hpp"
#include <iostream>

bool checkFunds(float balance,float cost)
{
    float remainingBalance = balance - cost;
    if (remainingBalance < 0)
    {
        std::cout << "Sorry, insufficient funds\n\n"
                  << "Press any key to continue";
        char input;
        std::cin >> input;
        return false;
    }

return true;
}