/* 
Rule Monitor (RM) Header File:
All function declarations for the RM component are contained in this header file 
*/

#include <iostream>
#include <string>
#include "types.hpp"

#ifndef RM_H // include guard
#define RM_H

// Function to validate the team name entered by the user in accordance with the game rules. Returns a Boolean.
bool validateTeamName(std::string);

// Rule monitor is responsible for checking the addition of a player does not violate rules (e.g. exceeds balance)
bool validatePlayerAddition(Player,Team*);

// Check if player purchase exceeds remaining funds
bool checkFunds(float,float);

// Check if player does not already exist in team
bool checkPlayerIsUnique(Player*,Player);

#endif // SR_H