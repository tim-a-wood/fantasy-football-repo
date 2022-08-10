#include "SR_Header.hpp"
#include "UI_Header.hpp"
#include "RM_Header.hpp"
#include <string>

// Local function to initialize a new team
Team* initializeTeam() {

    // Create new team object
    Team *newTeam = new Team;

    // Set uid of all new players  to -1 (empty)
    for(size_t i = 0; i < 15; i++)
    {
        newTeam->players[i].uid = -1;
    }

    return newTeam;
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

    // Initialize the new team
    Team* newTeam = initializeTeam();

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