#include "UI_Header.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

void displayTeamCreationForm(Team *team) {    

    cout << "\n";

    // Loop through all players in the team and display the current selection
    for(size_t i = 0; i < 15; i++) 
    {

        // If player integer is -1 then the player position is empty
        if ( team->players[i].uid == -1 ) 
        {
            cout << i + 1 << ": SELECT PLAYER ";
            if      (i == 0 || i == 11)
                cout << "(GK)\n";
            else if (i <= 4 || i == 12)
                cout << "(DF)\n";
            else if (i <= 8 || i == 13)
                cout << "(MF)\n";
            else
                cout << "(FW)\n";
        }
        else
        {
            // Get and display the player name and position
            cout << i + 1 << ": "
                 << team->players[i].name
                 << " ("
                 << team->players[i].position
                 << ")\n";
        }
    }
    cout << "16: Quit\n";

}