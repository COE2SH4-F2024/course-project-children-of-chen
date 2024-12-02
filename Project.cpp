#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"
using namespace std;

#define DELAY_CONST 100000


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

//create null pointers to the classes
GameMechs* game = NULL;
objPosArrayList* snake = NULL;
Player *myPlayer;

//declare global variables 
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

    //create new instances of the classes and 
    game = new GameMechs();
    myPlayer = new Player(game);
    game->generateFood(myPlayer->getPlayerPos());
    snake = new objPosArrayList();        
    snake->insertHead(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    //retrieves the input and sends it to game object 
   if(MacUILib_hasChar()){
    input = MacUILib_getChar();
        game->setInput(input);
   }
}

void RunLogic(void)
{
    
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    //create 2 temporate classes to make the calling shorter in length
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = game->getFoodPos();

    foodEaten = 0;//variable to check if food has been eaten

    //if it has been eaten(food coords=player coords), then a snack part is added, score increases by 1, and 1 new food generates
    if (playerPos.pos->x == foodPos.pos->x&&playerPos.pos->y == foodPos.pos->y){
        foodConsumed++;
        game->incrementScore();
        game->generateFood(playerPos);
        snake->insertHead(playerPos);
        foodEaten = 1;
    }
    //if its not eaten, then it stays the same length and updates to the new location
    if(foodEaten == 0){
        snake->insertHead(playerPos);
        snake->removeTail();
    }
    
    //this checks if the snake's head coords overlaps with any body coords, if it does, game ending condition is set
    for(int i =1;i<snake->getSize();i++){
        if((snake->getElement(0).pos->x == snake->getElement(i).pos->x)&&(snake->getElement(0).pos->y == snake->getElement(i).pos->y)){
            game->setLoseFlag();
        }
    }
    
    //set the speficied speed 
    game->setSpeed();
    
}

void DrawScreen(void)
{

    MacUILib_clearScreen();

    //create 2 temporate classes to make the calling shorter in length
    objPos playerPos = myPlayer->getPlayerPos();
    objPos foodPos = game->getFoodPos();
    int isBody =0;
      
    
    //main loop for printing everything
    for(int i=0;i<game->getBoardSizeY();i++){
        for(int j = 0;j<game->getBoardSizeX();j++){
            isBody = 0;//boolean to check if the coord is part of the snake's body
            //for loop loops through the entire snake body array and check if a piece of the body 
            //equals the current grid at [i,j]
            for(int k =0;k<snake->getSize();k++){
                if((i==snake->getElement(k).pos->y)&&(j==snake->getElement(k).pos->x)){
                    isBody = 1;
                    
                }
            }
            if(isBody){
                MacUILib_printf("%c",playerPos.getSymbol());
            }
            //check if [i,j] is border
            else if(i==0||j==0||i==game->getBoardSizeY()-1||j==game->getBoardSizeX()-1){
                MacUILib_printf("#");
            }
            //placing down food
            else if(j == foodPos.pos->x && i == foodPos.pos->y){
                MacUILib_printf("%c", foodPos.symbol);
            }
            //if its not any of the above things then it'll just print a blank space
            else{
                MacUILib_printf(" ");
            }
        }
        //new line for next row
        MacUILib_printf("\n");
    }

    //this is displayed each frame to show the score and speed level
    MacUILib_printf("\n");
    MacUILib_printf("Your score is: %d\n",game->getScore());
    MacUILib_printf("Your speed level(1-5) is: %d\n",game->getSpeedLevel());

    //if the exit flag is pressed, this will be the last thing displayed
    if(game->getExitFlagStatus()){
        MacUILib_printf("Game ended by player!\n");
        MacUILib_printf("Your final score is: %d",game->getScore());
    }
    //if the player crashes into the body, this will be the last thing displayed
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
