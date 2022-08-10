#include "DB_Header.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

// Mock function to load players. Function placeholder will just set a subset of players.

using namespace std;

Player* loadPlayers()
{
    // Create new players vector on the heap
    Player* players = new Player[573];

    // Create in put file stream
    fstream newfile;
    newfile.open("rawPlayerData.txt",ios::in);

    // Check whether the file is open
    if (newfile.is_open()){   
    
        // Each line will be read in as a string
        string tp;

        // count and index are used to identify which line and substring is active
        int count = -1;
        int index = -1;
        bool initFlag = false;

        // We will continue to loop through the file until all lines are parsed
        while(getline(newfile, tp, ',')){
            // Increment count
            count++;

            // Set the player name, uid and points when count is 0
            if (count == 0)
            {
                if (initFlag == true && index < 573)
                {
                    size_t pos = tp.find("\n");
                    players[index].name = tp.substr(pos + 1);
                    players[index].uid = index;
                    players[index].points = 0;
                }           
            }

            // Set the players team when the count is 1
            if (count == 1 && initFlag == true && index < 573)
            {
                players[index].team = tp;
            }

            // Set the players position when the count is 2
            if (count == 2 && initFlag == true && index < 573)
            {
                if      (tp == "GKP")
                    players[index].position = GK;
                else if (tp == "DEF")
                    players[index].position = DF;
                else if (tp == "MID")
                    players[index].position = MF;
                else if (tp == "FWD")
                    players[index].position = FW;  
            }

            // Set the players value when the count is 3
            if (count == 3 && initFlag == true && index < 573)
            {
                string::size_type sz;
                players[index].value = stof(tp,&sz);
            }

            // Increment the index at the end of the line when the count is 8
            if (count == 8)
            {
                count = -1;
                index++;
                initFlag = true;
            }
        }

        // Close the file object
        newfile.close();   
    }

    return players;

}