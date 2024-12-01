#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2; // Players starting Positon is placed in the middle of the Board
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '*';
}


Player::~Player()
{
    //No need for anything During Iteration 1A
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        char input = mainGameMechsRef->getInput();
        if (input != 0)
        {
            switch(input)
            {
                case 27:
                    mainGameMechsRef->setExitTrue();
                break;


                case 'w':
                if(myDir != UP && myDir != DOWN)
                    myDir = UP;
                break;

                case 's':
                if(myDir != UP && myDir != DOWN)
                    myDir = DOWN;
                break;

                case 'a':
                if(myDir != RIGHT && myDir != LEFT)
                    myDir = LEFT;
                break;

                case 'd':
                if(myDir != RIGHT && myDir != LEFT)
                    myDir = RIGHT;
                break;

                case '1':
                


                default:
                    break;
            }
        }        
}


void Player::movePlayer()
{
    
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case UP:
            playerPos.pos->y--;
            if(playerPos.pos->y <= 0)
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
            break;

        case DOWN:
            playerPos.pos->y++;
            if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY()-1)
                playerPos.pos->y = 1;//Wrap to the top of Boundry
            break;

        case LEFT:
            playerPos.pos->x--;
            if(playerPos.pos->x <=0)
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
            break;

        case RIGHT:
            playerPos.pos->x++;
            if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX()-1)
                playerPos.pos->x = 1;
            break;

        default:
            break;




    }

}

// More methods to be added