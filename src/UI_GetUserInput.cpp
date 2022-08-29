#include "UI_Header.hpp"
#include <string>

using std::cin;
using std::cout;
using std::string;

string getUserString(string prompt) {

    // Prompt user for team name
    string input;
    cout << "\n" << prompt << "\n";
    cin >> input;

    // Return input
    return input;
}

int getUserInt(string prompt) {

    // Prompt user for team name
    int input;
    cout << "\n" << prompt << "\n";
    cin >> input;

    // Return input
    return input;
}

float getUserFloat(string prompt) {

    // Prompt user for team name
    float input;
    cout << "\n" << prompt << "\n";
    cin >> input;

    // Return input
    return input;
}
