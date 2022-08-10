/* 
Rule Monitor (RM) Header File:
All function declarations for the RM component are contained in this header file 
*/

#include <iostream>
#include <string>

#ifndef RM_H // include guard
#define RM_H

// Function to validate the team name entered by the user in accordance with the game rules. Returns a Boolean.
bool validateTeamName(std::string);

#endif // SR_H