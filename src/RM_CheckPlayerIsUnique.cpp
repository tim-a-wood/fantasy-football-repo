#include "RM_Header.hpp"
#include <iostream>

bool checkPlayerIsUnique(Player *players, Player player)
{
    bool playerIsUnique{true};

    for (size_t i = 0; i < 15; i++)
    {
        if (players[i].uid == player.uid && player.uid != -1)
        {
            playerIsUnique = false;
            std::cout << "You already own this player!\n\n"
                      << "Press any key to continue";
            char input;
            std::cin >> input;

        }
    }

    return playerIsUnique;
}