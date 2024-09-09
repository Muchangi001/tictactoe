#include "../lib/tictactoe.h"

int main() {
    srand(time(NULL));
    displayGrid();
    selectPlayerSymbol();

    while(!isGameOver) {
        playerTurn();
        displayGrid();
        checkWinner();
        
        if (isGameOver) break; // Check for winner or draw before computer's turn

        computerTurn();
        displayGrid();
        checkWinner();
    }

    printf("Game Over! ");
    if (strcmp(gameWinner, "None") == 0) printf("It is a draw.\n"); else printf("%s wins.\n",gameWinner);
    return 0;
}