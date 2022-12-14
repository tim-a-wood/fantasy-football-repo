#include "SR_Header.hpp"
#include "types.hpp"
#include "UI_Header.hpp"
#include "RM_Header.hpp"
#include <iostream>

using namespace std;

Player* sortPlayers(Player* players,int sortOption,int count)
{
    // Two player structs are required to enable swapping of players in array. The index of the player to be swapped is also needed.
    Player player1;
    Player player2;
    int player2_idx;

    // We loop through the entire array and assign the players in order 
    for(size_t i = 1; i <= count; i++)
    {
        player1 = players[i];
        player2_idx = i;
        for(size_t j = i+1; j <= count; j++)
        {
            player2 = players[j];
            bool swapPlayer;
            // Sort high to low
            if (sortOption == 1)
                swapPlayer = player2.value > player1.value;
            // Sort low to high
            else
                swapPlayer = player2.value < player1.value;
            // Player with higher priority has been found so player2 becomes player1 and index is updated
            if (swapPlayer)
            {
                player1 = player2;
                player2_idx = j;
            }
        }                
        // Perform the swap
        players[player2_idx] = players[i];
        players[i] = player1;
    }   

    return players;
}

Player findPlayer(PlayerPos position, Player* playerBase, Player player, int filterOption, float filterValue, string club, int sortOption)
{
    cout << "\nSelect player to add:\n\n";
    int count = 1;
    int playerMap[573];
    bool includePlayer;
    Player *includedPlayers = new Player[573];

    // Loop through all players to create list of available players in position
    for (size_t i=0; i<573; i++)
    {   
        // Switch based on filter option to obtain T/F expression using filter criteria
        switch (filterOption)
        {
            // No filter selected
            case 0:
            {
                includePlayer = playerBase[i].position == position;
                break;
            }
            // Filter on Min Value
            case 1:
            {
                includePlayer = playerBase[i].position == position && playerBase[i].value >= filterValue;
                break;
            }
            // Filter on Max Value
            case 2:
            {
                includePlayer = playerBase[i].position == position && playerBase[i].value <= filterValue;
                break;
            }
            // Filter on Club
            case 3:
            {
                includePlayer = playerBase[i].position == position && playerBase[i].team == club;
                break;
            }
            // Catch error
            default:
            {
                cout << "Error: Invalid filter option applied";
                break;
            }
        }

        // When a player is included based on the filter criteria, we print the player information and store the index for accesing later
        if (includePlayer)
        {
            includedPlayers[count] = playerBase[i];
            count++;
        }
    }

    // Sort the players first if selected by user
    if (sortOption > 0)
        includedPlayers = sortPlayers(includedPlayers,sortOption,count);

    // Display players    
    for (size_t i = 1; i < count; i++)
    {
        cout << i << ": " << includedPlayers[i].name
             << " - " << includedPlayers[i].value
             << " - " << includedPlayers[i].team
             << "\n";
    }

    // Display the additional options for data manipulation
    cout << "\n";
    cout << count << ": Filter\n";
    cout << count+1 << ": Sort\n";
    cout << count+2 << ": BACK\n";

    bool selectionComplete{false};
    int selection;

    // The following block of code is run until a player has been selected
    while (!selectionComplete)
    {
        selection = getUserInt("Make Selection:");

        // User has selected a player, so we assign the selected player to the team using the stored index
        if (selection < count && selection > 0)
        {
            player = includedPlayers[selection];
            selectionComplete = true;
        } 
        // User has selected the filter option, so we prompt the user to enter the required filter criteria and then apply the filter
        else if (selection == count)
        {
            // Filter the players by using recursion to call findPlayers func with user specified filterOption on
            int filterSelection = getUserInt("Select Filter Option:\n1: Club\n2: Minimum Value\n3: Maximum Value\n4: BACK"); 
            switch (filterSelection)
            {
                // Filter on Club
                case 1:
                {
                    string club = getUserString("Select Club:\n\nARS AVL BOU BRE BHA CHE CRY EVE FUL LEI\nLEE LIV MCI MUN NEW NFO SOU TOT WHU WOL");
                    player = findPlayer(position,playerBase,player,3,0,club,0);
                    selectionComplete = true;
                    break;
                }
                // Filter on Min Value
                case 2:
                {
                    float minValue = getUserFloat("Enter minimum value in ?? (millions):");
                    player = findPlayer(position,playerBase,player,1,minValue,"",0);
                    selectionComplete = true;
                    break;
                }
                // Filter on Max Value
                case 3:
                {
                    float maxValue = getUserFloat("Enter maximum value in ?? (millions):");
                    player = findPlayer(position,playerBase,player,2,maxValue,"",0);
                    selectionComplete = true;
                    break;
                }
                // Catch invalid input
                default:
                {
                    cout << "\nInvalid Selection!\n";
                    player = findPlayer(position,playerBase,player,0,0,"",0);
                    selectionComplete = true;
                    break;
                }
            }
        }
        // User has selected the sort option
        else if (selection == count+1)
        {
            int sortOption = getUserInt("Select sort option:\n1: Sort by value - high to low\n2: Sort by value - low to high");
            player = findPlayer(position,playerBase,player,0,0,"",sortOption);
            selectionComplete = true;
        }
        // User has selected BACK
        else if (selection == count+2)
            selectionComplete = true;
        // User has entered an invalid selection 
        else    
            cout << "Invalid Selection\n";        
    }
    // Clear memory
    delete[] includedPlayers;
 
    return player;
}

Player getPlayer(Team *team, int userSelection, Player *playerBase)
{
    Player player;
    bool playerAdditionIsValid{false};

    while (!playerAdditionIsValid)
    {
        // Players to display depends on position selected
        if      (userSelection == 1 || userSelection == 12)
        {
            // GK selected
            player = findPlayer(PlayerPos::GK, playerBase, team->players[userSelection-1],0,0,"",0);
        }
        else if (userSelection <= 5 || userSelection == 13)
        {
            // DF selected
            player = findPlayer(PlayerPos::DF, playerBase, team->players[userSelection-1],0,0,"",0);
        }
        else if (userSelection <= 9 || userSelection == 14)
        {
            // MF selected
            player = findPlayer(PlayerPos::MF, playerBase, team->players[userSelection-1],0,0,"",0);
        }
        else if (userSelection <= 11 || userSelection == 15)
        {
            // FW selected
            player = findPlayer(PlayerPos::FW, playerBase, team->players[userSelection-1],0,0,"",0);
        }
        else
        {
            // Invalid selection
        }

    playerAdditionIsValid = validatePlayerAddition(player,team,userSelection);

    }

    return player;
}

void addPlayer(Team *team, int userSelection, Player *playerBase)
{
    // Get player selection
    Player player = getPlayer(team, userSelection, playerBase);

    // Update team value
    team->balance -= player.value;

    // Update team
    team->players[userSelection-1] = player;

    // Check if all positions have been filled
    bool emptySlot{false};
    for (size_t i=0; i < 15; i++)
    {
        if (team->players[i].uid == -1)
            emptySlot = true;
    }
    if (!emptySlot)
        team->teamComplete = true;
}

void swapPlayer(Team *team, int userSelection, Player* playerBase)
{
    // Get player selection
    Player player = getPlayer(team, userSelection, playerBase);

    // Update team value
    team->balance -= player.value;
    team->balance += team->players[userSelection-1].value;

    // Update team
    team->players[userSelection-1] = player;
}