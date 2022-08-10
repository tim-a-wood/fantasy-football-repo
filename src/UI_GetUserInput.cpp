#include "UI_Header.hpp"
#include <string>

using std::cin;
using std::cout;
using std::string;

string getUserInput(string prompt) {

    // Prompt user for team name
    string input{};
    cout << "\n" << prompt << "\n";
    cin >> input;

    // Return input
    return input;
}
