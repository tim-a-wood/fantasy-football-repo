#include "DB_Header.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

// Mock function to load players. Function placeholder will just set a subset of players.

using namespace std;

Player* loadPlayers()
{
    
    Player* players = new Player[573];
    fstream newfile;
    newfile.open("rawPlayerData.txt",ios::in);
    if (newfile.is_open()){   //checking whether the file is open

      string tp;
      int count = -1;
      int index = -1;
      bool initFlag = false;

      while(getline(newfile, tp, ',')){  //read data from file object and put it into string.
        count++;
        if (count == 0)
        {
            if (initFlag == true && index < 573)
            {
                size_t pos = tp.find("\n");
                players[index].name = tp.substr(pos + 1);
                players[index].uid = index;
            }           
        }
        if (count == 1 && initFlag == true && index < 573)
        {
            players[index].team = tp;
        }
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
        if (count == 8)
        {
            count = -1;
            index++;
            initFlag = true;
        }
      }
      newfile.close();   //close the file object.
   }

    return players;

}