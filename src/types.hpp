/* 
UI Header File:
All function declarations for the UI component are contained in this header file 
*/

#include <iostream>
#include <string>

#ifndef TYPES_H // include guard
#define TYPES_H

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

// Define the team structure
struct Team
{
    int uid;
    std::string teamName;
    float balance;
    Player players[15];
    int points;
};

#endif // UI_H


