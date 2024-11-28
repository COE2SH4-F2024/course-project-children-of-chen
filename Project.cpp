#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

#include "Player.h"
using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs* game = NULL;
char input;

int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
     
       
    } 

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs();
    myPlayer = new Player(game);
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
    input = MacUILib_getChar();
        game->setInput(input);
   }
}

void RunLogic(void)
{
    if(game->getInput() != 0)  // if not null character
    {
        switch(game->getInput())
        {                      
            case ']':  // exit
                game->setExitTrue();
                break;

            case 'w':
                
                break;
            case 's':
                
                break;
            case 'a':
                
                break;
            case 'd':
                
                break;
            case '1':
                game->setSpeed(900000);
                break;
            case '2':
                game->setSpeed(650000);
                break;
            case '3':
                game->setSpeed(450000);
                break;
            case '4':
                game->setSpeed(300000);
                break;
            case '5':
                game->setSpeed(100000);
                break;
            default:
                break;

        }
        game->clearInput();
    }
}

void DrawScreen(void)
{

    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();

    MacUILib_printf("Player[x,y] = [%d %d], %c",
                    playerPos.pos->x, playerPos.pos->y, playerPos.symbol);    

   
}

void LoopDelay(void)
{
    MacUILib_Delay(game->getSpeed()); 
}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    
    MacUILib_uninit();
    delete game;
    delete myPlayer;  
}
