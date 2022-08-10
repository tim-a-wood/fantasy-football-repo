/* 
Scheduler (SR) Header File:
All function declarations for the SR component are contained in this header file 
*/

#include <string>
#include "types.hpp"

#ifndef SR_H // include guard
#define SR_H

// Function to schedule the team creation task
int createTeam();

// Function to add a new player
void addPlayer(Team*,int);

// Function to swap a player
void swapPlayer(Team*,int);

#endif // SR_H