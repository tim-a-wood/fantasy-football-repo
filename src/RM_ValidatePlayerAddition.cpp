#include "RM_Header.hpp"

bool checkFunds(float balance,float cost, float sale)
{
    float remainingBalance = balance - cost + sale;
    if (remainingBalance < 0)
    {
        std::cout << "Sorry, insufficient funds\n\n"
                  << "Press any key to continue";
        char input;
        std::cin >> input;
        return false;
    }

return true;
}

bool checkPlayerIsUnique(Player *players, Player player, int userSelection)
{
    bool playerIsUnique{true};

    for (size_t i = 0; i < 15; i++)
    {
        if (players[i].uid == player.uid && player.uid != players[userSelection-1].uid)
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

bool validatePlayerAddition(Player player, Team *team, int userSelection)
{
    // The team should have enough remaining funds to purchase the player
    bool enoughFunds;
    enoughFunds = checkFunds(team->balance,player.value,team->players[userSelection-1].value);

    // Only one instance of a player can be added
    bool playerIsUnique;
    playerIsUnique = checkPlayerIsUnique(team->players,player,userSelection);

    if (enoughFunds && playerIsUnique)
        return true;
    else
        return false;
}