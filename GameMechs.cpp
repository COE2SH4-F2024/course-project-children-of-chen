#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs() // default constructor
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

GameMechs::GameMechs(int boardX, int boardY) // custom constructor with user specified board size
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

// do you need a destructor? - no we dont, this class contains objpos which will use objpos class destructor
// other variables are primative so they're automatically destroyed
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
    input = this_input; // stores the scanned input in variable for future use
}

void GameMechs::clearInput()
{
    input = 0; // clearning input so that the previous input doesn't interfer with the program
}

// More methods should be added here

void GameMechs::setSpeed(){
    // switch case of 1 to 5 for different speed
    //variable speed level is only there for display
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

//Food Generation
void GameMechs::generateFood(objPos blockOff)
{
   

    seed();

    int randomx;
    int randomy;

    bool valid  = false;

    
    //We run a while loop for while the condition is false, we check if the random coordinates match with our block of positions, if not then we set our food to the random coordinates.
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

// Creating a Pseudo randomizer using the the function
void GameMechs::seed(){
    srand(time(NULL));
}



