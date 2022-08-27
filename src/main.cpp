#include <iostream>         // I/O Stream
#include "UI_Header.hpp" // UI Header
#include "SR_Header.hpp" // Scheduler Header
#include "RM_Header.hpp"
#include "DB_Header.hpp"
#include "types.hpp"

int main(){

    // Define the program mode options
    static const int quit           = -1;
    static const int teamCreation   = 1;
    static const int teamManagement = 2;

    // Load the player base TODO - move this to a startup function
    Player* players = loadPlayers();
    Team* team;

    // runProgram will terminate the program if it goes to false
    bool runProgram{true};

    // programMode defines the current mode of the program. This will be modified through user selection.
    int programMode{0};

    while (runProgram) {


       // The program will switch through different modes as defined by programMode
       switch (programMode) {

            // Startup Mode
            case 0 : 
                programMode = displayHomePage(quit,teamCreation); // Return the programMode
                break;

            // Team Creation Mode
            case 1 :
                // Schedule Team Creation
                team = createTeam(players); 
                // When team has been created successfully, switch to the Team Management screen
                if (team->teamComplete)
                    programMode = 2;
                break;

            // Team Management Mode
            case 2 :
                std::cout << "case 2";
                break;

            // Quit Program
            default :
                runProgram = false;
                break;

       } // switch

    } // while

    // Clear memory
    delete[] players;
    delete[] team;

    return 0;
}