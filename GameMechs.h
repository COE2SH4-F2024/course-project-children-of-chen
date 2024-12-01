#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        int speed;
        int speedLevel;
        objPos food;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        //not needed, the objpos object has its own destructor, other data types are all premative and will delete by default
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();

        
        
        // More methods should be added here
        void setSpeed(int s);
        int getSpeed() const;
        int getSpeedLevel() const;

        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
        void seed();
};

#endif