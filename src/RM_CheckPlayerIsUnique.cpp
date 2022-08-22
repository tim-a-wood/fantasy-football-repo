#include "RM_Header.hpp"
#include <iostream>

bool checkPlayerIsUnique(Player *players, Player player)
{
    bool playerIsUnique{true};

    for (size_t i = 0; i < 15; i++)
    {
        if (players[i].uid == player.uid)
        {
            playerIsUnique = false;
            std::cout << "You already own this player!";
        }
    }

    return playerIsUnique;
}