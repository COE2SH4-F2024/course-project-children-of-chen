#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = ' ';
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = ' ';
    exitFlag = 0;
    loseFlag = 0;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor? - no we dont 
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{

}

bool GameMechs::getLoseFlagStatus() const
{

}
    

char GameMechs::getInput() const
{

}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{

}

int GameMechs::getBoardSizeY() const
{

}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here