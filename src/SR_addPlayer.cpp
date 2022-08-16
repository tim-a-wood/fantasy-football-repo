#include "SR_Header.hpp"
#include "types.hpp"
#include "UI_Header.hpp"
#include <iostream>

using namespace std;

Player findPlayer(PlayerPos position, Player* playerBase)
{
    Player player;
    cout << "Select player to add:\n";
    int count = 1;
    int playerMap[573];

    // Loop through all players to create list of available players in position
    for (size_t i=0; i<573; i++)
    {  
        if (playerBase[i].position == position)
        {
            cout << count << ": " << playerBase[i].name 
                 << " - " << playerBase[i].value
                 << " - " << playerBase[i].team
                 << "\n";
            playerMap[count] = i;
            count++;
        }
    }

    // Get player selection
    int selection = getUserInt("Make Selection:");

    // Assign player to selected player
    int index = playerMap[selection];
    player = playerBase[index];   

    return player;
}

void addPlayer(Team *team, int userSelection, Player *playerBase)
{
    Player player;
    // Players to display depends on position selected
    if      (userSelection == 1 || userSelection == 12)
    {
        // GK selected
        player = findPlayer(PlayerPos::GK, playerBase);
    }
    else if (userSelection <= 5 || userSelection == 13)
    {
        // DF selected
        player = findPlayer(PlayerPos::DF, playerBase);
    }
    else if (userSelection <= 9 || userSelection == 14)
    {
        // MF selected
        player = findPlayer(PlayerPos::MF, playerBase);
    }
    else if (userSelection <= 11 || userSelection == 15)
    {
        // FW selected
        player = findPlayer(PlayerPos::FW, playerBase);
    }
    else
    {
        // Invalid selection
    }
    team->players[userSelection-1] = player;
}