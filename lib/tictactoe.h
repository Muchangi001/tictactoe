#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern char gameGrid[3][3];
extern unsigned playerCount;
extern char gameSymbols[2];
extern char playerSymbol;
extern char computerSymbol;
extern char playerInput[2];
extern unsigned char position[2];
extern char *gameWinner;
extern bool isGameOver;

void displayTempGrid();
void displayGrid();

// Player functions
void selectPlayerSymbol();
void playerTurn();
void selectPlayerPosition();

// Computer functions
void computerTurn();
void mapComputerInput(unsigned char input);
void checkWinner();

#endif