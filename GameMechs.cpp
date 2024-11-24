#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
    speed = 900000;
    speedLevel = 1;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    speed = 900000;
    speedLevel = 1;
}

// do you need a destructor? - no we dont 
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

void GameMechs::setSpeed(int this_speed){
    speed = this_speed;
    switch(speed){
        case 900000:
            speedLevel = 1;
            break;
        case 650000:
            speedLevel = 2;
            break;
        case 450000:
            speedLevel = 3;
            break;
        case 300000:
            speedLevel = 4;
            break;
        case 100000:
            speedLevel = 5;
            break;
        default: 
            break;

    }
    

}

int GameMechs::getSpeed() const{
    return speed;
}

int GameMechs::getSpeedLevel() const{
    return speedLevel;
}

