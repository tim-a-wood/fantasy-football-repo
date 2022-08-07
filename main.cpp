#include <iostream>         // I/O Stream
#include "UI/UI_Header.hpp" // UI Header
#include "SR/SR_Header.hpp" // Scheduler Header
#include "RM/RM_Header.hpp"

int main(){

    // Define the program mode options
    static const int quit           = -1;
    static const int teamCreation   = 1;
    static const int teamManagement = 2;

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
                createTeam(); 
                // Transition to Team Management Mode upon completion of Team Creation
                programMode = teamManagement; 
                break;

            // Team Management Mode
            case 2 :
                std::cout << "case 2";
                break;

            // Quit Program
            default :
                std::cout << "default";
                break;

       } // switch

    } // while

    return 0;
}