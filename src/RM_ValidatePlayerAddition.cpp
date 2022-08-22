#include "RM_Header.hpp"

bool validatePlayerAddition(Player player, Team *team)
{
    // The team should have enough remaining funds to purchase the player
    bool enoughFunds;
    enoughFunds = checkFunds(team->balance,player.value);

    // Only one instance of a player can be added
    bool playerIsUnique;
    playerIsUnique = checkPlayerIsUnique(team->players,player);

    if (enoughFunds && playerIsUnique)
        return true;
    else
        return false;
}