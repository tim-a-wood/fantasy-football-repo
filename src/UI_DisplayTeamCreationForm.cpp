#include "UI_Header.hpp"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using namespace std;

// Common function to output a line in the required format.
void printLine(std::string str, int num)
{

    // Append a single whitespace if the string length is not even
    if (str.length() % 2 != 0)
        str = str + " ";

    // Get the required parameters to manipulate the string
    int lineLength = 100 / num;
    int midPoint = lineLength / 2;
    int length = str.length();
    int start_idx; int end_idx;
    start_idx = midPoint - (length / 2);
    end_idx   = midPoint + (length / 2);

    // Print whitespace until string is to be printed, then continue to print whitespace
    for (size_t i = 0; i < lineLength; i++)
    {
        if      (i == start_idx)
            cout << str;
        else if (i < start_idx || i > end_idx)
            cout << " ";
    }
}

void displayTeamCreationForm(Team *team) {    

    // Step through line by line from GK -> DF's -> MF's -> FW's > Bench
    for (size_t i = 0; i <= 5; i++)
    {

        std::string name;
        float value;

        switch (i)
        {
            // Header
            case 0 :
            {
                printLine("=========================================================================================",1);
                cout << "\n\n";
                cout << "TEAM NAME: " << team->teamName << "\n";
                cout << "REMAINING TRANSFER FUNDS: £" << team->balance << "m"; 
                cout << "\n\n";   
                break;
            }

            // Goalkeeper
            case 1 :
            {
                printLine("=========================================================================================",1);
                cout << "\n\n";
                printLine("Team Selection:",1);
                cout << "\n\n";
                printLine("#1",1);
                cout << "\n";
                printLine(team->players[0].name,1);
                cout << "\n\n";
                break;
            }

            // Defenders
            case 2 :
            {
                printLine("#2",4);
                printLine("#3",4);
                printLine("#4",4);
                printLine("#5",4);
                cout << "\n";
                printLine(team->players[1].name,4);
                printLine(team->players[2].name,4);
                printLine(team->players[3].name,4);
                printLine(team->players[4].name,4);
                cout << "\n\n";
                break;
            }

            // Midfielders
            case 3 :
            {
                printLine("#6",4);
                printLine("#7",4);
                printLine("#8",4);
                printLine("#9",4);
                cout << "\n";
                printLine(team->players[5].name,4);
                printLine(team->players[6].name,4);
                printLine(team->players[7].name,4);
                printLine(team->players[8].name,4);
                cout << "\n\n";
                break;
            }

            // Forwards
            case 4 :
            {
                printLine("#10",2);
                printLine("#11",2);
                cout << "\n";
                printLine(team->players[9].name,2);
                printLine(team->players[10].name,2);
                cout << "\n\n";
                break;
            }

            // Bench
            case 5:
            {
                printLine("=========================================================================================",1);
                cout << "\n\n";
                printLine("Bench:",1);
                cout << "\n\n";
                printLine("#12",4);
                printLine("#13",4);
                printLine("#14",4);
                printLine("#15",4);
                cout << "\n";
                printLine(team->players[11].name,4);
                printLine(team->players[12].name,4);
                printLine(team->players[13].name,4);
                printLine(team->players[14].name,4);
                cout << "\n\n";
                printLine("=========================================================================================",1);
                cout << "\n\n";
                break;
            }
        }
    }

    // The Submit Team option is only displayed when all positions in the team have been filled
    bool emptySlot{false};
    for (size_t i = 0; i < 15; i++)
    {
        if (team->players[i].uid == -1)
            emptySlot = true;
    }
    if (emptySlot)
        cout << "#16 - Return to Main Menu\n";
    else
        cout << "#16 - Return to Main Menu\n"
             << "#17 - Submit Team\n";

}