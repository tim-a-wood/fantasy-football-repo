/* 
DB Interface (DB) Header File:
All function declarations for the DB Interface component are contained in this header file 
*/

#include <string>
#include "types.hpp"

#ifndef DB_H // include guard
#define DB_H

// Function to load in the player base
Player* loadPlayers();

#endif // SR_H