/* 
DB Interface (DB) Header File:
All function declarations for the DB Interface component are contained in this header file 
*/

#include <string>

#ifndef DB_H // include guard
#define DB_H

// Define player position enumeration
enum PlayerPos {GK, DF, MF, FW};

// Define the player structure
struct Player 
{
    int uid;
    std::string name;
    std::string team;
    float value;
    int points;
    PlayerPos position;
};

// Function to load in the player base
Player* loadPlayers();

#endif // SR_H