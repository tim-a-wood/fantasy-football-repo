#include "DB_Header.hpp"
#include <fstream>
#include <iostream>

bool saveTeam(Team* team)
{
    // Open file for writing
    std::ofstream fw("TeamsDatabase.txt",std::ios_base::app);

    // Check if file was successfully opened
    if (fw.is_open())
    {
        /* Store all team data to file in the following format:
        UID
        Team Name
        Balance
        Accumulated Points Total
        Player 1 UID, Player 2 UID, ... Player 15 UID
        */
        fw << team->uid << ",\n"
           << team->teamName << ",\n"
           << team->balance << ",\n"
           << team->points << ",\n";
        for (size_t i = 0; i < 15; i++)
        {
            fw << team->players[i].uid << ",";
        }
        fw << "\n\n";

        fw.close();
        std::cout << "Team has been successfully created!\n\n";
    }
    else
    {
        std::cout << "Problem connecting with Team Database";
        return false;
    }

    return true;
}
