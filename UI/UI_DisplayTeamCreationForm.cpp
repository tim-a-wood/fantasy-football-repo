#include "UI_Header.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

void displayTeamCreationForm(int *team) {    

    cout << "\n";

    // Loop through all players in the team and display the current selection
    for(size_t i = 0; i < 15; i++) 
    {

        // If player integer is -1 then the player position is empty
        if ( team[i] == -1 ) 
        {
            cout << i + 1 << ": SELECT PLAYER\n";
        }
        else
        {
            // TODO - Else logic
        }
    }    

}