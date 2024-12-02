#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
    speed = 900000;
    speedLevel = 1;


    
    food.setObjPos(-10,-10, 'o');
    //init the food object to be out of the gameboard, So when before it is set on the gameboard it does not appear on the board.
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
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
    

char GameMechs::getInput() 
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

void GameMechs::setSpeed(){
    switch(input){
        case '1':
            speedLevel = 1;
            speed = 700000;
            break;
        case '2':
            speedLevel = 2;
            speed = 500000;
            break;
        case '3':
            speedLevel = 3;
            speed = 350000;
            break;
        case '4':
            speedLevel = 4;
            speed = 220000;
            break;
        case '5':
            speedLevel = 5;
            speed = 140000;
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

// Iteration 2B

void GameMechs::generateFood(objPos blockOff)
{
   

    seed();

    int randomx;
    int randomy;

    bool valid  = false;

    

    while(!valid)
    {

        randomx = (rand() % (boardSizeX - 2)) + 1;
        randomy = (rand() % (boardSizeY - 2)) + 1;
        
        if((blockOff.pos->x != randomx)  && (blockOff.pos->y != randomy)){
            valid = true;
        }


    }

    food.setObjPos(randomx, randomy, 'o');

}
objPos GameMechs::getFoodPos() const
{
    return food;
}

void GameMechs::seed(){
    srand(time(NULL));
}



