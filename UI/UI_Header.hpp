/* 
UI Header File:
All function declarations for the UI component are contained in this header file 
*/

#include <iostream>
#include <string>

#ifndef UI_H // include guard
#define UI_H

// Function to display the home page. The return value will activate the application moding.
int displayHomePage(const int,const int);

// Function to prompt and receive a user input. The return value is a string
std::string getUserInput(std::string);

// Function to display the team creation form
void displayTeamCreationForm(int *);

#endif // UI_H


