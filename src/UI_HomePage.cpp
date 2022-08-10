#include "UI_Header.hpp" // UI Header File
#include <iostream>      // I/O Stream

// Namespaces
using std::cin;
using std::cout;

int displayHomePage(const int quit,const int teamCreation) {

    int userSelection{0}; // Initialize variable

    // Display the available user selectable options
    cout << "Select Option:\n"
         << teamCreation << ". Create Team\n"
         << quit << ". Quit\n";
    
    // The system must continue to accept an input until a valid input is provided
    bool inputIsValid{false};
    while (!inputIsValid) {

        // Receive the user selection
        cin >> userSelection;

        // Validate the user selection
        if (userSelection != teamCreation && userSelection != quit) {
            cin.clear(); 
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid Selection\n";
        }
        else 
            inputIsValid = true;

    } // while  

    return userSelection; // Return user selection

} // displayHomePage