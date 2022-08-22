#include "RM_Header.hpp"
#include <iostream>

bool checkFunds(float balance,float cost)
{
    float remainingBalance = balance - cost;
    if (remainingBalance < 0)
    {
        std::cout << "Sorry, insufficient funds";
        return false;
    }

return true;
}