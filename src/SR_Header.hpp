/* 
Scheduler (SR) Header File:
All function declarations for the SR component are contained in this header file 
*/

#include <string>
#include "types.hpp"

#ifndef SR_H // include guard
#define SR_H

// Function to schedule the team creation task
Team* createTeam(Player*);

// Function to add a new player
void addPlayer(Team*,int,Player*);

// Function to swap a player
void swapPlayer(Team*,int,Player*);

#endif // SR_H