#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
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
objPosArrayList* snake = NULL;
char input;

int foodConsumed = 0,foodEaten;

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
    snake = new objPosArrayList();        
    snake->insertHead(myPlayer->getPlayerPos());

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
    foodEaten = 0;
    if (playerPos.pos->x == foodPos.pos->x&&playerPos.pos->y == foodPos.pos->y){
        foodConsumed++;
        game->incrementScore();
        game->generateFood(playerPos);
        snake->insertHead(playerPos);
        foodEaten = 1;
    }

    if(foodEaten == 0){
        snake->insertHead(playerPos);
        snake->removeTail();
    }
    
    for(int i =1;i<snake->getSize();i++){
        if((snake->getElement(0).pos->x == snake->getElement(i).pos->x)&&(snake->getElement(0).pos->y == snake->getElement(i).pos->y)){
            game->setLoseFlag();
        }
    }
    
    game->setSpeed();
    
}

void DrawScreen(void)
{

    MacUILib_clearScreen();

    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = game->getFoodPos();
    int isBody =0;
      
    

    for(int i=0;i<game->getBoardSizeY();i++){
        for(int j = 0;j<game->getBoardSizeX();j++){
            isBody = 0;
            for(int k =0;k<snake->getSize();k++){
                if((i==snake->getElement(k).pos->y)&&(j==snake->getElement(k).pos->x)){
                    isBody = 1;
                    
                }
            }
            if(isBody){
                MacUILib_printf("%c",playerPos.getSymbol());
            }
            else if(i==0||j==0||i==game->getBoardSizeY()-1||j==game->getBoardSizeX()-1){
                MacUILib_printf("#");
            }
            else if(j == foodPos.pos->x && i == foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("\n");
    MacUILib_printf("Your score is: %d\n",game->getScore());
    MacUILib_printf("Your speed level(1-5) is: %d\n",game->getSpeedLevel());

    if(game->getExitFlagStatus()){
        MacUILib_printf("Game ended by player!\n");
        MacUILib_printf("Your final score is: %d",game->getScore());
    }
    if(game->getLoseFlagStatus()){
        game->setExitTrue();
        MacUILib_printf("!!GAME OVER!! \nYou hit the snake's body\n");
        MacUILib_printf("Your final score is: %d",game->getScore());
    }
}

void LoopDelay(void)
{
   MacUILib_Delay(game->getSpeed()); 

}


void CleanUp(void)
{
    //MacUILib_clearScreen();  
    
    MacUILib_uninit();
    delete game;
    delete myPlayer; 
}
