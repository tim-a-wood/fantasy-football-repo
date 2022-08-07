#include "SR_Header.hpp"
#include "../UI/UI_Header.hpp"
#include "../RM/RM_Header.hpp"
#include <string>

// Local function to initialize a new team
int* initializeTeam() {

    // Create pointer to array
    int *newTeam_ptr = nullptr;

    // Create array of players. -1 means player is undefined.
    newTeam_ptr = new int[15];
    for(size_t i = 0; i < 15; i++)
    {
        newTeam_ptr[i] = -1;
    }

    return newTeam_ptr;
}

void createTeam() {

    // User must enter team name until it is valid
    bool teamNameIsValid{false};

    std::string teamName{}; // Initialize team name

    bool userSubmit{false}; // Initialize user submit request

    while (!teamNameIsValid) {

        // Prompt the user to enter a team name
        teamName = getUserInput("Enter Team Name:");

        // Validate the team name
        teamNameIsValid = validateTeamName(teamName);

        }    

    // Initialize the new team of players
    int* newTeam = initializeTeam();

    // Continue to display the team creation form until submitted
    while (!userSubmit){

        // Display the team creation form
        displayTeamCreationForm(newTeam);

        // Get user option
        std::string userSelection = getUserInput("Select Option:");

    }
    
    // Delete newTeam_ptr from the heap to free up memory
    delete[] newTeam;
}