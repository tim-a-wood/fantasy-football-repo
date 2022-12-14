#include "SR_Header.hpp"
#include "UI_Header.hpp"
#include "RM_Header.hpp"
#include "DB_Header.hpp"
#include <string>

// Local function to initialize a new team
Team* initializeTeam(std::string teamName) {

    // Create new team object
    Team *newTeam = new Team;
    newTeam->teamName = teamName;
    newTeam->teamComplete = false;

    // Starting balance is £100m
    newTeam->balance = 100;

    // Starting points are zero
    newTeam->points = 0;

    // Set uid of all new players  to -1 (empty)
    for(size_t i = 0; i < 15; i++)
    {
        newTeam->players[i].uid = -1;
        newTeam->players[i].name = "ADD PLAYER";
        newTeam->players[i].value = 0;
    }

    return newTeam;
}

Team* createTeam(Player *playerBase) {

    // User must enter team name until it is valid
    bool teamNameIsValid{false};

    std::string teamName; // Initialize team name

    bool userSubmit{false}; // Initialize user submit request

    while (!teamNameIsValid) {

        // Prompt the user to enter a team name
        teamName = getUserString("Enter Team Name:");

        // Validate the team name
        teamNameIsValid = validateTeamName(teamName);
        }    

    // Initialize the new team
    Team* newTeam = initializeTeam(teamName);

    // Continue to display the team creation form until submitted
    while (!userSubmit){

        // Display the team creation form
        displayTeamCreationForm(newTeam);

        // Get user option
        int userSelection = getUserInt("Select Option:");

        // Next action depends on user selection. Switch between adding a player, swapping a player, submitting team or quitting
        if      (userSelection == 16)
            return 0;

        else if (userSelection == 17)
        {
            userSubmit = true;
            // Write the new team to database. If writing fails then reset the teamComplete flag to false.
            bool teamSaved = saveTeam(newTeam);
            if (!teamSaved)
                newTeam->teamComplete = false;
        }

        else if (userSelection <= 15 && userSelection > 0)

            // If valid player is selected then check if player needs to be added or swapped
            if (newTeam->players[userSelection-1].uid == -1)
                // Add player
                addPlayer(newTeam,userSelection,playerBase);
            else
                // Swap player
                swapPlayer(newTeam,userSelection,playerBase);             
    }

    

    return newTeam;
}