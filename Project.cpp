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

int foodConsumed = 0;

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
    game->generateFood(myPlayer->getPlayerPos());

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
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = game->getFoodPos();

    if (playerPos.pos->x == foodPos.pos->x&&playerPos.pos->y == foodPos.pos->y){
        foodConsumed++;
        game->incrementScore();
        game->generateFood(playerPos);
    }
   


    

    
}

void DrawScreen(void)
{

    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = game->getFoodPos();
    
    /* MacUILib_printf("Player[x,y] = [%d %d], %c",
                    playerPos.pos->x, playerPos.pos->y, playerPos.symbol); */
    MacUILib_printf("Food[x,y] = [%d %d], %c\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol);    


    for(int i=0;i<game->getBoardSizeY();i++){
        for(int j = 0;j<game->getBoardSizeX();j++){
            if(i==0||j==0||i==game->getBoardSizeY()-1||j==game->getBoardSizeX()-1){
                cout<<'#';
            }
            else if(j == playerPos.pos->x && i == playerPos.pos->y){
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if(j == foodPos.pos->x && i == foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
            }
            
            else{
                cout<<' ';
            }
        }
        cout<<endl;
    }

}

void LoopDelay(void)
{
   //MacUILib_Delay(game->getSpeed()); Will Implement back I mistakingly broke my bad king :(
    MacUILib_Delay(100000); 
}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    
    MacUILib_uninit();
    delete game;
    delete myPlayer;  
}
